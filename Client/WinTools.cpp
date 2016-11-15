#include "WinTools.h"
#include "Utils.h"

#include <stdio.h>
#include <windows.h>

int mbox(const char* title, const char* body, icon type, button but){
    u_int x = 0;
    u_int y = 0;

    switch(but){
        case 0:
            x = MB_OK;
            break;
        case 1:
            x = MB_OKCANCEL;
            break;
        case 2:
            x = MB_YESNO;
            break;
        case 3:
            x = MB_YESNOCANCEL;
            break;
        case 4:
            x = MB_RETRYCANCEL;
            break;
        case 5:
            x = MB_ABORTRETRYIGNORE;
            break;
    }

    switch(type){
        case 0:
            y = MB_ICONINFORMATION;
            break;
        case 1:
            y = MB_ICONQUESTION;
            break;
        case 2:
            y = MB_ICONERROR;
            break;
        case 3:
            y = MB_ICONWARNING;
            break;
    }

    int res = 0;

    res = MessageBoxA(NULL, (LPCSTR)body, (LPCSTR)title, y | x);

    return res;

}

void send_keys(string z){
    if(issame(z, "{EN}")){
        keybd_event(VK_RETURN, 0, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    } else {
        for(int i = 0; z[i] != '\0'; i++){
            if(((char) toupper(z[i]) == z[i] && contains("ABCDEFGHIJKLMNOPQRSTUVWXYZ", z[i])) || contains("\":<>?{}|~_+!@#$%^&*()", z[i])){
                keybd_event(VK_SHIFT, 0, 0, 0);
                keybd_event(VkKeyScan(z[i]), 0, 0, 0);
                keybd_event(VkKeyScan(z[i]), 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            } else {
                keybd_event(VkKeyScan(z[i]), 0, 0, 0);
                keybd_event(VkKeyScan(z[i]), 0, KEYEVENTF_KEYUP, 0);
            }
            Sleep(100);
        }
    }
}

void instant_send_keys(string z){
    if(issame(z, "{EN}")){
        keybd_event(VK_RETURN, 0, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    } else {
        for(int i = 0; z[i] != '\0'; i++){
            if(((char) toupper(z[i]) == z[i] && contains("ABCDEFGHIJKLMNOPQRSTUVWXYZ", z[i])) || contains("\":<>?{}|~_+!@#$%^&*()", z[i])){
                keybd_event(VK_SHIFT, 0, 0, 0);
                keybd_event(VkKeyScan(z[i]), 0, 0, 0);
                keybd_event(VkKeyScan(z[i]), 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            } else {
                keybd_event(VkKeyScan(z[i]), 0, 0, 0);
                keybd_event(VkKeyScan(z[i]), 0, KEYEVENTF_KEYUP, 0);
            }
        }
    }
}

void create_process(char* name){
    STARTUPINFO inf;
    PROCESS_INFORMATION pro;
    ZeroMemory(&inf, sizeof(inf));
    inf.cb = sizeof(inf);
    ZeroMemory(&pro, sizeof(pro));

    if(!CreateProcessA(LPCSTRfromString(name), GetCommandLineA(), NULL, NULL, false, 0, NULL, NULL, &inf, &pro)){
    }
}

void change_background(string path){

}

void hold_down(string z, int delay){
    if(issame(z, "{EN}")){
        keybd_event(VK_RETURN, 0, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    } else {
        for(int i = 0; z[i] != '\0'; i++){
            if(((char) toupper(z[i]) == z[i] && contains("ABCDEFGHIJKLMNOPQRSTUVWXYZ", z[i])) || contains("\":<>?{}|~_+!@#$%^&*()", z[i])){
                keybd_event(VK_SHIFT, 0, 0, 0);
                keybd_event(VkKeyScan(z[i]), 0, 0, 0);
                Sleep(delay);
                keybd_event(VkKeyScan(z[i]), 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            } else {
                keybd_event(VkKeyScan(z[i]), 0, 0, 0);
                Sleep(delay);
                keybd_event(VkKeyScan(z[i]), 0, KEYEVENTF_KEYUP, 0);
            }
        }
    }
}

void switch_monitor_status(int delay){
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
	Sleep(delay);
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);
}

void open_cd_tray() {
	mciSendString("set cdaudio door open", NULL, NULL, NULL);
}
