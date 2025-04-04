local:
	g++ -Wall -o main main.cpp EJ_1/Tiempos.cpp Ej_2/Consola.cpp Ej_2/Cursos.cpp Ej_2/Estudiantes.cpp Ej_3/Numeros.cpp Ej_4/BBVA.cpp EJ_1/consola_tiempos.cpp Ej_3/Consola_numeros.cpp Ej_4/Consola_banco.cpp clear.cpp
	
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
    
	rm main