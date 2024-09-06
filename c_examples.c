
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Built-in Types
void cBuiltinTypes() {
    int a = 10;
    char* b = "hello";
    int c[] = {1, 2, 3}; // array, not slice
    
    printf("C Built-in Types:\n");
    printf("a: %d (type int)\n", a);
    printf("b: %s (type char*)\n", b);
    printf("c: [%d, %d, %d] (type int[])\n", c[0], c[1], c[2]);
    // No direct equivalent for maps
}

// Word Size
void cWordSize() {
    int a;
    printf("\nC Word Size:\n");
    printf("Size of int: %lu bytes\n", sizeof(a));
}

// Zero Value Concept (C doesn't have this, showing uninitialized behavior)
void cZeroValue() {
    int a;
    char* b;
    int* c;
    
    printf("\nC 'Zero Value' (uninitialized):\n");
    printf("a: %d\n", a);
    printf("b: %p\n", (void*)b);
    printf("c: %p\n", (void*)c);
}

// Casting
void cCasting() {
    int a = 10;
    float b = (float)a;
    printf("\nC Casting:\n");
    printf("a: %d (type int)\n", a);
    printf("b: %f (type float)\n", b);
}

// Struct and Construction
struct Employee {
    int ID;
    char Name[50];
    char Department[50];
    float Salary;
};

void cStruct() {
    struct Employee emp1 = {.Name = "Bob", .Department = "Sales", .ID = 102, .Salary = 58000.00};
    struct Employee emp2 = {.Name = "Charlie", .Salary = 60000.00};
    
    printf("\nC Struct and Construction:\n");
    printf("emp1: ID=%d, Name=%s, Department=%s, Salary=%.2f\n", 
           emp1.ID, emp1.Name, emp1.Department, emp1.Salary);
    printf("emp2: ID=%d, Name=%s, Department=%s, Salary=%.2f\n", 
           emp2.ID, emp2.Name, emp2.Department, emp2.Salary);
}

// Padding and Alignment
struct Example {
    char a;
    int b;
    char c;
};

void cPadding() {
    struct Example ex;
    printf("\nC Padding and Alignment:\n");
    printf("Size of Example struct: %lu bytes\n", sizeof(ex));
}

// Assigning Values
void cAssigning() {
    printf("\nC Assigning Values:\n");
    int a = 10;
    int b = 20;
    int c = 30;
    printf("a: %d, b: %d, c: %d\n", a, b, c);
}

// Pointers
void cPointers() {
    printf("\nC Pointers:\n");
    int a = 10;
    int* p = &a;
    *p = 20;
    printf("a: %d, *p: %d\n", a, *p);
    p++; // Allowed in C, not in Go
    printf("p after increment: %p\n", (void*)p);
}

// Pass by Value
void increment1(int inc) {
    inc++;
}

void increment2(int *inc) {
    (*inc)++;
}

void cPassByValue() {
    int count = 10;
    printf("\nC Pass by Value:\n");
    printf("Before: count = %d\n", count);
    increment1(count);
    printf("After increment1: count = %d\n", count);
    increment2(&count);
    printf("After increment2: count = %d\n", count);
}

// Manual Memory Management (instead of Escape Analysis)
struct User {
    char name[50];
    char email[50];
};

struct User stayOnStackC() {
    struct User u = {"Bill", "bill@email.com"};
    return u;
}

struct User* escapeToHeapC() {
    struct User* u = malloc(sizeof(struct User));
    strcpy(u->name, "Bill");
    strcpy(u->email, "bill@email.com");
    return u;
}

void cManualMemory() {
    printf("\nC Manual Memory Management:\n");
    struct User u1 = stayOnStackC();
    struct User* u2 = escapeToHeapC();
    printf("u1: name=%s, email=%s\n", u1.name, u1.email);
    printf("u2: name=%s, email=%s\n", u2->name, u2->email);
    free(u2);
}

// Constants
#define UI 12345
#define UF 3.141592
const int TI = 12345;
const double TF = 3.141592;

void cConstants() {
    printf("\nC Constants:\n");
    printf("UI: %d\n", UI);
    printf("UF: %f\n", UF);
    printf("TI: %d\n", TI);
    printf("TF: %f\n", TF);
}

// Enum (similar to IOTA)
enum {
    A = 0,
    B,
    C,
    D = 4,
    E
};

void cEnum() {
    printf("\nC Enum (similar to IOTA):\n");
    printf("A: %d, B: %d, C: %d, D: %d, E: %d\n", A, B, C, D, E);
}

int main() {
    cBuiltinTypes();
    cWordSize();
    cZeroValue();
    cCasting();
    cStruct();
    cPadding();
    cAssigning();
    cPointers();
    cPassByValue();
    cManualMemory();
    cConstants();
    cEnum();
    return 0;
}