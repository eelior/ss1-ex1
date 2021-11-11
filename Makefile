CC = gcc
AR = ar
FLAGS = -Wall -g
BASIC = basicClassification.o
LOOPS = advancedClassificationLoop.o
RECUR = advancedClassificationRecursion.o

all: loops recursives recursived loopd mains maindloop maindrec

loopd: libclassloops.so
loops: libclassloops.a
recursived: libclassrec.so
recursives: libclassrec.a

mains: main.o libclassrec.a
	${CC} ${FLAGS} main.o -L . -lclassrec -lm -o mains

maindrec: main.o libclassrec.so
	${CC} ${FLAGS} main.o -L . -lclassrec -lm -o maindrec

maindloop: main.o libclassloops.so
	${CC} ${FLAGS} main.o -L . -lclassloops -lm -o maindloop

libclassloops.so: ${BASIC} ${LOOPS}
	${CC} ${FLAGS} -shared ${LOOPS} ${BASIC} -o libclassloops.so

libclassloops.a: ${BASIC} ${LOOPS}
	${AR} -rcs libclassloops.a  ${BASIC} ${LOOPS}

libclassrec.so: ${BASIC} ${RECUR}
	${CC} ${FLAGS} -shared ${BASIC} ${RECUR} -o libclassrec.so

libclassrec.a: ${BASIC} ${RECUR}
	${AR} -rcs libclassrec.a ${BASIC} ${RECUR}

main.o: main.c NumClass.h
	${CC} ${FLAGS} -c main.c

basicClassification.o: basicClassification.c
	${CC} ${FLAGS} -fPIC -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	${CC} ${FLAGS} -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	${CC} ${FLAGS} -fPIC -c advancedClassificationRecursion.c

clean:
	rm -f *.a *.o *.so  maindrec maindloop mains