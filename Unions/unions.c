#include <stdio.h>




typedef enum ESTADO_CIVIL{
    SOLTERO,
    CASADO,
    DIVORCIADO,
    VIUDO

}ESTADO_CIVIL;


// A diferencia de los structs, los unions solo puedes definir únicamente 1 solo miembro, en cambio los structs, pueden definir todos sus miembros.
// Nos puedes servir en casos en los cuales necesitemos solo definir 1 miembro. Los podemos usar anidados en structs

typedef struct PERSONA
{
    ESTADO_CIVIL estadoCivil;
    union 
    {   // Promedio de salario por hora
        int PromedioSalarioHora;
        // Salario Mensual
        int salario;
    };

    

}PERSONA;

void ImprimirTipoDESalario(PERSONA*persona){
    // En esta función evaluaremos cómo es que se pueden usar en conjunto los structs, unions y enums.
    switch (persona->estadoCivil)
    {

    /*también podemos acceder a los miembros enums mediante su valor entero: 
    
    case 0:printf("Salario por Mes: %d\n",persona->salario);break;
    case 1:printf("Salario por hora de este maltido pobre: %d);break;
    
    */
    case CASADO:printf("Salario por Mes: %d\n",persona->salario);break;
    case SOLTERO:printf("Salario por hora de este maldito pobre: %d \n",persona->PromedioSalarioHora);break;
    
    default:
        break;
    }

}


int main(){
    PERSONA persona1={CASADO,20};
    ImprimirTipoDESalario(&persona1);
    PERSONA persona2={SOLTERO,10};
    ImprimirTipoDESalario(&persona2);


}