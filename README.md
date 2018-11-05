
Source :  
C++ 11 Tour For experienced programmers : 
- https://isocpp.org/tour

Whats new in c++ : 
- http://www.stroustrup.com/C++11FAQ.html

Also :http://www.cplusplus.com/doc/tutorial/



**Compiler on MacOS** :

- gpp : does not support c++11
- use `clang++ -std=c++11 -stdlib=libc++` to compile C++11 code.



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

**const**

- const : value wont change at runtime

- **constexpr** : value will be evaluated at compile time itself

  - better performance 

- To be constexpr a function must be rather simple: just a return statement computing a value. A constexpr function can be used for non-constant arguments, but when that is done the result is not a constant expression. We allow a constexpr function to be called with non-constant-expression arguments in contexts that do not require constant expressions, so that we don’t have to define essentially the same function twice: once for constant expres- sions and once for variables. 

  In a few places, constant expressions are required by language rules (e.g., array bounds (§2.2.5, §7.3), case labels (§2.2.4, §9.4.2), and some template arguments (§25.2). In other cases, compile-time evaluation is important for performance. Independently of perfor- mance issues, the notion of immutability (of an object with an unchangeable state) is an important design concern (§10.4). 

