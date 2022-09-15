# 2 - CPP data-types
Some data types in C are:
* Integers:
  * signed or unsigned
  * int (implementation dependent)
  * char (a byte)
  * stdint.h contains portable types like uint32_t
* Floats (ieee754):
  * float
  * double
  * long double
* Boolean:
  * bool: true|false, true=1, false=0
* Strings (provided in <string>, not natively supported)
  * <string> has the string datatype
  * <cstring> has lots of string methods
  * strings are not natively supported
* Pointers
  * like in C

Literals:
* hex: start with '0x'
* bin: start with '0b'
* unsigned: end with 'u' or 'U'
* float: contain decimal and ending with 'f'
* double: like float but without 'f'

Stack area of mem: non-global variables
Data area of mem: global variables

Bitwise operations:
* & bitwise and 
* | bitwise or 
* ~ bitwise not
* ^ bitwise xor
  
Pointer operations: Like C
* dereference operator: *
* 'address of' operator: &
* to get members of struct: ->

type inference using auto
* e.g. auto c = 44.1f; auto a = 'd';
* typeid(c).name() returns "float"

The const qualifier
* used to declare constant
* scope encapsulation is enforced
* declarations specify a type
* const is not the same in c and c++