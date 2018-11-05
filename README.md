Source :  
C++ 11 Tour For experienced programmers : 

- https://isocpp.org/tour

Whats new in c++ : 
- http://www.stroustrup.com/C++11FAQ.html

Also :http://www.cplusplus.com/doc/tutorial/



**Compiler on MacOS** :

- gpp : does not support c++11
- use `clang++ -std=c++11 -stdlib=libc++` to compile C++11 code.
- Web REPL: https://repl.it/repls/AdoredSuspiciousModem



**Console Reading and writting** 

```c++
std::cout << "Proceed ? y/n" << std::endl;

char input = 0;
std::cin  >> input;

if(input == 'n'){
    std::cout << "You said no" << std::endl;
}else if(input =='y'){
    std::cout << "You said yes" << std::endl;
}else{
    std::cout << "What the hello did you say ?" << std::endl;
}

// Reading a string from console
std::string user_input;
std::getline(std::cin, user_input);
std::cout << "You said "<< user_input << std::endl;

// std::endl is same as "\n" for most of time
```



# Variables and Types

**Fundamental variable types :**

- bool
- char
- int
- double



**Variable type and memory size** 

- dependent on platform
- char and bool occupies same size (typically 4 bits or 1 byte)
- int occupies four times of char (typically four bytes)
- double occupies two times of int (typically eight bytes)



**Curly braces** 

- curly braces are recommended over assignment operator
- defining using curly braces : `double d {2.3}`
- curly braces don't loose info on type conversion



**auto**

- auto allows auto deduction of value based on declaration

  `auto age = 21`

  `auto height {2.3f}`

- It is okay to use `=` with auto, because now we cannot have problem with type conversion which is automatic

  ```c++
  auto 
      a = 1, 
  	b = 7,
  	*c = &a;
  // valid
  
  auto 
      a = 1, 
      b = 7,
      c = 'h';
  // error: inconsistent deduction for 'auto': 'int' and then 'char'
  ```


**const**

- **const** : value wont change at runtime

- **constexpr** : value will be evaluated at compile time itself

  - better performance (code branching)

- To be constexpr a function must be rather simple: just a return statement computing a value. A constexpr function can be used for non-constant arguments, but when that is done the result is not a constant expression. We allow a constexpr function to be called with non-constant-expression arguments in contexts that do not require constant expressions, so that we don’t have to define essentially the same function twice: once for constant expres- sions and once for variables. 

  In a few places, constant expressions are required by language rules (e.g., array bounds (§2.2.5, §7.3), case labels (§2.2.4, §9.4.2), and some template arguments (§25.2). In other cases, compile-time evaluation is important for performance. Independently of perfor- mance issues, the notion of immutability (of an object with an unchangeable state) is an important design concern (§10.4). 

**array**

- declared with fixed length expression :  `int values[6] = {11, 22, 33, 44, 55, 66}`
- cant be auto auto : **~~int values[6] = {11, 22, 33, 44, 55, 66}~~**
- size comes after the variable name **~~int[6] values = {11, 22, 33, 44, 55, 66}~~**
- calculate length with sizeof : `sizeof(values)`
- 

**pointers**

- Pointers hold the address of an object of appropriate type: 
- dereferncing : `*p ` i.e. getting value from a pointer 

```c++
  char a[6] = "hello";
  char *p;
  p = &a[1];

// a  = hello
// *p = e
// p = ello
```

- **reference`&` vs pointer `*`** :

  - `T* p` is same as `T& p` , only difference is we dont need to use `*` to get the value of pointed location.

- **nullptr**

  - represents a pointer pointing to no memory locatoin

  - same **nullptr** value is shared by **all pointer types**

  - check as **`ptr == nullptr`**

  - in older c++ code, NULL is used instead of nullptr (just convention)

  - ```c++
    #include <iostream>
    using namespace std;
    
    int main ()
    {
      int numbers[5];
      int * p;
      p = numbers;  *p = 10;
      p++;  *p = 20;
      p = &numbers[2];  *p = 30;
      p = numbers + 3;  *p = 40;
      p = numbers;  *(p+4) = 50;
      for (int n=0; n<5; n++)
        cout << numbers[n] << ", ";
      return 0;
    }
    
    // Output 10, 20, 30, 40, 50, 
    ```

- **offset operator**

  - **`*(p+5)`is same as `p[5]`**

  - arrays variable are very much like pointer variables, but can't be assigned a new address other than that of the first memory location of array object that they point to

  - increment has a higher precedence over `*` operator, i.e.

  - ```
    *p++   // same as *(p++)
    *++p   // same as *(++p)
    ++*p   // same as ++(*p)
    (*p)++ // post-increment the value it points to 
    
    ```

  - 

- **constant pointers**

  - `cosnt int* p1` is not same as `int* const p1`

  - `cosnt int* p1` tells that pointer points to a constant value (cant write to memory location)

  - `int * const p1` declares that this pointer variable will always hold the same address

  - ***if a variable is const, then pointer has to be read-only to hold a referernce to it***

      ```c++
        const int var = 101;
        const int * cp = &var; // valid
        int * pc = &var; 		 // ERROR 
        int * const pc = &var; // ERROR
      ```


- **Pointer to strings**

  - string literals are arrays with null-terminated (`\0`) char sequence

    ```
       const char* message = "hello i am nishant";
       std::cout << message << std::endl;      // hello i am nishant
       std::cout << (message + 6) << std::endl;// i am nishant
    ```

- **pointer to pointer** 

  ```c++
  char a;
  char * b;
  char ** c; // Pointer to pointer
  a = 'z';
  b = &a;
  c = &b;
  ```


  - **void pointer**


      - void means absence of a type
      - void pointers point to a memory locatoin, irrsepective of type of data
      - hence can't be derefernced without typecasting.

- **pointers to functions**


  - defined as `<return-type> (*var_name) (args...)`

  - can refernce a function and invoked like a regular function name

    ```c++
    int perform(int value, int (*callback)(int)){
      return callback(value) ;
    }
    
    int increment(int val){
        return val+1;
    }
    
    int main() {
      int (*method_pntr)(int) = increment;
      std::cout << perform(100, method_pntr) << std::endl;
    }
    
    ```



**for loops**

```

```



# Questions

- What is the result of `*p++ = *q++;`

  - this is equivalent of 

  	```c++
      *p = *q; // value at addres p is copied from value at q
      p++;     // p points to next memory location
      q++;     // q pointe to next memory location
    ```

- What is a const pointer ?
  - (read-only pointer) pointer that can read the memory it points to, but cannot write to it
  - `const int *p = &var;`
  - if var is const, it can only be pointed to by a const pointer type
  - good application is in method signature : `void print_all (const int* start, const int* stop)`

- What is pointer to a const ?

  ```c++
    const int var = 101;
    const int * cp = &var;
      // cp = cp +1; // valid
    // *cp = 102; // error: assignment of read-only location
  
    // int * const pc = &var; // error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
  
   // *pc = 102; // error: invalid conversion from 'const int*' to 'int*'
    
  ```



  ```c++
   int var = 101;
   int * const pc = &var; // valid
  
   *pc = 102; // error: invalid conversion from 'const int*' to 'int*'
  
   pc = pc +1; //error: assignment of read-only variable 'pc'
  ```
