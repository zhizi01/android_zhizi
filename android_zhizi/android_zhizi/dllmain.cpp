#include "pch.h"
#include <windows.h>
#include <string>
#include <iostream>

std::string global_output;

const char* executeCommand(const std::string& adbPath, const std::string& cmdSuffix) {
    char buffer[128];
    global_output = "";
    std::string fullCmd = adbPath + " " + cmdSuffix;
    FILE* pipe = _popen(fullCmd.c_str(), "r");
    if (!pipe) return "ERROR";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            global_output += buffer;
    }
    _pclose(pipe);
    return global_output.c_str();
}

extern "C" __declspec(dllexport) const char* GetDeviceInformation(const char* adbPath) {
    std::string devices = executeCommand(adbPath, "devices");
    if (devices.find("device") == std::string::npos) {
        //连接不到设备 输出错误
        global_output = "Device connection error.";
        return global_output.c_str();
    }

    std::string manufacturer = executeCommand(adbPath, "shell getprop ro.product.manufacturer");
    std::string model = executeCommand(adbPath, "shell getprop ro.product.model");
    std::string deviceName = executeCommand(adbPath, "shell getprop ro.product.device");
    std::string androidVersion = executeCommand(adbPath, "shell getprop ro.build.version.release");
    std::string serialNumber = executeCommand(adbPath, "shell getprop ro.serialno");
    std::string cpuABI = executeCommand(adbPath, "shell getprop ro.product.cpu.abi");

    global_output = "manufacturer[" + manufacturer + "]model[" + model + "]deviceName[" + deviceName + "]androidVersion[" + androidVersion + "]serialNumber[" + serialNumber + "]cpuABI[" + cpuABI + "]infoby[zhizi]";

    return global_output.c_str();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
