
global _start

;section .text

_start:



;mov rbx,gs:[60h]
;lea rsi,[rbx+18h]
;mov rbx,[rbx+20h]
;mov rbx,[rbx+rcx]
;mov rbx,[rbx+rcx]
;mov rbx,[rbx+20h]
mov rbx,gs:60h
lea rsi,[rbx+18h]
mov rbx,[rsi]
lea rsi,[rbx+20h]
mov rbx,[rsi]
mov rbx,[rbx]
mov rbx,[rbx]
lea rsi,[rbx+20h]
mov rbx,[rsi]
mov r8,rbx
;e_lfanew
mov ebx,[rbx+3ch]
add rbx,r8
mov edi,[rbx+88h]
add rdi,r8
mov r10d,[rdi+18h]
mov r9d,[rdi+20h]
add r9,r8
xor rcx,rcx

mov rcx,r10
call funcF


funcF:
jecxz gotha
xor rsi,rsi
mov esi,[r9+4+rcx*4]
add rsi,r8
dec rcx
mov rax,0x636578456E6957
cmp [rsi],rax
jnz funcF

gotha:

inc rcx
mov r10d,[rdi+24h]
add r10,r8

mov r11w,[r10+rcx*2]
mov r12d,[rdi+1ch]
add r12,r8
mov eax,[r12+4+r11*4]
add rax,r8

mov r14,rax

lop:
xor rcx,rcx
mov rcx,0x657865
push rcx
mov rcx,0x2E64617065746F6E
push rcx
mov rcx,rsp

xor rdx,rdx
inc rdx
and rsp,-16
sub rsp,32



call r14

;add rsp,0x30
;add rsp,0x30


