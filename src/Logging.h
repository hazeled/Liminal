#pragma once

/* Header only logging for liminal */

#include <cstdio>

namespace Liminal
{
    class Log
    {
    public:
        Log(const char* name) :
            name(name)
        {

        }

        template <typename Message, typename... Args>
        void Print(const Message &message, Args&&... args)
        {
            #ifdef BUILD_LOGGING
            char msg[100]; // Buffer for formatted message
            snprintf(&msg[0], sizeof(msg), message, args...);
            printf("[%s] ", name);
            printf("%s\n", msg);
            #endif
        }

        /* Like print but prints with a special tag at the
         * beggining, which is useful for grepping/sorting output */
        template <typename Message, typename... Args>
        void Debug(const Message &message, Args&&... args)
        {
            printf("<DEBUG> ");
            Print(message, args...);
        }
        template <typename Message, typename... Args>
        void Error(const Message &message, Args&&... args)
        {
            printf("<ERROR> ");
            Print(message, args...);
        }

    private:
        const char* name;
    };
}
