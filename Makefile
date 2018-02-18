test: testMain.c
	gcc -o test testMain.c -lm
gTest: graphics.c
	gcc -o graphics graphics.c -lglut -lGLU -lGL -lm
main: main.c
	gcc -o main main.c -lglut -lGLU -lGL -lm
