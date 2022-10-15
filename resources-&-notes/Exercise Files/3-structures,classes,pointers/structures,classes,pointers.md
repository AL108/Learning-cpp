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
````
#ifndef HEADER_H
#define HEADER_H
    //includes and macros here
#endif 
````