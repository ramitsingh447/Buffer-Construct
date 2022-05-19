/**************************************************************
* Class:  CSC-415-0# Spring 2022
* Name: Ramit Singh
* Student ID: 918213925
* GitHub Name: ramitsingh447
* Project: Assignment 2 – Buffer and Construct
*
* File: assignment2.c
*
* Description: To show how to construct, buffer and memory allocate
*
**************************************************************/
#include "assignment2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The int main is to help take in the command line arguments.
int main(int arg, char *argv[])
{
  personalInfo *info = malloc(sizeof(personalInfo));
  info->firstName = argv[1];
  info->lastName = argv[2];
  info->studentID = 918213925;
  info->level= SENIOR;
  info->languages = (KNOWLEDGE_OF_CPLUSPLUS + KNOWLEDGE_OF_JAVA + KNOWLEDGE_OF_PYTHON); // added plus signs to add all languages to get certain number of output.

// copies message from argument command line.
  strcpy(info-> message,argv[3]);

  //Have PerosnalInfo structure by having a int vairable (info), then use to call writePersonalInfo.
  int wpi = writePersonalInfo(info);

// When the buffer is filled, commit the buffer then Empty the buffer out
//idx to 0 after buffer is empty
  char *buff = (char *) malloc(BLOCK_SIZE);
  int lgth, idx = 0;
  const char * str = getNext();
    while(str!=NULL){
      lgth = strlen(str);
      
        for(int n=0;n<lgth;n++){
          buff[idx] = str[n];
          idx++;
          
          if (idx == BLOCK_SIZE){
            commitBlock(buff);
            strcpy(buff, "");
            idx = 0;
          }
        }
        //use function to get next string
        str = getNext();
    }
    //shows if the null is recieved from input
    if(idx!=0){
      commitBlock(buff);
    }
//prints out hexadecimal charcters inside the output
checkIt();
//frees the memory
free(info);
free(buff);
}
