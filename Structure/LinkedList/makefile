all: cLinkedList cppLinkedListBI javaLinkedList.class

cLinkedList: cLinkedList.c
	gcc -o cLinkedList cLinkedList.c

cppLinkedListBI: cppLinkedListBI.cpp

javaLinkedList.class: javaLinkedList.java
	javac javaLinkedList.java

clean: cLinkedList
	rm cLinkedList cppLinkedListBI javaLinkedList.class
