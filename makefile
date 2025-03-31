local:
	g++ -o main main.cpp EJ_1/Tiempos.cpp Ej_2/Consola.cpp Ej_3/Numeros.cpp Ej_4/BBVA.cpp
	
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
    
	rm main