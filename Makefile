export LD_LIBRARY_PATH=.
NUM=2

install: curves
	g++ main.cc libcurves.so -DNUM_OF_THREADS=$(NUM) -lpthread  
	./a.out

curves:
	g++ -shared -fPIC -o libcurves.so lib/curves.cc

test: clean
	g++ -o test lib/curves.cc tests.cc -g -lgtest -lm -lrt -lpthread -lsubunit 
	./test
	
clean:
	rm -f test

leaks:
	g++ -o test_file model/s21_maze.cc -g model/main_leaks.cc
	valgrind --log-file="v_report" --tool=memcheck --track-origins=yes -v ./test_file

style:
		-@clang-format -style=file -i *'.cpp' *'.hpp' *'.h' model/*'.cpp' \
lib/*'.cc' lib/*'.h' lib/*'.hpp' *'.cc'