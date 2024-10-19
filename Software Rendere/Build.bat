cd C:\Users\ExciliousRBX\Desktop\FusionEngine\core
echo nasm -f win64 v_draw.asm -o v_draw.obj
gcc -o Engine.exe f_main.c f_math.h v_draw.c -lgdi32 