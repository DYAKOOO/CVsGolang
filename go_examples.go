
package main

import (
    "fmt"
    "unsafe"
)

// Built-in Types
func goBuiltinTypes() {
    var a int = 10
    var b string = "hello"
    var c []int = []int{1, 2, 3} // slice
    var d map[string]int = map[string]int{"one": 1, "two": 2} // map

    fmt.Println("Go Built-in Types:")
    fmt.Printf("a: %v (type %T)\n", a, a)
    fmt.Printf("b: %v (type %T)\n", b, b)
    fmt.Printf("c: %v (type %T)\n", c, c)
    fmt.Printf("d: %v (type %T)\n", d, d)
}

// Word Size
func goWordSize() {
    var a int
    fmt.Println("\nGo Word Size:")
    fmt.Printf("Size of int: %d bytes\n", unsafe.Sizeof(a))
}

// Zero Value Concept
func goZeroValue() {
    var a int
    var b string
    var c *int
    
    fmt.Println("\nGo Zero Value Concept:")
    fmt.Printf("a: %d\n", a)
    fmt.Printf("b: %q\n", b)
    fmt.Printf("c: %v\n", c)
}

// Conversion vs Casting
func goConversion() {
    var a int = 10
    var b float64 = float64(a)
    fmt.Println("\nGo Conversion:")
    fmt.Printf("a: %d (type %T)\n", a, a)
    fmt.Printf("b: %f (type %T)\n", b, b)
}

// Struct and Construction Mechanics
type Employee struct {
    ID        int
    Name      string
    Department string
    Salary    float64
}

func goStruct() {
    emp1 := Employee{Name: "Bob", Department: "Sales", ID: 102, Salary: 58000.00}
    emp2 := Employee{Name: "Charlie", Salary: 60000.00}
    
    fmt.Println("\nGo Struct and Construction:")
    fmt.Printf("emp1: %+v\n", emp1)
    fmt.Printf("emp2: %+v\n", emp2)
}

// Padding and Alignment
type Example struct {
    a byte
    b int32
    c byte
}

func goPadding() {
    ex := Example{}
    fmt.Println("\nGo Padding and Alignment:")
    fmt.Printf("Size of Example struct: %d bytes\n", unsafe.Sizeof(ex))
}

// Assigning Values
func goAssigning() {
    fmt.Println("\nGo Assigning Values:")
    a := 10 // Short variable declaration
    var b = 20 // Variable declaration with inferred type
    var c int = 30 // Variable declaration with explicit type
    fmt.Printf("a: %d, b: %d, c: %d\n", a, b, c)
}

// Pointers
func goPointers() {
    fmt.Println("\nGo Pointers:")
    var a int = 10
    var p *int = &a
    *p = 20
    fmt.Printf("a: %d, *p: %d\n", a, *p)
}

// Pass by Value
func goPassByValue() {
    count := 10
    fmt.Println("\nGo Pass by Value:")
    fmt.Printf("Before: count = %d\n", count)
    increment1(count)
    fmt.Printf("After increment1: count = %d\n", count)
    increment2(&count)
    fmt.Printf("After increment2: count = %d\n", count)
}

func increment1(inc int) {
    inc++
}

func increment2(inc *int) {
    *inc++
}

// Escape Analysis
func goEscapeAnalysis() {
    fmt.Println("\nGo Escape Analysis:")
    u1 := stayOnStack()
    u2 := escapeToHeap()
    fmt.Printf("u1: %v\n", u1)
    fmt.Printf("u2: %v\n", u2)
}

type user struct {
    name string
    email string
}

func stayOnStack() user {
    u := user{name: "Bill", email: "bill@email.com"}
    return u
}

func escapeToHeap() *user {
    u := user{name: "Bill", email: "bill@email.com"}
    return &u
}

// Constants
const (
    ui = 12345            // Untyped integer
    uf = 3.141592         // Untyped float
    ti int = 12345        // Typed integer
    tf float64 = 3.141592 // Typed float
)

func goConstants() {
    fmt.Println("\nGo Constants:")
    fmt.Printf("ui: %v (type %T)\n", ui, ui)
    fmt.Printf("uf: %v (type %T)\n", uf, uf)
    fmt.Printf("ti: %v (type %T)\n", ti, ti)
    fmt.Printf("tf: %v (type %T)\n", tf, tf)
}

// IOTA
const (
    A = iota
    B
    C
    D = iota << 2
    E
)

func goIota() {
    fmt.Println("\nGo IOTA:")
    fmt.Printf("A: %d, B: %d, C: %d, D: %d, E: %d\n", A, B, C, D, E)
}

func main() {
    goBuiltinTypes()
    goWordSize()
    goZeroValue()
    goConversion()
    goStruct()
    goPadding()
    goAssigning()
    goPointers()
    goPassByValue()
    goEscapeAnalysis()
    goConstants()
    goIota()
}