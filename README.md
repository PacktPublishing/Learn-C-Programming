# Learn C Programming

<a href="https://www.packtpub.com/programming/learn-c-programming-fundamentals-of-c?utm_source=github&utm_medium=repository&utm_campaign=9781789349917"><img src="https://packt-type-cloud.s3.amazonaws.com/uploads/sites/2925/2020/06/cover.png" alt="Learn C Programming" height="256px" align="right"></a>

This is the code repository for [Learn C Programming](https://www.packtpub.com/programming/learn-c-programming-fundamentals-of-c?utm_source=github&utm_medium=repository&utm_campaign=9781789349917), published by Packt.

**A beginner's guide to learning C programming the easy and disciplined way**

## What is this book about?
C is a powerful general-purpose programming language that is excellent for beginners to learn. This book will introduce you to computer programming and software development using C. If you're an experienced developer, this book will help you become familiar with the C programming language.


This book covers the following exciting features:
Understand fundamental programming concepts and implement them in C 
Write working programs with an emphasis on code indentation and readability 
Break existing programs intentionally and learn how to debug code 
Adopt good coding practices and develop a clean coding style 
Explore general programming concepts that are applicable to more advanced projects 
Discover how you can use building blocks to make more complex and interesting programs 
Use C Standard Library functions and understand why this is desirable

If you feel this book is for you, get your [copy](https://www.amazon.com/dp/1789349915) today!

<a href="https://www.packtpub.com/?utm_source=github&utm_medium=banner&utm_campaign=GitHubBanner"><img src="https://raw.githubusercontent.com/PacktPublishing/GitHub/master/GitHub.png" 
alt="https://www.packtpub.com/" border="5" /></a>

## Instructions and Navigations
All of the code is organized into folders. For example, Chapter02.

The code will look like the following:
```
#include <stdio.h>

int main()
{
    printf( "Hello, world!\n" );
    return 0;
}
```

## Errata

* Section “Memory Leaks” on page 410: The sentence "First, the free() function is called on pThing1, which is the pointer element of pThing2. Then, and only then, can we release the memory of pThing1." must read as "First, the free() function is called on pThing1->pThing2, which is the pointer element to pThing2. Then, and only then, can we release the memory of pThing1."
* Page no. 20: The sentence "The way in which one v sends text to the console is likely different from any other OS, even if they both run on the same hardware." must read as "The way in which one sends text to the console is likely different from any other OS, even if they both run on the same hardware."
* Page no. 42: It is mentioned that "Four keywords we have already encountered are include, int, main, and return." but main() is not a keyword; it is a token.
* Page no. 51: The sentence "Your program can never call main itself; main can only be called by the system." must read as "Your program can call main() again itself but this is a very unwise practice."
* Page no. 55: The sentence "A function can be values given as input to the function." must read as "A function can have values given as input to the function."
* Page no. 121: Page 121 example code
It is:
```
      printf( "  Final: %\n" , aValue );
...
     printf( "  Final: %\n" , aValue );
```
Should be:
```
printf( "  Final: %d\n\n" , aValue );
...
printf( "  Final: %d\n\n" , aValue );
```
* Page no. 121: Page 121 prefixpostfix.c running result
It is:
```
++aValue (alone) == 7
aValue++ (alone) == 8
```

Should be:
```
++aValue (alone) == 6
aValue++ (alone) == 6
```
* Page no. 121: The sample program is given as
 ```
    // A more predictable result: increment in isolation.
  ++aValue;
  printf( "++aValue (alone) == %d\n" , aValue );
  aValue++;
  printf( "aValue++ (alone) == %d\n" , aValue );
 ```
but this should be
```
    // A more predictable result: increment in isolation.
  aValue = 5;
  ++aValue;
  printf( "++aValue (alone) == %d\n" , aValue );
  aValue = 5;
  aValue++;
  printf( "aValue++ (alone) == %d\n" , aValue );
  ```
  * Chapter 12, page 250:
  ```
  const int size1D = 5;
  const int size2D = 4;
  const int size3D = 3;
  const int size4D = 7;
  ```
  The above four statements could and should be written as enums, as follows:
 ```
  enum {
    size1D = 5,
    size2D = 4,
    size3D = 3,
    size4D = 7
  };
  ```
It could also have been declared
 ```
  #define size1D 5
  #define size2D 4
  #define size3D 3
  #define size4D 7
```
* Page 192: The code block after "Alternatively, we could write a function that adds two cards, as follows:" is:
```
int sumCards( struct Card c1 , struct Card c2 ) {
  int faceValue = c1.faceFalue + c2.faceValue;
  return faceValue;
}
```
It should be:
```
int sumCards( struct Card c1 , struct Card c2 ) {
  int faceValue = c1.faceValue + c2.faceValue;
  return faceValue;
}
```

**Following is what you need for this book:**
This book is written for two very diverse audiences.
If you're an absolute beginner who only has basic familiarity with operating a computer, this book will help you learn the most fundamental concepts and practices you need to know to become a successful C programmer.
If you're an experienced programmer, you'll find the full range of C syntax as well as common C idioms. You can skim through the explanations and focus primarily on the source code provided.

With the following software and hardware list you can run all code files present in the book (Chapter 1-25).
### Software and Hardware List
| Chapter | Software required | OS required |
| -------- | ------------------------------------ | ----------------------------------- |
| 1-25 | GCC/Clang/Cygwin/MinGW | Windows, Mac OS X, and Linux (Any) |

We also provide a PDF file that has color images of the screenshots/diagrams used in this book. [Click here to download it](https://static.packt-cdn.com/downloads/9781789349917_ColorImages.pdf).

### Related products
*  Practical C Programming [[Packt]](https://www.packtpub.com/programming/c-programming-cookbook?utm_source=github&utm_medium=repository&utm_campaign=) [[Amazon]](https://www.amazon.com/dp/1838641106)

*  Extreme C [[Packt]](https://www.packtpub.com/programming/extreme-c?utm_source=github&utm_medium=repository&utm_campaign=) [[Amazon]](https://www.amazon.com/dp/1789343623)

## Get to Know the Author
**Jeff Szuhay**
is the principal developer at QuarterTil2 which specializes in graphics-rich software chronographs for desktop environments. In his software career of over 35 years, he has engaged in the full range of development activities from systems analysis and systems performance tuning to application design, from initial development through full testing and final delivery.
Throughout that time, he has taught computer applications and programming languages at various educational levels from elementary school students to university students, as well as developed and presented professional, on-site training.

### Suggestions and Feedback
[Click here](https://docs.google.com/forms/d/e/1FAIpQLSdy7dATC6QmEL81FIUuymZ0Wy9vH1jHkvpY57OiMeKGqib_Ow/viewform) if you have any feedback or suggestions.


### Download a free PDF

 <i>If you have already purchased a print or Kindle version of this book, you can get a DRM-free PDF version at no cost.<br>Simply click on the link to claim your free PDF.</i>
<p align="center"> <a href="https://packt.link/free-ebook/9781789349917">https://packt.link/free-ebook/9781789349917 </a> </p>