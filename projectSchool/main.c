#include "./functions.c"


int main(){

    // Adding Students and Course to linked list.
    School*headSchool=NULL;
   headSchool=addNewSchool(headSchool);
    headSchool->courses=addNewCourse(headSchool->courses);
   headSchool->courses->students=addNewStudent(headSchool->courses->students);
   headSchool->courses->students=addNewStudent(headSchool->courses->students);
   headSchool->courses->students=addNewStudent(headSchool->courses->students);


    headSchool->courses=addNewCourse(headSchool->courses);
   headSchool->courses->next->students=addNewStudent(headSchool->courses->next->students);
   headSchool->courses->next->students=addNewStudent(headSchool->courses->next->students);




    // Básicamente para poder seleccionar los cursos correspondientes debemos usar el identificador y luego
    // con este podemos anclarnos y acceder a sus propiedades.

    // La Cabeza (Raíz) siempre será la misma.
   studentsDetails(headSchool->courses,headSchool->courses->students);
   studentsDetails(headSchool->courses->next,headSchool->courses->next->students);
   freeSchools(headSchool);
    

}