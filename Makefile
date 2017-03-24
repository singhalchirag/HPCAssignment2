CC=gcc
FLAGS=-fopenmp
EXECS=omp_bug2 omp_bug3 omp_bug4 omp_bug5 omp_bug6 question2-gauss-parallel question2-gauss-serial question2-jacobi-parallel question2-jacobi-serial

all: ${EXECS}

omp_bug2: omp_bug2.c
	${CC} ${FLAGS} omp_bug2.c -o omp_bug2

omp_bug3: omp_bug3.c
	${CC} ${FLAGS} omp_bug3.c -o omp_bug3

omp_bug4: omp_bug4.c
	${CC} ${FLAGS} omp_bug4.c -o omp_bug4

omp_bug5: omp_bug5.c
	${CC} ${FLAGS} omp_bug5.c -o omp_bug5

omp_bug6: omp_bug6.c
	${CC} ${FLAGS} omp_bug6.c -o omp_bug6

question2-gauss-parallel: question2-gauss-parallel.c
	${CC} ${FLAGS} question2-gauss-parallel.c -o question2-gauss-parallel

question2-gauss-parallel: question2-gauss-serial.c
	${CC} ${FLAGS} question2-gauss-serial.c -o question2-gauss-serial

question2-jacobi-parallel: question2-jacobi-parallel.c
	${CC} ${FLAGS} question2-jacobi-parallel.c -o question2-jacobi-parallel

question2-jacobi-serial: question2-jacobi-serial.c
	${CC} ${FLAGS} question2-jacobi-serial.c -o question2-jacobi-serial


clean:
	rm -f ${EXECS}
