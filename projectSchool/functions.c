#include "./structs.h"
#include <stdio.h>
#include <stdlib.h>



// returns length (lower -1 than real length);
int len(char*str){
    char*ptr_str=str;
    int i=0;
    while (*ptr_str!='\0')
    {
        i++;
        ptr_str++;
    }
    return i;
}



// Replace the '\n' for '\0'
void noStepLine(char*str){
    str[len(str)-1]='\0';
}


// Create :

/*allocates a new student struct in memory, and populates the struct with the provided details*/
Student*createStudent(){
    Student*newStudent=(Student*)calloc(1,sizeof(Student));
    printf("\nEnter Name of the Student: ");
    fgets(newStudent->name,50,stdin);
    noStepLine(newStudent->name);
    
    printf("\nEnter Record of the Student: ");
    scanf("%d",&newStudent->record);
    getchar();

    printf("\nEnter ID of the Student: ");
    scanf("%d",&newStudent->id);
    getchar();

    newStudent->next=NULL;
    return newStudent;

}

// Allocates a new school struct in memory, and populates it with the provided details
Course*createCourse(){
    Course*newCourse=(Course*)malloc(sizeof(Course));
    printf("\nEnter name of the Course: ");
    fgets(newCourse->name,50,stdin);
    noStepLine(newCourse->name);
    newCourse->averageGrade=0;
    printf("\nEnter NRC: ");
    scanf("%d",&(newCourse->nrc));
    getchar();

    newCourse->students=NULL;
    newCourse->next=NULL;

 
    return newCourse;
}

// Allocates a new course struct in memory, and populates it with the provided course details and students.
School*createSchool(){
    School*newSchool=(School*)malloc(sizeof(School));

    printf("\nEnter Name of the School: ");
    fgets(newSchool->name,50,stdin);
    noStepLine(newSchool->name);
    printf("\nEnter School´s Rif: ");
    scanf("%d",&newSchool->rif);
    getchar();

    newSchool->courses=NULL;
    newSchool->next=NULL;
    return newSchool;

}

// Add

Student*addNewStudent(Student*head){
    Student*newStudent=createStudent();
    if (head==NULL){
    return newStudent;
    }
    Student*ptr_head=head;
    while (ptr_head->next!=NULL)
    {
        ptr_head=head->next;
    }
     ptr_head->next=newStudent;
    return head;
}

    

Course*addNewCourse(Course*head){
    Course*newCourse=createCourse();
    if (head==NULL){
    return newCourse;
    }
    Course*ptr_head=head;
    while (ptr_head->next!=NULL)
    {
        ptr_head=head->next;
    }
     ptr_head->next=newCourse;
    return head;
}




School*addNewSchool(School*head){
    School*newSchool=createSchool();
    if (head==NULL){
    return newSchool;
    }

    School*ptr_head=head;
    while (ptr_head->next!=NULL)
    {
        ptr_head=head->next;
    }
     ptr_head->next=newSchool;
    return head;
}


// Details


// Calculate the Average Grade.
int averageGrade(Student*head){
    int cont=0;
    int studentCount=0;
    while (head!=NULL)
    {   
        cont+=head->record;
        studentCount++;
        head=head->next;
    }
    int avgGrade= cont/studentCount;
    return avgGrade;


}

//  Takes a student struct and prints its details.
void studentDetails(Student*head,int*i){
    printf("%d)Name : %s  --- Record : %d --- ID : %d \n",*(i+1),head->name,head->record,head->id);
    *(i)=*(i)+1;

}




// Print Student´s details From Course Menú.
void studentsDetails(Course*headCourse,Student*head){
    if (head==NULL){
       printf("\n\nCurso sin alumnos...\n\n");
        return;
    }
    
    printf("\n\n======== %s STUDENTS ========\n\n",headCourse->name);
    int i=0;
    while (head!=NULL){
        printf("%d)Name : %s  --- Record : %d --- ID : %d \n",i+1,head->name,head->record,head->id);
        head=head->next;
        i++;
    }
}

