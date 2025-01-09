typedef struct Student{
    int record;
    char name[50];
    int id;
    struct Student*next; // Points to the next Student.


}Student;


typedef struct Course
{   
    char name[50];
    int nrc;
    int averageGrade;
    Student*students; // Students Linked List
    struct Course*next; // Point to the next Course
    
    
}Course;



typedef struct School
{       char name[50];
        int rif;
        Course*courses; // Courses Linked List
        struct School*next;
        
}School;








