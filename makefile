local:
	g++ -o main main.cpp
	
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
    
	rm main