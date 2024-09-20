
/*
    Free to use, coded by juve <3
*/

#include <utility/misc.h>

// da el path del usuario usando las enviorementvariables, asi lo da: C:\Users\Administrator
string misc::getuserpath()
{
	char userProfile[MAX_PATH];
	DWORD result = GetEnvironmentVariable("USERPROFILE", userProfile, MAX_PATH);
	return userProfile;
}

// obtener nombre de usuario, se puede usar para despeus obtener el SID y algunas pelotudeces mas
string misc::getuser() {
    char username[256];
    DWORD username_len = sizeof(username);

    if (GetUserNameA(username, &username_len)) {
        return string(username);
    }
}

// borrar archivos por patron usando regex, generalmente solamente se usa para prefetch
void patterndelete(const string& directory, const vector<string>& patterns) {
    try {
        for (const auto& entry : directory_iterator(directory)) {
            string filename = entry.path().filename().string();

            for (const string& pattern : patterns) {
                string regexPattern = "^" + regex_replace(pattern, regex("\\*"), ".*") + "$";
                regex regex(regexPattern);

                if (regex_match(filename, regex)) {
                    remove(entry.path());
                }
            }
        }
    }
    catch (const exception& e) {
    }
}

// cleanear el prefetch, añadir mas patrones de .pf si se necesita
void misc::cleanprefetch()
{
    string path = "C:\\Windows\\Prefetch";
    vector<string> patterns = { "BFSVC*", "CMD*", "CONHOST*", "FILTERKEYSSETTER*", "FSUTIL*", "MSBUILD*", "NETSH*", "ResPriHMStaticDb*", "SC*", "SVCHOST*", "VBCSCOMPILER*", "VSSVC*", "WMIPRVSE*", "IPCONFIG*", "DLLHOST*", "RUNDLL32*", "SVCHOST*", "VSSVC*", "FILT𝖾RKEYSSETT𝖾R*", "FILTERK𝖾YSSETT𝖾R*", "FILT𝖾RKEYSSETT𝖾R*", "REGINI*", "IPCONFIG*", "DURATIONCONTROLMEDIUM*", "TASKKILL*", "FSUTIL*", "CMD*", "CONHOST*", "TASKHOSTW*", "TELEGRAM*", "SPPSVC*" };
    patterndelete(path, patterns);
}

// modificar la fecha de ultima modificacion por 6 horas menos a la actual
void misc::modificationDate(const string& folderPath) {
    try {
        if (exists(folderPath) && is_directory(folderPath)) {
            auto now = chrono::system_clock::now();
            auto fileTime = file_time_type::clock::now() - chrono::hours(6);

            last_write_time(folderPath, fileTime);
        }
    }
    catch (const exception& e) {
    }
}