
/*
    Free to use, coded by juve <3
*/

#include <utility/console.h>

// hay otras formas mas faciles de ejecutar comandos pero esta es la que use siempre y bueno
void console::command(const char* command)
{
    std::string cmd = (xorstr_("/C "));
    cmd += command;

    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    if (CreateProcess(
        (xorstr_("C:\\Windows\\System32\\cmd.exe")),   // cmd path
        const_cast<LPSTR>(cmd.c_str()),                // execute command
        NULL,                                          
        NULL,                                          
        FALSE,                                         
        0,                                             
        NULL,                                          
        NULL,                                          // initial dir
        &si,                                           // start info
        &pi))                                          // process info
    {

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}