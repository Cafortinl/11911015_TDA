all:
	-g++ main.cpp \
	Object.cpp \
	Alumno.cpp \
	Simbolo.cpp \
	TDAList.cpp \
	TDAStack.cpp \
	TDAQueue.cpp \
	ArrayList.cpp \
	ArrayStack.cpp \
	ArrayQueue.cpp \
	Node.cpp \
	LinkedList.cpp \
	-o tda
clean:
	-rm o
