#include<iostream>
#define WINVER 0x0500
#include <windows.h>
#include<string>
using namespace std;
class autoGUI{
public:
    
    string C_press(const char* str) {
        cout << str;
        
        int h_k; char key; int L = stoi(len(str)); cout << L;
        if (L == 1) {

            return  k_press(str);
        }

        if (str == "enter") {
            h_k = 0x0D;
            return hotkeys(to_string(h_k));
        }
        if (str == "ctrl") {
            h_k = 0x11;
            return hotkeys(to_string(h_k));
        }
        if (str == "alt"){
            h_k = 0x12;
            return hotkeys(to_string(h_k));
        }
        if (str == "win") {
            h_k = 0x5C;
            return hotkeys(to_string(h_k));
        }
        if (str == "esc") {
            h_k = 0x1B;
            return hotkeys(to_string(h_k));
        }
        if (str == "spacebar") {
            h_k = 0x20;
            return hotkeys(to_string(h_k));
        }
        if (str == "capslock") {
            h_k = 0x14;
            return hotkeys(to_string(h_k));
        }
        if (str == "shift") {
            h_k = 0x10;
            return hotkeys(to_string(h_k));
        }
        if (str == "clear") {
            h_k = 0x0C;
            return hotkeys(to_string(h_k));
        }
        if (str == "backspace") {
            h_k = 0x08;
            return hotkeys(to_string(h_k));
        }
        if (str == "tab")
        if (str == "pause") {
            h_k = 0x13;
            return hotkeys(to_string(h_k));
        }
        if (str == "pageup") {
            h_k = 0x21;
            return hotkeys(to_string(h_k));
        }
        if (str == "pagedown") {
            h_k = 0x22;
            return hotkeys(to_string(h_k));
        }
        if (str == "end") {
            h_k = 0x23;
            return hotkeys(to_string(h_k));
        }
        if (str == "home") {
            h_k = 0x24;
            return hotkeys(to_string(h_k));
        }
        if (str == "L_arrowkey") {
            h_k = 0x25;
            return hotkeys(to_string(h_k));
        }
        if (str == "R_arrowkey") {
            h_k = 0x27;
            return hotkeys(to_string(h_k));
        }
        if (str == "DOWN_arrowkey") {
            h_k = 0x28;
            return hotkeys(to_string(h_k));
        }
        if (str == "UP_arrowkey") {
            h_k = 0x26;
            return hotkeys(to_string(h_k));
        }
        if (str == "select") {
            h_k = 0x29;
            return hotkeys(to_string(h_k));
        }
        if (str == "print") {
            h_k = 0x2A;
            return hotkeys(to_string(h_k));
        }
        if (str == "execute") {
            h_k = 0x2B;
            return hotkeys(to_string(h_k));
        }
        if (str == "prtscr") {
            h_k = 0x2C;
            return hotkeys(to_string(h_k));
        }
        if (str == "insert") {
            h_k = 0x2D;
            return hotkeys(to_string(h_k));
        }
        if (str == "delete") {
            h_k = 0x2E;
            return hotkeys(to_string(h_k));
        }
        if (str == "help") {
            h_k = 0x2F;
            return hotkeys(to_string(h_k));
        }
        else {

            return e_rror("0");
        }
   
    }

    const char* hotkeys(string k) {
        if (k != "0") {
            INPUT ip;
            // Set up a generic keyboard event.
            ip.type = INPUT_KEYBOARD;
            ip.ki.wScan = 0; // hardware scan code for key
            ip.ki.time = 0;
            ip.ki.dwExtraInfo = 0;

            // Press the "enter" key
            ip.ki.wVk = stoi(k); // virtual-key code for the "enter" key
            ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));


            ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
            SendInput(1, &ip, sizeof(INPUT));
            return "0";
        }
        cout << "Invalid key " << endl;

    }
    const char* k_press(const char* key) {//if press = other than Hotkeys

        INPUT ip;
        ip.type = INPUT_KEYBOARD;
        ip.ki.time = 0;
        ip.ki.dwFlags = KEYEVENTF_UNICODE; // Specify the key as a unicode character
        ip.ki.wScan = (unsigned char)key[0]; // Which keypress to simulate
        
        ip.ki.wVk = 0;
        ip.ki.dwExtraInfo = 0;
        SendInput(1, &ip, sizeof(INPUT));
        return "0";
    }
    string len(string str) {/*******************************************************************************************************/
        
        return to_string(str.length());//calculate the length of stringh
    }
    void C_write(const char* sen,int t) {//for writting a sentence
        int length = stoi(len(sen));
        float time=(float)t*100;
        for (int i = 0; i < length; i++) {//loop to pass only one character at a time
            
            
            INPUT ip;
            ip.type = INPUT_KEYBOARD;
            ip.ki.time = 0;
            ip.ki.dwFlags = KEYEVENTF_UNICODE; // Specify the key as a unicode character
            ip.ki.wScan =sen[i]; // Which keypress to simulate
            ip.ki.wVk = 0;
            ip.ki.dwExtraInfo = 0;
            SendInput(1, &ip, sizeof(INPUT));

            Sleep(time);
        }

    }
    string e_rror( const char* e) {

        cout << "Invalid command :(" << endl;
        return "0";
    }
 
};


int main()
{
    
    
    
    Sleep(2000);
    autoGUI gi; gi.C_press("win");
}
/*int main() {
    
}*/