FLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
BUILD_PATH=./
SOURCES=quadratic_equation.c
H=quadratic_equation.h
LIBO=*.o
LIBA=quadratic_equation.a
EXE=test.out
TST_LIBS=-lcheck -lsubunit -lm -lpthread


all: quadratic_equation.a check

quadratic_equation.a: clean 
	gcc ${FLAGS} -c $(SOURCES)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA) 

check: quadratic_equation.a
	gcc  ${FLAGS} test.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)


rebuild: clean all

clean:
	rm -rf *.a && rm -rf *.o && rm -rf test.out



