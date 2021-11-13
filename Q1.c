/** C program **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_WORDS   500


int main() {

    printf("Welcome to C program that reads the content of a file\n");

    // s meaning the sentence
    FILE *file;
    int i, len, index, isUnique;
    

    pid_t wait();

    //List of words need 
    char word[50];
    char words[MAX_WORDS][50];

    // Counting the distincts word with variable k

    int k[MAX_WORDS];
    
   
    // open the file 
    file = fopen("program.txt", "r");

    if (file == NULL) {
        printf("Ouff Error, This file doesn't exist.\n");
        printf("Please try again Later and make sure the file exist.\n");

        exit(0);
    } else {
        printf("File Opened Successfully. Reading Content now \n\n");
        
    }

    
    
    while (fscanf(file, "%s", word) != EOF)
    {
        

        // Remove last punctuation character
        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';


        // Check if word exits in list of all distinct words
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }

        // If word is unique then add it to distinct words list
        // and increment index. Otherwise increment occurrence 
        // count of current word.
        if (isUnique) 
        {
            strcpy(words[index], word);
            k[index]++;

            index++;
        }
        else
        {
            k[i - 1]++;
        }
    }

    // Close file
    fclose(file);

    // Using Fork to print the output
    int pid = fork();
    int x = getpid();
    printf("Before Fork: Parent process is PID is %d\n", x);

    if (pid == 0) {
        printf("I'm a child with pid : %d and parent pid : \n", getpid());
        printf("\nOccurrences of all distinct words in file: \n");
        // It is waiting for parent process to be executed.
        wait();

    
    } else if (pid > 0) {
        printf("I'm parent process with pid: %d\n", getpid());
        printf("\nOccurrences of all distinct words in file: \n");
        for (i=0; i<index; i++)
        {
        
        printf("'%s ': %d\n", words[i], k[i]);
        }    
    
    } else {
        printf("Error");
    }

    return 0;
}