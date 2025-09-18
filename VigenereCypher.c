/*Assignment: pa01 - Encrypting a plaintext file using the Vigenere cipher
|
|
| Author: Terence Wilchcombe
| Language: c
|
| To Compile:
| gcc -o pa01 pa01.c
|
| To Execute:
|./pa01 kX.txt pX.txt
|
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Spring 2022
| Instructor: McAlpin
| Due Date: 2/27/2022
|
|
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// Declaring / Initializing user defined functions
char * getText(FILE *filename);
void output(char *text);
// Main Function / Encryption happens
int main(int argc, char**argv)
{

 // Initializing variables
 char *decrypted;
 char *encrypted = malloc(sizeof(char)*(512+1));
int i;
 int j;
 int k;
 char *tempArray;
 char *keyFileName = argv[1];
 char *decryptedFileName = argv[2];
 char *key;

// Opening Files
 FILE *keyFile = fopen(keyFileName, "r");
 key = getText(keyFile);
 FILE *decryptedFile = fopen(decryptedFileName, "r");
 tempArray = getText(decryptedFile);
 decrypted = tempArray;

 for(i = strlen(tempArray); i < 512; i++)
 {
 tempArray[i] = 'x';
 }
 tempArray[i] = '\0';
 decrypted =tempArray;
 // Encrypting the decrypted text using given key
 for(j = 0; j < 512; j++)
 {
 encrypted[j] = (((decrypted[j] - 'a') + (key[k] - 'a')) % 26) + 'a';
 k = (k+1) % (strlen(key));
 }

 encrypted[512] = '\0';

 // Printing outputs to terminal
 printf("\nKey Used:\n");
 output(key);
 free(key);

 printf("\nDecrypted Text:\n");
 output(decrypted);
 free(decrypted);

 printf("\nEncrypted Text:\n");
 output(encrypted);
 free(encrypted);



 return 0;
}
// Function to print output to the terminal
void output(char *text){

 for(int i = 0; i < strlen(text); i++){
 printf("%c", text[i]);

 if((i+1)%80 == 0){
 printf("\n");
 }
 }

 printf("\n\n");
}
// Function to obtain text from given files
char * getText(FILE *filename){
 if(filename == NULL){
 return NULL;
 }
 char *stringX = malloc(sizeof(char)*(512+1));
 int x = 0;
 char storage[512+1];
 int y = 0;

 while(fscanf(filename, "%s", storage) != EOF){

// changes all characters to lowercase syntax
for(int i = 0; i < strlen(storage); i++){

 storage[i] = tolower(storage[i]);

// combats error given if storage[i] happens to cast as an integer
 if(isalpha(storage[i])){
 stringX[y] = storage[i];

 stringX[y+1] = '\0';

 y++;
 x++;

 if(x == 512)
 break;
 }
 }

 if(x == 512)
 break;
 }
 fclose(filename);
 return stringX;
}
/*=============================================================================
| I [Terence Wilchcombe] ([te750713]) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/