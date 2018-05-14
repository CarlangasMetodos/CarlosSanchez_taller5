cuerda.gif::animacion.py dat.txt
	python animacion.py

dat.txt::a.out
	./a.out cuerda.cpp > dat.txt

a.out::cuerda.cpp
	g++ cuerda.cpp
