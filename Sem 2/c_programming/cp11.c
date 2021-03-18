#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replace (char *, char *, char *);
int main()
{
    char choice.str[200];
    int i, words;
    char s_string[200], r_string[200];
    /* Input text from user */
    printf("Enter any text:\n ");
    gets(str);
    do
    {
        printf("\n1. Find the total number of words \n");
        printf("2. Capitalize the first word of each sentence \n");
        printf("3. Replace a given word with another word \n");
        printf("4. Stop\n");
        printf("Enter your choice : ");
        choice=getchar();
        switch(choice)
        {
            case '1' :
                i = 0;
                words = 1;
                /* Runs a loop till end of text */
                while(str[i] != '\0')
                {
                /* If the current character(str[i]) is white space */
                    if(str[i]==' ' || str[i]=='\n' || str[i]=='\t')
                    {
                        words++;
                    }
                    i++;
                }
                printf("\nTotal number of words = %d", words);
                break;
            case '2' :
                i = 0;
                /* Runs a loop till end of text */
                while(str[i] != '\0')
                {
                    /* Checks to see if a character is a punctuation mark used to denote
                    the end of a sentence. (! . ?) */
                    if(str[i]=='!' || str[i]=='.' || str[i]=='?')
                    {
                        i++;
                        while(str[i]!=' ' || str[i]!='\n' || str[i]!='\t || str[i] != '\0'’)
                        {
                            putchar (toupper(str[++i]));
                            i++;
                        }
                    }
                    else
                        putchar (str[i]);
                    i++;
                }
                break;
            case '3' :
            /*Get the search and replace string from the user.
             Write a user defined function to replace the first occurrence of the search string with the replace string.
             Recursively call the function until there is no occurrence of the search string.*/
                printf("\nPlease enter the string to search: ");
                fflush(stdin);
                gets(s_string);
                printf("\nPlease enter the replace string ");
                fflush(stdin);
                gets(r_string);
                replace(str, s_string, r_string);
                puts(str);
                break;
            case '4' :
                exit(0);
        }
        printf("\nPress any key to continue....");
        getch();
    }
    while(choice!=’4’);
    return 0;
}
void replace(char * str, char * s_string, char * r_string) 
{
    //a buffer variable to do all replace things
    char buffer[200];
    //to store the pointer returned from strstr
    char * ch;
    //first exit condition
    if(!(ch = strstr(str, s_string)))
        return;
    //copy all the content to buffer before the first occurrence of the search string
    strncpy(buffer, str, ch-str);
    //prepare the buffer for appending by adding a null to the end of it
    buffer[ch-str] = 0;
    //append using sprintf function
    sprintf(buffer+(ch -str), "%s%s", r_string, ch + strlen(s_string));
    //empty str for copying
    str[0] = 0;
    strcpy(str, buffer);
    //pass recursively to replace other occurrences
    return replace(str, s_string, r_string);
}