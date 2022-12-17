APP = build/3DViewer.app
CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. --coverage
CHECK_FLAGS = -lcheck

all: install tests clean

build:
	mkdir build
	cd ./build/ && qmake ../3DWieve && make

install: uninstall build
	@mkdir $(HOME)/Desktop/3DViewer
	@cp -rf $(APP) $(HOME)/Desktop/3DViewer
	make clean

uninstall: clean
	@rm -rf $(HOME)/Desktop/3DViewer

dvi:
	open 'https://isqua.ru/blog/' // вставь ссылку на редми

dist:
	rm -rf Archive_3DViewer_v1.0/
	mkdir Archive_3DViewer_v1.0/
	mkdir Archive_3DViewer_v1.0/src
	cp Makefile *.c *.h *.pro *.cpp *.ui *.user Archive_3DViewer_v1.0/src/
	tar cvzf Archive_3DViewer_v1.0.tgz Archive_3DViewer_v1.0/
	mv Archive_3DViewer_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_3DViewer_v1.0/

tests:
	checkmk clean_mode=1 GUI/test.check > GUI/test.c
	gcc -Wall -Werror -Wextra 3DWieve/s21_viewer.c 3DWieve/test.c -lcheck
	rm 3DWieve/test.c
	./a.out

gcov_report:
	rm -f *.g*
	checkmk clean_mode=1 3DWieve/test.check > 3DWieve/test.c
	gcc -Wall -Werror -Wextra 3DWieve/viewer.c 3DWieve/test.c -lcheck --coverage
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	rm 3DWieve/test.c
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info

3DViewer_v1.o:
	$(CC+FLAGS) -c *.c

linters:
	python3 ../materials/linters/cpplint.py --extensions=c *.c  // переделать под новый стиль, пока не знаю как

clean:
	rm -rf *.o *.a
	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf s21_calc s21_test // зачем??
	rm -rf ./build*
	rm -rf a.out

leaks:
	CK_FORK=no leaks --atExit -- ./a.out

rebuild: clean uninstall all

reinstall: clean uninstall install