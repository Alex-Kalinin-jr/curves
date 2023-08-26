export LD_LIBRARY_PATH=.
NUM=2 #num of threads

install: curves
	g++ main.cc libcurves.so -DNUM_OF_THREADS=$(NUM) -lpthread  
	./a.out

curves:
	g++ -shared -fPIC -o libcurves.so lib/curves.cc

test: clean
	g++ -o test lib/curves.cc tests.cc -g -lgtest -lm -lrt -lpthread -lsubunit 
	./test
	
clean:
	rm -f test a.out libcurves.so

style:
	-@clang-format -style=file -i *'.cpp' *'.hpp' *'.h' lib/*'.cpp' \
lib/*'.cc' lib/*'.h' lib/*'.hpp' *'.cc'