void courseDetails(Course*course){
    printf("\n\n===  Course: %s  ===\n\n",course->name);
    course->averageGrade=averageGrade(course->students);
    printf("Name: %s --- Average Grade : %d --- NRC : %d \n",course->name,course->averageGrade,course->nrc);
    studentsDetails(course ,course->students);


}







// Check if a course exists at the school.
void CheckCourse(School*head){
    if (head->courses==NULL){
        printf("\n\nSchool without Courses...\n\n");
        return;
    }
    
    int nrc;
    printf("\n\nEnter the NRC : ");
    scanf("%d",&nrc);
    getchar();


    Course*headCourse=head->courses;
    

    while (headCourse!=NULL)
    {   

        if (headCourse->nrc==nrc){
            courseDetails(headCourse);
            return;
        }
        headCourse=headCourse->next;
    }
    printf("\n\nCourse Not Found....\n\n");
}




// Search For student From Courses Menú.
void searchForStudent(Student*head,int id){
     if (head==NULL){
        printf("\n\nCurso sin alumnos...\n\n");
        return;
    }
    int i=0;
    while (head!=NULL)
    {   // Print Student Details.
        if (head->id==id){
        studentDetails(head,&i);
        return;
        }
        head=head->next;
    }
    printf("\n\nStudent Not Found.... \n\n");
}




void printOutStudentAllCourses(School*headSchool,Course*headCourse){
    if (headCourse==NULL){
        printf("\n\nESCUELA %s SIN CURSOS...\n\n",headSchool->name);
        return;
    }


    while(headCourse!=NULL)
    {
        studentsDetails(headCourse,headCourse->students);
        headCourse=headCourse->next;
    
    }
}











void freeStudents(Course*headCourse,Student*head){
    if (head== NULL){
        printf("\nCurso : %s Sin Estudiantes....\n\n",headCourse->name);
        return;
    }
    Student*aux=NULL;
    while (head!=NULL)
    {
        aux=head;
        printf("\nEliminando Estudiante: %s     Addres: %p\n",aux->name,aux);
        head=head->next;
        free(aux);
    }
}




void freeCourses(School*headSchool,Course*headCourse){
    if (headCourse== NULL){
        printf("\nEscuela : %s Sin Cursos...\n\n",headSchool->name);
        return;
    }


    Course*aux=NULL;
    
    while (headCourse!=NULL)
    {
        aux=headCourse;
        printf("\n\n======    Curso: %s ======\n",headCourse->name);
        headCourse=headCourse->next;
        freeStudents(aux,aux->students);
        free(aux); 


    }
    




}
    






void freeSchools(School*headSchool){
    if (headSchool==NULL){
    printf("\n\nNo hay Escuelas Disponibles..\n\n");
    return;
    }

    School*aux=NULL;
    while (headSchool!=NULL)
    {   
        aux=headSchool;
        printf("\n\n====   ELIMINANDO ESCUELA : %s  ====\n",aux->name);
        headSchool=headSchool->next;
        freeCourses(aux,aux->courses);
        free(aux);
    }
    


}


// DEBEMOS TENER CUIDADO CON ESTO, YA QUE SI USAMOS ÚNICAMENTE EL PUNTERO DE HEADSCHOOL ESTAMOS MODIFICANDO LA LISTA ORIGINAL.
void CourseFailedAvgGrade(School*headSchool){
    if (headSchool->courses==NULL){
        printf("\n\nEscuela sin CURSOS...\n\n");
        return;
    }
        int avgGrade=0;
        printf("\n\n=== CURSOS CON PROMEDIO DE REPROBADOS ===\n\n");
        Course*headCourse=headSchool->courses;
        while (headCourse!=NULL)
        {
            avgGrade=averageGrade(headCourse->students);
            if (avgGrade<10){
                courseDetails(headCourse);

            }
            headCourse=headCourse->next;
        }
}
        




void CoursePassedAvgGrade(School*headSchool){
if (headSchool->courses==NULL){
        printf("\n\nEscuela sin CURSOS...\n\n");
        return;
    }
        int avgGrade=0;
        printf("\n\n=== CURSOS CON PROMEDIO DE APROBADOS ===\n");
        Course*headCourse=headSchool->courses;
        while (headCourse!=NULL)
        {
            avgGrade=averageGrade(headCourse->students);
            if (avgGrade>=10){
                courseDetails(headCourse);

            }
            headCourse=headCourse->next;
        }
}


