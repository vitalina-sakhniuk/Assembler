Testing : 
	push    ax
        push    cx
        push    dx

		test ax,ax ;�������� �� ����, ���� ��'����- ���������� 16 ����, ���� �������, ���� 4
		mov cx,12
		js m1
		jns m5



	m3:mov dl,20h ; ����� �� ������� 4-�� ���������
	mov ah,02h
	int 21h 
	dec cx
	jmp m1


	m1:  jcxz m4 ; ��������� ���� FFFF,�� � 16-�  �� �������� �� ��'���� �����
 	mov dl,46h
	mov ah,02h
	int 21h  

	mka: cmp cx,9 ; �������� ��� ������ �� 4-�� ���������
	jz m3
	cmp cx,5
	jz m3
	cmp cx,0
	jz m3
	jnz m11


	m11: jcxz m4 
	loop m1

             
	m4: mov dl,20h
	mov ah,02h
	int 21h 
	jmp m5
	

	m5:pop dx 
	pop cx
	pop ax
	jmp ShowHex  ; ������ �����������


ShowHex:
 	push    ax
        push    cx
        push    dx
           		   
	mov cl,     12 ; ��������� �� 4 ���(0...F), ����������� ����� � �����
        mov dx,     ax      ; ���������� ����� � DX


Steprep:
 
        mov     ax,     dx      ; ³��������� ����� � ��
        shr   ax,      cl       ; ���� ������ �� cl(������� ���� �� 4)
        and     al,     0Fh     ; ��������� ����� � Al, �� 0 �� 15  
	adc     al,     90h     ; special hex conversion sequence
        daa                     ; ��������
        adc     al,     40h
        daa                     ; ������������� ��������� ����� �� � ��곳
        int     29h             ; ��������� ������� �� �����
        sub     cl,     4       ; ��������� cl �� 4 ��� �������� �����
        jns     Steprep         ; ���� CL >= 0, �� ����������
       


	mov DL, 104
	mov AH, 2

	int 21h

	mov DL, 0Dh
	mov AH, 2

	int 21h


	mov DL, 0Ah
	mov AH, 2

	int 21h 



	pop     dx
        pop     cx
        pop     ax
        ret



