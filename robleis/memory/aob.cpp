#include <memory/aob.h>

/*
    Free to use, coded by juve <3
    The commented lines are to replace the pattern found with another pattern
    Uses: This can be used to scan strings or replace strings in a process memory
*/

// traducilo de texto a hex con https://es.rakko.tools/tools/77/ o usa memory view de cheatengine o tambien systeminformer que se yo lo que quieras
std::vector<std::pair<std::string, std::string>> patterns = {
    {(xorstr_("6B 65 79 61 75 74 68 2E 77 69 6E 30 59 30")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // keyauth.win0Y0 -> swaggerboy
    {(xorstr_("61 70 69 2D 77 6F 72 6B 65 72 2E 6B 65 79 61 75 74 68 2E 77 69 6E")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // api-worker.keyauth.win -> swaggerboy
    {(xorstr_("6B 65 79 61 75 74 68 2E 77 69 6E 30")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))},// keyauth.win0 -> swaggerboy
    {(xorstr_("61 00 70 00 69 00 2D 00 77 00 6F 00 72 00 6B 00 65 00 72 00 2E 00 6B 00 65 00 79 00 61 00 75 00 74 00 68 00 2E 00 77 00 69 00 6E")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))},// api-worker.keyauth.win (UTF-16) -> swaggerboy
    {(xorstr_("6B 65 79 61 75 74 68 2E 77 69 6E")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // keyauth.win -> swaggerboy
    {(xorstr_("6B 00 65 00 79 00 61 00 75 00 74 00 68 00 2E 00 77 00 69 00 6E")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // keyauth.win (UTF-16) -> swaggerboy
    {(xorstr_("63 00 64 00 6e 00 2e 00 67 00 6f 00 73 00 74 00 68 00 2e 00 6c 00 74 00 64 ")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // cdn.gosth.ltd (UTF-16) -> swaggerboy
    {(xorstr_("67 6F 73 74 68 2E 6C 74 64 30 59 30")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // gosth.ltd0Y0 -> swaggerboy
    {(xorstr_("67 6F 73 74 68 2E 6C 74 64")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // gosth.ltd -> swaggerboy
    {(xorstr_("67 6F 73 74 68 2E 6C 74 64 30")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // gosth.ltd0 -> swaggerboy
    {(xorstr_("2A 2E 67 6F 73 74 68 2E 6C 74 64 30")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // *.gosth.ltd0 -> swaggerboy
    {(xorstr_("75 74 68 2e 77 69 6e")), (xorstr_("61"))}, // auth.win -> A
    {(xorstr_("21 30 21")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))}, // !0! -> swaggerboy
    {(xorstr_("67 00 6F 00 73 00 74 00 68 00 2E 00 6C 00 74 00 64")), (xorstr_("73 77 61 67 67 65 72 62 6F 79"))} // gosth.ltd (UTF-16) -> swaggerboy
};

// literalmente al pedo, lo hice con chat gpt para que me imprima los strings que reemplaza
std::string hex_to_string(const std::string& hex) {
    std::string result;

    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byte = hex.substr(i, 2); 
        char chr = static_cast<char>(strtol(byte.c_str(), nullptr, 16)); 
        result.push_back(chr);
    }

    return result;
}

// reemplazar strings de un proceso usando la lista de arriba, eliminar los cout, los tenia para debugear y que este todo bien
int aobscan::stringprocess(const char* process)
{
    c_fn_memory memory;
    const char* processName = process;


    if (memory.attack_process(processName)) {
        for (const auto& [findPattern, replacePattern] : patterns) {
            std::string findPatternReadable = hex_to_string(findPattern);
            std::string replacePatternReadable = hex_to_string(replacePattern);

            // search the addresses
            std::vector<LPVOID> foundAddresses = memory.find_byte(findPattern);
            if (!foundAddresses.empty()) {
                // reeplace the strings
                BOOL replaceSuccess = memory.replace_byte(findPattern, replacePattern);
                if (replaceSuccess) {
                    std::cout << "[+] string replaced successfully, process: " << processName
                        << " | string: " << findPatternReadable
                        << " | new string: " << replacePatternReadable << std::endl;
                }
                else {
                    std::cout << "[-] error replacing string in process: " << processName << std::endl;
                }
            }
        }
    }
    return 0;
}

// reemplazar strings de un servicio usando la lista de arriba, eliminar los cout, los tenia para debugear y que este todo bien
int aobscan::stringservice(const char* process)
{
    c_fn_memory memory;
    const char* processName = process;

    if (memory.attack_service(processName)) {
        for (const auto& [findPattern, replacePattern] : patterns) {
            std::string findPatternReadable = hex_to_string(findPattern);
            std::string replacePatternReadable = hex_to_string(replacePattern);

            // search the addresses
            std::vector<LPVOID> foundAddresses = memory.find_byte(findPattern);
            if (!foundAddresses.empty()) {
                // reeplace the strings
                BOOL replaceSuccess = memory.replace_byte(findPattern, replacePattern);
                if (replaceSuccess) {
                    std::cout << "[+] string replaced successfully, process: " << process
                        << " | string: " << findPatternReadable
                        << " | new string: " << replacePatternReadable << std::endl;
                }
                else {
                    std::cout << "[-] error replacing string in service: " << process << std::endl;
                }
            }
        }
    }
    return 0;
}

