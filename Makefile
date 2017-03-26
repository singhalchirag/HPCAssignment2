CC=gcc
FLAGS=-fopenmp
EXECS=omp_solved2 omp_solved3 omp_solved4 omp_solved5 omp_solved6 gs2D-omp question2-gauss-serial jacobi2D-omp question2-jacobi-serial

all: ${EXECS}

omp_solved2: omp_bug2.c
	${CC} ${FLAGS} omp_bug2.c -o omp_solved2

omp_solved3: omp_bug3.c
	${CC} ${FLAGS} omp_bug3.c -o omp_solved3

omp_solved4: omp_bug4.c
	${CC} ${FLAGS} omp_bug4.c -o omp_solved4

omp_solved5: omp_bug5.c
	${CC} ${FLAGS} omp_bug5.c -o omp_solved5

omp_solved6: omp_bug6.c
	${CC} ${FLAGS} omp_bug6.c -o omp_solved6

gs2D-omp: question2-gauss-parallel.c
	${CC} ${FLAGS} question2-gauss-parallel.c -o gs2D-omp

question2-gauss-serial: question2-gauss-serial.c
	${CC} ${FLAGS} question2-gauss-serial.c -o question2-gauss-serial

jacobi2D-omp: question2-jacobi-parallel.c
	${CC} ${FLAGS} question2-jacobi-parallel.c -o jacobi2D-omp

question2-jacobi-serial: question2-jacobi-serial.c
	${CC} ${FLAGS} question2-jacobi-serial.c -o question2-jacobi-serial


clean:
	rm -f ${EXECS}
