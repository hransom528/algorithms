all: cBinSearch javaBinSearch.class

cBinSearch: cBinSearch.c

javaBinSearch.class: javaBinSearch.java
	javac javaBinSearch.java

clean: cBinSearch javaBinSearch.class
	rm cBinSearch javaBinSearch.class
