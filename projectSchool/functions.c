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
    getchar();
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
    while (head!=NULL)
    {
        cont++;
        head=head->next;
    }
    return cont;


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
    
    printf("\n\n======== %s Students ========\n\n",headCourse->name);
    int i=0;
    while (head!=NULL){
        printf("%d)Name : %s  --- Record : %d --- ID : %d \n",i+1,head->name,head->record,head->id);
        head=head->next;
        i++;
    }
}

void courseDetails(Course*course){
    printf("\n\n====  Course  ===\n\n");
    course->averageGrade=averageGrade(course->students);
    printf("Name: %s --- Average Grade : %d --- NRC : %d \n",course->name,course->averageGrade,course->nrc);
    printf("\nStudents: \n");
    studentsDetails(course ,course->students);


}

void schoolDetails(School*head){
    if (head==NULL){
    printf("\n\nSchool NOT Found...\n\n");
    return;
    }

    while (head!=NULL)
    {

    }
    

    


}





// Check if a course exists at the school.
void CheckCourse(Course*head,int NRC){
    if (head==NULL){
        printf("\n\nSchool without Courses...\n\n");
        return;
    }

    while (head!=NULL)
    {
        if (head->nrc==NRC){
            courseDetails(head);
            return;
        }
        head=head->next;
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
        printf("\n\n====    Escuela : %s  ====\n\n",aux->name);
        headSchool=headSchool->next;
        freeCourses(aux,aux->courses);
        free(aux);
    }
    


}



void FailedStudents();
void PassedStudents();
void courseMenu();
void schoolMenu();