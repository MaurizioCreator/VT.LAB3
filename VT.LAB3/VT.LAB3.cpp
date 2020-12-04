#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    __int16 A = 350, B = 750;
    __int32 C = 1500;
    int D = 0; // D = (A * B) - C
    _asm {
        mov AX, A;
        imul B;
        SUB AX, word ptr C;
        SBB DX, word ptr C + 2;
        mov word ptr D, AX;
        mov word ptr D + 2, DX;
    }

    cout << "D = (" << A << " * " << B << ") - " << C << endl;
    cout << "D = " << D << endl;
     
    __int16 E = 0; // E = ( C / B ) + A
    _asm {
        mov AX, word ptr C;
        mov DX, word ptr C + 2;
        idiv B;
        ADD AX, A;
        mov word ptr E, AX;   
    }

    cout << "E = (" << C << " / " << B << ") + " << A << endl;
    cout << "E = " << E << endl;
    return 0;
}

