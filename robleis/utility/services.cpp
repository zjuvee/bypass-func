
/*
    Free to use, coded by juve <3
*/

#include <utility/services.h>

// lista de servicios, ya estan la mayoria 
std::vector<std::string> serviceslist = {
        "eventlog",
        "dnscache",
        "diagtrack",
        "bam",
        "pcasvc",
        "dps",
        "vmicvss",
        "VSS",
        "SSDPSRV",
        "cdpusersvc",
        "CDPSvc"
};

// stopear un servicio
bool services::stopservice(const std::string& serviceName) {
    SC_HANDLE schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (schSCManager == NULL) {
        return false;
    }

    SC_HANDLE schService = OpenService(schSCManager, serviceName.c_str(), SERVICE_STOP | SERVICE_QUERY_STATUS);
    if (schService == NULL) {
        CloseServiceHandle(schSCManager);
        return false;
    }

    SERVICE_STATUS_PROCESS ssp;
    DWORD bytesNeeded;
    if (!QueryServiceStatusEx(schService, SC_STATUS_PROCESS_INFO, (LPBYTE)&ssp, sizeof(SERVICE_STATUS_PROCESS), &bytesNeeded)) {
        CloseServiceHandle(schService);
        CloseServiceHandle(schSCManager);
        return false;
    }

    SERVICE_STATUS status;
    if (ControlService(schService, SERVICE_CONTROL_STOP, &status)) {
        std::cout << "stopping service: " << serviceName << "..." << std::endl;
        Sleep(100);
        while (QueryServiceStatus(schService, &status)) {
            if (status.dwCurrentState == SERVICE_STOP_PENDING) {
                Sleep(100);
            }
            else if (status.dwCurrentState == SERVICE_STOPPED) {
                std::cout << "service " << serviceName << " stopped." << std::endl;
                break;
            }
        }
    }
    else {
        std::cerr << "service: " << serviceName << " could not be stopped, error: " << GetLastError() << std::endl;
        CloseServiceHandle(schService);
        CloseServiceHandle(schSCManager);
        return false;
    }

    CloseServiceHandle(schService);
    CloseServiceHandle(schSCManager);
    return true;
}

// startear un servicio
bool services::startservice(const std::string& serviceName) {
    SC_HANDLE schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (schSCManager == NULL) {
        return false;
    }

    SC_HANDLE schService = OpenService(schSCManager, serviceName.c_str(), SERVICE_START | SERVICE_QUERY_STATUS);
    if (schService == NULL) {
        CloseServiceHandle(schSCManager);
        return false;
    }

    if (!::StartService(schService, 0, NULL)) {
        CloseServiceHandle(schService);
        CloseServiceHandle(schSCManager);
        return false;
    }

    std::cout << "starting service: " << serviceName << "..." << std::endl;

    SERVICE_STATUS status;
    while (QueryServiceStatus(schService, &status)) {
        if (status.dwCurrentState == SERVICE_START_PENDING) {
            Sleep(100);
        }
        else if (status.dwCurrentState == SERVICE_RUNNING) {
            std::cout << "service " << serviceName << " started." << std::endl;
            break;
        }
    }

    CloseServiceHandle(schService);
    CloseServiceHandle(schSCManager);
    return true;
}

// bucle para prender todos los servicios
void services::start() {
    for (const std::string& serviceName : serviceslist) {
        startservice(serviceName);
    }
}

// bucle para detener todos los servicios
void services::stop() {
    for (const std::string& serviceName : serviceslist) {
        stopservice(serviceName);
    }
}