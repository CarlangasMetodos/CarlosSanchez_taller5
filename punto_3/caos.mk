caos.pdf::caos.py dat.txt
	python caos.py

dat.txt::caos.x
	./caos.x > dat.txt

caos.x::caos.cpp
	g++ caos.cpp
