#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void Error(const char* message){
    fprintf(stderr, "[Error]: %s\n", message);
    exit(1);
}

int main(void)
{
//We Use Variable for Saving Data(Saved in Computer memory)
//Each Varaible has "Data Type"

//* : frequently Used
    char char_value = 'A'; //*
    short short_value;
    long long_value;
    int int_value = 2024; //*
    long long long_long_value;
    float float_value;
    double double_value = 2024.2024; //*
    long double long_double_value;

//notice: When declare variable, it is good to initialize

//char is abbreviation of charater, so we can represent text using char data type
//it's value follow ASCII Code
    printf("char: %c\n", char_value);
    printf("int : %d\n", int_value);
    printf("double : %.4lf\n\n", double_value);

//We Can Check how each data type use memory using "sizeof" function
    printf("char's Size: %d\n", sizeof(char_value));
    printf("short's Size: %d\n", sizeof(short_value));
    printf("long's Size: %d\n", sizeof(long_value));
    printf("int's Size: %d\n", sizeof(int_value));
    printf("long long's Size: %d\n", sizeof(long_long_value));
    printf("float's Size: %d\n", sizeof(float_value));
    printf("double's Size: %d\n", sizeof(double_value));
    printf("long double's Size: %d\n\n", sizeof(long_double_value));

//Each Data Type has Limits
//Some Frequently used data type's limits are defined for variable in "limits" header file
    printf("char MAX: %d,\t char MIN: %d\n", CHAR_MAX, CHAR_MIN);
    printf("short MAX: %d,\t short MIN: %d\n", SHRT_MAX, SHRT_MIN);
    printf("int MAX: %d,\t int MIN: %d\n\n", INT_MAX, INT_MIN);

//If we over that limits, that data type cause "Over Flow"
//If you want to know the reason of Over Flow, Reference Calculation.C in my github
    printf("int OverFlow: %d,\t int MIN: %d\n\n", INT_MAX + 1, INT_MIN);


//We Can Sheave Each Data Type, And We Call that bunch for "array"
//array make easy to use loop
//Bunch of Alphabet is string -> We can use char's array for representing string
    char array_char[10] = "ARRAY";
    int array_int[10];
    double array_double[10];

//And array's index start from "0" not 1
    printf("Example: ");
    for(int i = 0; array_char[i] != '\0'; i++)
        printf("%c", array_char[i]);
    printf("\n\n");

//Whenever you learn array in C based langauge, You will learn "pointer" together
//Pointer is main concept of C
//Everything in Computer has address and pointer is variable that can be pointing address
//We can declare pointer using "*"
    char* char_pointer = &char_value;
    int* int_pointer = &int_value;
    double* double_pointer = &double_value;

//Despite pointer has data type, but memory size is same.
//And then why pointer has data type? -> Cause "DeReference"
    *char_pointer = 'B';
    *int_pointer = 2025;
    *double_pointer = 2025.2025;

    printf("char: %c,\t size: %d\n", *char_pointer, sizeof(char_pointer));
    printf("int: %d,\t size: %d\n", *int_pointer, sizeof(int_pointer));
    printf("double: %.4lf,\t size: %d\n\n", *double_pointer, sizeof(double_pointer));

//And then why array and pointer learn together?
//Cause we Can use pointer for array using dynamic memory allocation
    char_pointer = NULL;

    char_pointer = (char*)malloc(10 * sizeof(char));
    if(char_pointer == NULL)
        Error("Failed to Allocate Memory");

    if(strncpy(char_pointer, "ARRAY", 10) == NULL)
        Error("Failed to Copy String");
    
    printf("array using pointer example: %s\n\n", char_pointer);

    free(char_pointer); //After using memory, must be free


//Array is bunch of same data type
//And then how we use bunch of other data type? -> struct, union

//struct [struct name]{ declare }[variable name];
//usage = [variable name].[declared variable in struct]
//struct's memroy size = sum of declared variable's memory in struct
    struct S_TEST{
        char sc_test[5] = "TEST";
        int si_test = 2025;
        double sd_test = 2025.2025;
    }s_test;
    
    printf("struct example: %s\n", s_test.sc_test);
    printf("%d\n", s_test.si_test);
    printf("%.4lf\n", s_test.sd_test);
    printf("size: %d\n\n", sizeof(S_TEST));

//And using struct pointer, you can access struct value

    S_TEST* S_POINTER = &s_test;

    printf("struct pointer example: %s\n", S_POINTER->sc_test);
    printf("%d\n", S_POINTER->si_test);
    printf("%.4lf\n", S_POINTER->sd_test);
    printf("size: %d\n\n", sizeof(S_POINTER));  //Memory saving

//Only one variable can be initialized
//why use union type? -> Check endian (little endian or big endian) {The Way of Storing number in Memory}
//union [union name]{ declare }[variable name];
//usage = [variable name].[declared variable in union]
//union's memory size = most biggest variable's memory in union
    
    union U_TEST{
        char uc_test;
        int ui_test = 10;
    }u_test;

    printf("union size: %d\n\n", sizeof(U_TEST));

//array, function, struct, union's name is pointer
    printf("array's address: %#x\n", array_int);
    printf("function's address: %#x\n", printf);
    printf("struct's address: %#x\n", s_test);
    printf("union's address: %#x\n\n", u_test);

//There are default data types.
//At one day, You can make abstract data type (a.k.a ADT) using this default data types like STACK, QUEUE, etc...

//If You Any Question about this Source Code, Please Contact to me
//mail : yeskwon05@dgu.ac.kr

    return 0;
}