trust:	trust.h trust.cpp 
		g++ trust.cpp -o trust


run:	trust
		./trust < digraph1.txt
		./trust < digraph2.txt
		./trust < digraph3.txt

clean:
		rm -f trust
