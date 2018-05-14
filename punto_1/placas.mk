placas.pdf:: placas.py data.txt
	python placas.py

data.txt::a.out
	./a.out placas.cpp

a.out::placas.cpp
	g++ placas.cpp
