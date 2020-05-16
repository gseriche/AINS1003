#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Escriba un algoritmo que indique si un valor determinado existe o no en un
/ arreglo de N posiciones. Se pide que el bucle termine cuando se encuentre el valor.
/ Los elementos y la dimensión del arreglo debe ser ingresado por el usuario */

int L,B,Arreglo[100];
void bienvenido();
void ejercicio();
void imprimirElementos();
void busco(int b);
int randomize();

/* El programa principal */

main(){
  /* Inicializo el random */
  srand(time(0));

  /* Banner de bienvenida */
  bienvenido();

  /* El ejercicio */
  ejercicio();
}

void bienvenido() {
  system("clear");
  printf("Bienvenido, se le solicitara el ingreso del largo del arreglo a buscar\n");
  printf("Luego de ello, se le solicitara ingresar el valor a buscar dentro del arreglo\n\n\n");
  return;
}

void ejercicio() {
  /* Pido el largo del arreglo */
  do {
    printf("\nIngresar largo del arreglo: \n");
    scanf("%d", &L);
  }while(L<0 || L>100);

  /* Ingreso los numeros de forma random del 1 al 20 */
  for(int i = 1; i<=L; i++){
    Arreglo[i] = randomize();
  }

  /* Pido el número a buscar (si, trampa entre 1 y 20) */
  do {
    printf("\nIngrese el valor a buscar (entre 1 y 20): \n");
    scanf("%d", &B);
  }while(B<0 || B>20);

  /* Luego busco si esta el valor ingresado en mi arreglo randomizado */
  busco(B);

}


/* Mi super generador de numeros */
int randomize(){
  int minimo = 1, maximo = 20, cuento = 1, i = 0;
  for (i = 0; i < cuento; i++){
    int num = (rand() %
        (maximo - minimo + 1)) + minimo;
        return num;
  }
}

/* Imprimo los valores del arreglo */
void imprimirElementos() {
  for(int i = 0; i <= L; i++){
    printf("Elemento [%d] = %d \n", i, Arreglo[i]);
  }
}

/* Mi super duper buscador */
void busco(int b){
  int found = 0;
  for(int i = 0; i <= L; i++){
    if(b == Arreglo[i]){
      printf("\nEureka! Lo encontré en el elemento numero %d del arreglo \n", i);
      found = 1;
    }
  }

  /* Si lo encuentro imprimo el mensaje Eureka y ademas imprimo ( para no mentir mas ;) )*/
  if (found == 0){
    printf("\nEl valor no fue encontrado :'( \n");
  }

  imprimirElementos();

}
