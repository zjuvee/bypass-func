
/*
    Free to use, coded by juve <3
*/

#include <utility/regedit.h>

// todos los rootkeys para probar 
HKEY rootKeys[] = {
    HKEY_CLASSES_ROOT,
    HKEY_CURRENT_USER,
    HKEY_LOCAL_MACHINE,
    HKEY_USERS,
    HKEY_CURRENT_CONFIG
};

// borrar los values y subkeys usando la funcion recursivamente :v
bool regedit::clearkey(HKEY hKeyRoot, const std::string& subKey) {
    HKEY hKey;
    LONG result = RegOpenKeyEx(hKeyRoot, subKey.c_str(), 0, KEY_READ | KEY_SET_VALUE | KEY_ENUMERATE_SUB_KEYS | DELETE, &hKey);

    if (result != ERROR_SUCCESS) {
        return false; 
    }

    DWORD valueNameSize;
    char valueName[255];
    while (RegEnumValue(hKey, 0, valueName, &(valueNameSize = sizeof(valueName)), nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
        RegDeleteValue(hKey, valueName);
    }

    DWORD subKeyNameSize;
    char subKeyName[255];
    while (RegEnumKeyEx(hKey, 0, subKeyName, &(subKeyNameSize = sizeof(subKeyName)), nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
        std::string fullSubKeyPath = subKey + "\\" + subKeyName;
        clearkey(hKeyRoot, fullSubKeyPath);
    }

    RegCloseKey(hKey);

    return true;
}

// bucle para probar todos los rootkey y encontrar la clave para despues borrarla
bool regedit::regdelete(const std::string& subKey) {
    for (HKEY rootKey : rootKeys) {
        if (clearkey(rootKey, subKey)) {
            return true;
        }
    }

    return false;
}
