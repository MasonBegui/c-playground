#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

void leetcodetestcase1832();
bool checkIfPangram(char *sentence);

int main()
{
    leetcodetestcase1832();
    return 0;
}

bool checkIfPangram(char *sentence)
{
    bool pangramcheck[26] = {false};
    size_t length = strlen(sentence);
    for (int i = 0; i < length; i++)
    {
        ;
        printf("%c %d\n", sentence[i], sentence[i] - 'a');
        int index = sentence[i] - 'a';
        pangramcheck[index] = true;
    }
    for (int i = 0; i < 26; i++)
    {
        if (pangramcheck[i] == false)
        {
            return false;
        }
    }
    return true;
}

void leetcodetestcase1832()
{
    char str1[] = "thequickbrownfoxjumpsoverthelazydog";
    char str2[] = "leetcode";
    if (checkIfPangram(str1))
    {
        printf("The string 1 is a pangram.\n");
    }
    else
    {
        printf("The string 1 is not a pangram.\n");
    }
    if (checkIfPangram(str2))
    {
        printf("The string 2 is a pangram.\n");
    }
    else
    {
        printf("The string 2 is not a pangram.\n");
    }
}