void highestCourseAverage(School*headSchool,Course*headCourse){
    if (headCourse==NULL){
        printf("\n\nNo hay Cursos Disponibles...\n\n");
        return;
    }

    int highestGrade=0;
    Course*highestCourseGrade=NULL;
    int avgGrade=0;
    while (headCourse!=NULL)
    {   
        avgGrade=averageGrade(headCourse->students);
        if (avgGrade>highestGrade){
            highestGrade=avgGrade;
            highestCourseGrade=headCourse;
        }
        headCourse=headCourse->next;

    }
    printf("\n\n=== CURSO CON EL PROMEDIO MAS ALTO: %s , PROMEDIO: %d ===\n",highestCourseGrade->name,highestGrade);
    courseDetails(highestCourseGrade);
    



}

void studentsWhopassed(Course*headCourse,Student*headStudent){
    if (headStudent==NULL){
        printf("\n\nNO HAY ALUMNOS EN ESTE CURSO....\n");
        return;
    }
    int i=0;
    printf("\n\n=== ALUMNOS APROBADOS : %s ===\n",headCourse->name);
    while (headStudent!=NULL)
    {
        if (headStudent->record>=10){
            printf("\n%d)Name : %s  --- Record : %d --- ID : %d \n",i+1,headStudent->name,headStudent->record,headStudent->id);
            i++;

        }
        headStudent=headStudent->next;
    }
        



}
void studentsWhofailed(Course*headCourse,Student*headStudent){
    if (headStudent==NULL){
        printf("\n\nNO HAY ALUMNOS EN ESTE CURSO....\n");
        return;
    }
    int i=0;
    printf("\n\n=== ALUMNOS REROBADOS: %s ===\n",headCourse->name);
    while (headStudent!=NULL)
    {
        if (headStudent->record<10){
            printf("\n%d)Name : %s  --- Record : %d --- ID : %d \n",i+1,headStudent->name,headStudent->record,headStudent->id);
            i++;

        }
        headStudent=headStudent->next;
    }
        


}





void courseMenu(School*rootSchool,Course*head){
    printf("\n\n=== BIENVENIDO AL CURSO : %s ===\n",head->name);
    Student*headStudent=NULL;
    int condicion=1;
    int option;
    while (condicion==1)
    {
        printf("\n=========   OPTIONS ========\n");
        printf("\n1)Create Student\n2)Course Details\n3)Students who Passed\n4)Students who Failed\n5)BACK\n6)Exit\n\nSelect Option: ");
        scanf("%d",&option);
        getchar();

        switch (option)
        {   
            case 1: headStudent=addNewStudent(headStudent);break;
            case 2: courseDetails(head);break;
            case 3: studentsWhopassed(head,headStudent);break;
            case 4: studentsWhofailed(head,headStudent);break;
            case 5: return; break;
            case 6: condicion=0;freeSchools(rootSchool);break;
            
            default:printf("\n\nInvalid Option.. Please Enter a valid number..\n\n") ;break;
        }

    }



}

void selectCourse(School*rootSchool,School*headSchool,Course*headCourse){

    if (headCourse==NULL){
        printf("\n\nNo hay Cursos disponibles en esta escuela \n\n");
        return;
    }

    Course*aux=headCourse;
    int i=0;

    while (aux!=NULL)
    {
        printf("\n%d) Name: %s   ---   NRC: %d\n",i+1,aux->name,aux->nrc);
        i++;
        aux=aux->next;


    }
    aux=headCourse;
    int nrc;
    printf("\n\nEnter NRC: ");
    scanf("%d",&nrc);
    getchar();

    while (aux!=NULL)
    {
        if (aux->nrc==nrc){
            courseMenu(rootSchool,aux);
            // schoolMenu(rootSchool,headSchool); // al momento de  terminar al función del menú del curso nos enviará al menú anterior.
            return;
        }
        aux=aux->next;
    }
    printf("\n\nCourse Not Found...\n\n");
}


