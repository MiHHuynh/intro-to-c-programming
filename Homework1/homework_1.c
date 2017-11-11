//C language does not allow you to have more than one main in one application
//So, when you are writing your midterm, you may run into situation that you have to
//create multiple project for each problem in the homework.
//That could get out of hand

//So, here is a solution which you can use.  This solution uses functions.  Though I use functions
//later, but, for now, just copy the methodlogies which should help you.  You will learn
//about writing functions in details in coming days

//Say, you are writing homework #1
//Name the file as homework_1.c

//now write the code like this
#include <stdio.h>

//this is problem 1.2 - What would you need to change if I 
//asked you to display “Welcome” in one line and “to the class 
//of C Beginners” in another line? 
void problem_2(){
    printf("Welcome\nto the class of C beginners\n");
}

//this is problem 1.3 to print out HELLO
void problem_3(){
    //your code goes here
    printf("***\t  ***\t********\t***\t\t***\t\t    ***\n");
    printf("***\t  ***\t***\t\t***\t\t***\t\t***\t***\n");
    printf("***\t  ***\t***\t\t***\t\t***\t\t***\t***\n");
    printf("*************\t********\t***\t\t***\t\t***\t***\n");
    printf("***\t  ***\t***\t\t***\t\t***\t\t***\t***\n");
    printf("***\t  ***\t***\t\t***\t\t***\t\t***\t***\n");
    printf("***\t  ***\t********\t********\t********\t    ***\n");
}

//this is problem 1.4 to print a box
void problem_4(){
    printf("--------------------\n");
    printf("|                  |\n");
    printf("|                  |\n");
    printf("|                  |\n");
    printf("|                  |\n");
    printf("|                  |\n");
    printf("|                  |\n");
    printf("|                  |\n");
    printf("|                  |\n");
    printf("--------------------\n");
}

int main (void){
    
    problem_2();   //call the function problem_1, where you will write the code for problem#1
    problem_3();   //call the function problem_2, where you will write the code for problem#1
    problem_4();   //call the function problem_3, where you will write the code for problem#1
    
    return 0;
}