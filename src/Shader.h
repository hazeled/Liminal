#pragma once

namespace Liminal
{
    class Shader
    {
    public:
        Shader(const char* source, int type);
        virtual ~Shader();
        unsigned int shader;
    };

    class Program
    {
    public:
        Program(const char* vertSource, const char* fragSource);
        virtual ~Program();
        void Use();
        unsigned int program;
    private:
        Shader* frag;
        Shader* vert;
    };
}
