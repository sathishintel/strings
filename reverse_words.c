#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void reverse(char *start, char *end)
{
        char temp;
        while (start < end)
        {
                temp = *start;
                *start++ = *end;
                *end--  = temp;

        }

}

void reverse_words(char *string)
{
        char *word_begin = NULL;
        char *temp = string; /* temp is for word boundry */

        /*STEP 1 of the above algorithm */
        while( *temp )
        {
                /*This condition is to make sure that the string start with
                valid character (not space) only*/
                if (( word_begin == NULL ) && (*temp != ' ') )
                {
                        word_begin=temp;
                }
                if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
                {
                        reverse(word_begin, temp);
                        word_begin = NULL;
                }
                        temp++;
        } /* End of while */
        /*STEP 2 of the above algorithm */

        printf("string is %s\n",string);
        reverse(string, temp-1);
}


int main()
{

        char str[] = "sathish is a bad boy";
        printf("string is %s\n",str);

        reverse_words(str);
        printf("string is %s\n",str);
        return 0;
}
            
