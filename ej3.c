#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
	const char *nombre;
	const char *apellido;
	double promedio;
	
}alumno_t ;

int comparAlumno (const void *pA, const void *pB);

int main (void){

	alumno_t alumnos [5];

	alumnos[0].nombre = "Damian";
	alumnos[0].apellido = "Sergi";
	alumnos[0].promedio = 6.5;
	
	alumnos[1].nombre = "Tania";
	alumnos[1].apellido = "Lembo";
	alumnos[1].promedio = 7.5;
	
	alumnos[2].nombre = "Alexis";
	alumnos[2].apellido = "Aches";
	alumnos[2].promedio = 9.5;

	alumnos[3].nombre = "Federico";
	alumnos[3].apellido = "Sergi";
	alumnos[3].promedio = 6.5;
	
	alumnos[4].nombre = "Agustina";
	alumnos[4].apellido = "Aches";
	alumnos[4].promedio = 9.5;

	for(int i =0; i<5; i++){
	
		printf("%s ", alumnos[i].nombre );
		printf("%s ", alumnos[i].apellido);
		printf("%f ", alumnos[i].promedio);		
		printf("\n");		
	}

	qsort(alumnos, (sizeof(alumnos)/sizeof(alumno_t)), sizeof(alumno_t), &comparAlumno );
	
		printf("Aqui luego de llamar a Quicksort\n");	
	
	for(int i =0; i<5; i++){
	
		printf("%s ", alumnos[i].nombre );
		printf("%s ", alumnos[i].apellido);
		printf("%f ", alumnos[i].promedio);
		printf("\n");					
	}

	return 0;
}


int comparAlumno (const void *pA, const void *pB){

	alumno_t estA = *((alumno_t*)pA);
	
	alumno_t estB = *((alumno_t*)pB);

	if ( estA.promedio == estB.promedio ){
	
		if ( estA.apellido == estB.apellido ){
		
			int i = 0;
		
			while(estA.nombre[i] == estB.nombre[i]){		//Me muevo hasta el punto donde sean diferentes
			
				i++;
			}
			
			return (estA.nombre[i] - estB.nombre[i]);		//Aca en orden alfabetico
		}
		else{
		
			int i = 0;
		
			while(estA.apellido[i] == estB.apellido[i]){		//Me muevo hasta el punto donde sean diferentes
			
				i++;
			}	
			return (estA.apellido[i] - estB.apellido[i]);	//Aca en orden alfabetico
		}
	
	}
	else{
	
		return (estB.promedio - estA.promedio);		//Aca en orden alfabetico
	}
}
