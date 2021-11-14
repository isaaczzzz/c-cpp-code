ClassroomManagement: ClassroomManagement.o readline.o print.o
	gcc -o ClassroomManagement ClassroomManagement.o readline.o print.o
ClassroomManagement.o: ClassroomManagement.c read_print.h
	gcc -c ClassroomManagement.c
readline.o: readline.c read_print.h
	gcc -c readline.c
print.o: print.c read_print.h
	gcc -c print.c
