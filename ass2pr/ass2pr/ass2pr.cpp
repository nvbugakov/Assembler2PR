// ass2pr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    char a[256];
    char b[256];
    char r[512];
    char f[] = "%s";
    char fd[] = "%d\n";
    
    _asm {
        lea eax, a
        push eax
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
       
        lea eax, b
        push eax
        lea ecx , f
        push ecx
        call scanf
        add esp, 8

        lea ecx, r
        dec ecx
        lea ebx, a
        dec ebx
        b1 :
        inc ebx
            mov al, [ebx]
            inc ecx
            mov[ecx], al
            inc edx
            cmp al, 0
            jnz b1

            dec ecx

        lea ebx, b
            dec ebx
            c1:
        inc ebx
            mov al, [ebx]
            inc ecx
            mov[ecx], al
            inc edx
            cmp al, 0
            jnz c1

            lea ecx, r
            push ecx
            lea ebx, f
            push ebx
            call printf
            add esp,8


         
    }
  

}