// We use rootSchool to be able to free the whole system
void schoolMenu(School*rootSchool,School*head){
    printf("\n\n=== BIENVENIDO A LA INSTITUCIÓN: %s ===\n",head->name);
    Course*headCourse=NULL;
    int condicion=1;
    int option;
    while (condicion==1)
    {   
        printf("\n=========   OPTIONS ========\n");
        printf("\n1)Create Course\n2)Select Course\n3)Print Out Student all Courses\n4)Courses with a passed Average Grade\n5)Courses with a failed Average Grade\n6)Print the course with the highest Average Grade\n7)Back\n8)Exit\n\nSelect Option: ");
        scanf("%d",&option);
        getchar();
        switch (option)
        {   
            case 1: headCourse=addNewCourse(headCourse);break;
            case 2: selectCourse(rootSchool,head,headCourse);break;
            case 3: printOutStudentAllCourses(head,headCourse);
            case 4: CoursePassedAvgGrade(head);break; 
            case 5: CourseFailedAvgGrade(head);break;
            case 6: highestCourseAverage(head,headCourse);break;
            case 7: return;break; // CUANDO RETORNAMOS ESTAMOS CERRANDO ESTA FUNCIÓN Y NOS ESTAMOS DEVOLVIENDO A LA ANTERIOR QUE ESTÁ PENDIENTE.
            case 8: condicion=0;freeSchools(rootSchool);break;
            
            default:printf("\n\nInvalid Option.. Please Enter a valid number..\n\n") ;break;
        }
        
    

    }
     

}

 

void selectSchool(School*headSchool){
    if (headSchool==NULL){
        printf("\n\nNO HAY ESCUELAS DISPONIBLES....\n\n");
        return;
    }

    // print list of schools
    School*aux=headSchool;
    int i=0;
    printf("\n\n=== LIST OF SCHOOLS ===\n");
    while (aux!=NULL)
    {   printf("\n%d) Name: %s   ---   RIF: %d\n",i+1,aux->name,aux->rif);
        i++;
        aux=aux->next;
    }

    aux=headSchool;
    int rif;
    printf("\nEnter rif of the school : ");
    scanf("%d",&rif);
    getchar();

    while (aux!=NULL)
    {
        if (aux->rif==rif){
            schoolMenu(headSchool,aux);
            return; // CUANDO RETORNAMOS ESTAMOS CERRANDO ESTA FUNCIÓN Y NOS ESTAMOS DEVOLVIENDO A LA ANTERIOR QUE ESTÁ PENDIENTE.
        }
        aux=aux->next;

    }
    
    printf("\n\nSCHOOL NOT FOUND.... \n\n");
}



void mainMenu(){
    printf("\n\n=== BIENVENIDO AL CENTRO DE EDUCACION NACIONAL ===\n");

    School*head=NULL;
    int condicion=1;
    int option;
    while (condicion==1)
    {   printf("\n=========   OPTIONS ========\n");
        printf("\n1)Create School\n2)Select School\n3)Exit\n\nSelect Option: ");
        scanf("%d",&option);
        getchar();

        switch (option)
        {

            case 1: head=addNewSchool(head);break;
            case 2: selectSchool(head);break;
            case 3: condicion=0;freeSchools(head);break;
            
            default:printf("\n\nInvalid Option.. Please Enter a valid number..\n\n") ;break;
        }
    }

        
        
    
    





}






/*LA MAGIA QUE ME VA A PERMITIR IR Y VENIR ENTRE LOS DISTINTOS MENÚS ES QUE AL MOMENTO DE PASAR AL SIGUIETNE MENÚ
NO DEBO DE CORTAR LA FUNCIÓN ACTUAL, LO QUE ME PERMITIRÁ VOLVER LUEGO RETORNANDO LA FUNCIÓN A LA QUE ACCEDÍ POSTERIORMENTE.


ES COMO QUE CUANDO VOY DEL MENÚ 1 ---> MENÚ 2, EL MENÚ 1 SE QUEDA COMO EN ESPERA Y LUEGO SI RETORNO (CIERRO LA FUNCIÓN) 2
ME ESTÁ DEVOLVIENDO A LA FUNCIÓN 1.*/



