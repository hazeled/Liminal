#include "../Shader.h"

#include "../pch.h"
#include "../Logging.h"

#include <iostream>

static Liminal::Log log = Liminal::Log("Shader");


namespace Liminal
{
    Shader::Shader(const char* source, int type)
    {
        shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, NULL);
        glCompileShader(shader);
        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        //log.Debug("%s", source);
        if (success != GL_TRUE)
        {
            // shader compilation failed
            int maxLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);
            glDeleteShader(shader);
            log.Error("Error compiling shader! Error:");
            for (auto& letter : errorLog)
            {
                std::cout << letter;
            }
            return;
        }
    }

    Shader::~Shader()
    {
        glDeleteShader(shader);
    }

    Program::Program(const char* vertSource, const char* fragSource)
    {
        program = glCreateProgram();
        vert = new Shader(vertSource, GL_VERTEX_SHADER);
        frag = new Shader(fragSource, GL_FRAGMENT_SHADER);
        glAttachShader(program, vert->shader);
        glAttachShader(program, frag->shader);
        glLinkProgram(program);
        int success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (success != GL_TRUE)
        {
            // program compilation failed
            int maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
            std::vector<GLchar> errorLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &errorLog[0]);
            glDeleteProgram(program);
            log.Error("Error linking program! Error:");
            for (auto& letter : errorLog)
            {
                std::cout << letter;
            }
            return;
        }
    }

    Program::~Program()
    {
        delete vert;
        delete frag;
        glDeleteProgram(program);
    }

    void Program::Use()
    {
        glUseProgram(program);
    }
}
