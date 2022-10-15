# structures
like C

# enums
like C

# classes
same idea as python, java classes\
e.g.:
```
class cow {
public:
    cow(string name_, int age_, unsigned char_ purpose) {
        name=name_;
        age=age_;
        purpose=purpose_;
    }

private:
    string name;
    int age;
    unsigned char purpose;

public:
    string get_name() {
        return name
    }
};
```
# pointers
  *: dereference/indirection operator
  &: address operator


# c/cpp compilation process
compiler(converts source files to assembly) ->\
assembler(converts assembly files to object files) ->\
linker (links object files) ->\
final form: executable binary file

# header file and implementation file
- header files contain class definitions and function declarations and macros
- implementation files contain executable code
- implementation files must include their header files
- don't forget to use a header guard e.g.
- `using` keyword should not be used in header files
- 
````
#ifndef HEADER_H
#define HEADER_H
    //includes and macros here
#endif 
````
## #pragma once
From wikip:
In c and cpp, #pragma once is a non-standard but 
widely supported preprocessor directive designed
to cause the current source file to be included
once only in a single compilation. Thus #pragma
once serves the same purpose as include guards, 
but with several advantages including: less code, 
avoidance of name clashes, and somtimes 
improvement in compilation speed. 

It is not available on all compilers.


# static/dynamic memory areas
Dynamic/heap memory can be allocated like in C
with malloc. In addition there is a ```new```
operator which which we can allocate
objects to the heap. e.g.
````
car_a = new car("Hatchback",4) // returns pointer

````
'car->type' is like in C, i.e. gets whatever is stored at pointer 'car'.

# References vs pointers
They are aliases to existing variables. 
e.g. 
````
int& my_ref = my_int
```` 

- Pointers don't have to be initalised, whereas refrences must be initisliased
- A pointer can reference different objects, whereas a reference always references the object that it was first initialised to.
- A pointer can be void and NULL, whereas references have fixed type and object
- A pointer can have multiple levels of indirection, whereas a reference can only have one level of indirection (to the object initialised to)
- Applications of references include:
    - Passing paramters by reference
    - Avoid copying large objects as function parameters (program uses less space)
    - Avoid copying large objects in for loops (program uses less space)

# Standard Template Library (STL) Vectors
- They are dynamic-size containers
- Memory is managed for you
- Generic container class
- Part of the cpp standard template librarya
- vectors have front () and back (.pushback(e)

e.g.
```
vector<int> numbers;
vector<person> people;
```
## Iterators
A pointer is a type of iterator
To get iterator object to first element of vector, 
we can use .begin().

