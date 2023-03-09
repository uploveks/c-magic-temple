# The Magic Temple
Welcome to the Magic Temple, a mini-program that features various tasks related to string manipulation, ciphers, and simple 2-gram analysis.

The program is divided into three main parts:

- **Magic Words** - In the first room of the temple, you will find a matrix of NxM dimension. Your task is to traverse the matrix to get to the next room. However, the right path is encoded, and you must decode it by analyzing the codes written on the temple's walls. The codes have a small pattern, and they start with letter a, b, or c. Your goal is to decode these codes by following the rules provided in the problem statement, and then print your way on the temple's wall for the next person who will enter the temple. You can find the source code for this task in **magic_words.c**.

- **Magic Ciphers** - In the second room of the temple, you will hear a strange voice speaking strange words. You realize that the words are encrypted, and your task is to decipher them. The encryptions used in this task are Caesar cipher, Vigenere cipher, and basic arithmetic operations. Your goal is to find all the right messages by analyzing the input data provided, and if you succeed, the voice will open the door to the next room. You can find the source code for this task in **magic_ciphers.c**.

- **Two Grams** - In the third and final room of the temple, you will find unencrypted text on the floor, and the voice will tell you that if you can help it find the set of all two-grams and print their frequency in the text, you will be free to leave the magic temple with the biggest prize ever. Your goal is to find all the two-grams in the text and print their frequency. You can find the source code for this task in **two_grams.c**.
## Table of Contents

1. [About the project](#start-description)
2. [Building and Testing](#build-description)

<a name="start-description"></a>
## About the project

This project aims to demonstrate string manipulation, cipher decryption, and simple 2-gram analysis. It includes a set of mini-programs, each focusing on one of these aspects. The project is divided into three parts: magic words, magic ciphers, and two-grams.


### **Magic Words**

In the first part, the user enters the magic temple and comes across a matrix of NxM dimensions. The objective is to traverse the matrix and move to the next room, but the right path is encoded, and the user must decode it. The codes on the temple walls have a small pattern.

* Some codes start with the letter "a" and have the form "aQ1Q2Q3Q4," where Q_i is a digit. The maximum number from these four will dictate the next moving step.
    *Q1-right
    *Q2-up
    *Q3-left
    *Q4-down
* Some codes start with the letter "b" and have the form "bQ1Q2...Qn," where Q_i is a digit.

    * If MOV_1 is a palindrome and MOV_2 is prime, the user moves to the left. 
    * If MOV_1 is a palindrome and MOV_2 is not prime, the user moves to the right. 
    * If MOV_1 is not palindrome and MOV_2 is prime, the user moves up. 
    * If MOV_1 is not palindrome and MOV_2 is not prime, the user moves down. 
* Some codes start with the letter "c" and have the form "cNKQ1Q2...Qn," where Q_i is a digit. The SUM of Q0 + QK + Q2K + ... + QK-1K (numbers are selected circularly from K to K) and N is the number of Q's. 
    * If SUM % 4 = 0, the user moves to the left. 
    * If SUM % 4 = 1, the user moves up.
    * If SUM % 4 = 2, the user moves right. 
    * If SUM % 4 = 3, the user moves down. 
After all the codes are processed, the user must print their way on the magic temple wall for the next person that will step in the magic temple.


### **Magic Ciphers**

In the second part, the user enters the second room and hears a strange voice. The words are encrypted, and the encryptions are Caesar, Vigenere, and sometimes the user must add the decoded messages. If the user finds all the right messages, the strange voice will open the door for the next room.


### **Two Grams**

In the third part, the user enters the third room, where there is an unencoded text on the floor, and the voice tells the user that if they help it find the set of all two grams and print their frequency in the text, the user is free to leave the magic temple with the biggest ever prize.


<a name="build-description"></a>
## Building and Testing

In order to build the project, make sure that you are on a LINUX machine or WSL, then enter the build folder and run the Makefile. After that, you will get the executable magic_temple. Run it and select the room that you want to break.


```BASH
    cd build
    make
```


```BASH
    ./magic_temple
    1
    ...the input data...
```

If you want to check some input files and reference files, check the input and ref folder from the build folder. To check if the program creates the correct output, execute the temple_run.sh file. After that, you will get an output message to see what task failed and what task passed.

