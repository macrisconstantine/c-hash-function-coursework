/******************************************************************************************
 * Author: Constantine Macris
 * ITC2276 – Coursework
 * Dimitrios Milioris
 * 15 March 2022
 *
 * Description: The following module takes an inputted string from a user or a file
 * and lets the user choose to either calculate a hash value of the string,
 * measure the frequency of each letter in the string, or exit the program.
 * If the user chooses hashing, 3 different hashing functions are executed
 * and timed (in nanoseconds), and the results are displayed to the user.
 * 
 * It should be noted that some parts of the code were not written by me.
 * I integrated pieces of provided code for hash-functions and some other functionality.
 ******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>


void hashString(char *s);
void countLetterFrequency(char *s);


int main() {
    int choice=0, max_len = 128;
    int curr_size = max_len;
    
    while(1)
    {
        int i = 0;
        int c = EOF;
        char *str = (char *) malloc(max_len);
        // malloc is void, so we need to adjust its type to be pointer of char
        
        printf("\nWould you like to intput a sentence, or read from a file?\n--> ");
        printf("[1] Input a sentence from the keyboard.\n--> [2] Read input from a file.\n--> [3] Exit.\n");
        scanf("%d", &choice);
        
        
        if (choice==1)
        {   
            int chars=0;
            
            // Prompts the user for input
            printf("\nEnter a minimum of 10 characters and then hit ENTER.\n\n");
            
            // Ensures that at least 10 characters are entered
            while(chars<10)
            {
                if (str == NULL) continue; 
                
                // Populate str variable from stdin
                while ((c = getchar()) != '\n' && c!= EOF) 
                {   
                    // Ensures that the 10 characters are alphabetical
                    if(c>='A'&&c<='Z') chars++;
                    if(c>='a'&&c<='z') chars++;
                    str[i++] = (char) c;
                    if (i == curr_size) 
                    
                    // Reallocates additional memory when capacity is reached
                    {
                        curr_size = i + max_len;
                        str = (char *) realloc(str, curr_size);
                    }
                }
            }
            // Marks the end of the string
            str[i] = '\0';
        } 
        else if (choice==2)
        { 
            FILE *fp = fopen("TestFile50000.txt", "r");
            if ( fp == NULL ) 
            {
                printf( "\nThe file failed to open.\n\n" );
                continue;
            }
            while ((c = getc(fp)) != EOF) 
            {
                str[i++] = (char) c;
                if (i == curr_size) 
                {
                    curr_size = i + max_len;
                    str = (char *) realloc(str, curr_size);
                }
            }
            str[i] = '\0';
            fclose(fp);
            printf("\nString successfully read from file.\n\n\n");
        }
        else if (choice==3)
        {
            // free the allocated memory
            free(str);
            str = NULL;
            exit(0);
        }
        else
        {
            printf("\nInvalid input. Try again.\n\n");
            // Clear scanf function to avoid infinite program loop
            //scanf("%s*");
            while ( getchar() != '\n' ); 
            continue;
        }
        printf("\n\n\n                What would you like to do?\n");
        printf("----------------------------------------------------------------\n");
        printf("--> [1] Calculate 3 different hashes of the input string.\n");
        printf("--> [2] Calculate the letter frequency of each letter in the string.\n");
        printf("--> [3] Exit the program.\n\n\n");
        scanf("%d", &choice);
        if (choice==1)
        {
            hashString(str);
            exit(0);
        }
        else if (choice==2)
        {
            countLetterFrequency(str);
            exit(0);
        }
        else if (choice==3)
        {
            // free the allocated memory
            free(str);
            str = NULL;
            exit(0);
        }
        else
        {
            printf("\nInvalid input--try again.\n\n");
            // Clears scanf buffer to prevent loops
            while ( getchar() != '\n' ); 
            continue;
        }
    } 
}




