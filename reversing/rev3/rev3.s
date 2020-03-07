.LC0:
        .string "Hm.. not quite.."
.LC1:
        .string "r"
.LC2:
        .string "flag.txt"
.LC3:
        .string "Too bad you can only run this exploit on the server..."
.LC4:
        .string "%s"
main:
        lea     ecx, [esp+4]
        and     esp, -16
        push    DWORD PTR [ecx-4]
        push    ebp
        mov     ebp, esp
        push    ecx
        sub     esp, 404
        mov     DWORD PTR [ebp-12], 0
        lea     eax, [ebp-88]
        mov     DWORD PTR [ebp-16], eax
        lea     eax, [ebp-152]
        mov     DWORD PTR [ebp-20], eax
        mov     eax, DWORD PTR stdin
        sub     esp, 4
        push    eax
        push    64
        push    DWORD PTR [ebp-16]
        call    fgets
        add     esp, 16
        mov     eax, DWORD PTR stdin
        sub     esp, 4
        push    eax
        push    64
        push    DWORD PTR [ebp-20]
        call    fgets
        add     esp, 16
        sub     esp, 8
        push    DWORD PTR [ebp-20]
        push    DWORD PTR [ebp-16]
        call    alg(char*, char*)
        add     esp, 16
        test    eax, eax
        sete    al
        movzx   eax, al
        mov     DWORD PTR [ebp-12], eax
        cmp     DWORD PTR [ebp-12], 0
        je      .L2
        sub     esp, 12
        push    OFFSET FLAT:.LC0
        call    puts
        add     esp, 16
        jmp     .L3
.L2:
        sub     esp, 8
        push    OFFSET FLAT:.LC1
        push    OFFSET FLAT:.LC2
        call    fopen
        add     esp, 16
        mov     DWORD PTR [ebp-24], eax
        cmp     DWORD PTR [ebp-24], 0
        jne     .L4
        sub     esp, 12
        push    OFFSET FLAT:.LC3
        call    puts
        add     esp, 16
        sub     esp, 12
        push    0
        call    exit
.L4:
        sub     esp, 4
        push    DWORD PTR [ebp-24]
        push    256
        lea     eax, [ebp-408]
        push    eax
        call    fgets
        add     esp, 16
        sub     esp, 8
        lea     eax, [ebp-408]
        push    eax
        push    OFFSET FLAT:.LC4
        call    printf
        add     esp, 16
.L3:
        mov     eax, 0
        mov     ecx, DWORD PTR [ebp-4]
        leave
        lea     esp, [ecx-4]
        ret
alg(char*, char*):
        push    ebp
        mov     ebp, esp
        push    ebx
        sub     esp, 20
        sub     esp, 12
        push    DWORD PTR [ebp+8]
        call    atoi
        add     esp, 16
        mov     ebx, eax
        sub     esp, 12
        push    DWORD PTR [ebp+12]
        call    atoi
        add     esp, 16
        imul    eax, ebx
        mov     DWORD PTR [ebp-12], eax
        cmp     DWORD PTR [ebp-12], 1337
        jne     .L7
        mov     eax, 1
        jmp     .L8
.L7:
        mov     eax, 0
.L8:
        mov     ebx, DWORD PTR [ebp-4]
        leave
        ret