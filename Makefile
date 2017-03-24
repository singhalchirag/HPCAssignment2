CC=gcc
FLAGS=-fopenmp
EXECS=omp_bug2 omp_bug3 omp_bug4 omp_bug5 omp_bug6 question2

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

question2: question2.c
	${CC} ${FLAGS} question2.c -o question2


clean:
	rm -f ${EXECS}
