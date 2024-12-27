#include <stdio.h>

/*Write a function that receives an array. the Function should find and return 
    the "Second smallest"   Value in the array
    
*/
// Recorremos el arreglo para obtener el elemento menor, a medida que vamos obteniendo el menor, vamos comparando
// si dicho elemento es menor al elemento actual y mayor al "smallestElement".


// int secondSmallest(int*array,int size){
//     int smallest=*(array),sndSmallest=*(array);
        // Find the smallest number.
//     for (int i=1;i<size;i++){
//         if (array[i]<smallest){
//             smallest=array[i];
//             printf("Smallest: %d\n",smallest);
//         }

//     }

        // Find de 2nd smallest number.
//      for (int i=1;i<size;i++){
        
//         if (array[i]<sndSmallest && array[i]>smallest){
//         sndSmallest=array[i];
//         printf("SecondSmallest: %d\n",sndSmallest);

//         }

//     }
//     return sndSmallest;

// }
// Solucion lineal


int secondSmallest(int*array,int size){
    int smallest=*(array),sndSmallest=*(array);

    for (int i=1;i<size;i++){
        if (array[i]<smallest){
            sndSmallest=smallest;
            smallest=array[i];
        }else if(array[i]<sndSmallest){
            sndSmallest=array[i];
        }

    }

     
    return sndSmallest;
}




int main(){

    // int arr[6]={7,1,6,3,2,0}; # Caso 1
    int arr[5]={2,3,5,6,7};
    printf("%d\n",secondSmallest(arr,5));


}