#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include<ctype.h>

// get key
int main(int argc, string argv[])
{
    //make sure there is an argument
    bool passed = true;
    if (argc == 2)
    {
        string word = argv[1];
        for (int k = 0; k < strlen(argv[1]); k++)
        {
            char letter = word[k];
            if (isalpha(letter) == false)
            {
                passed = false;
                break;
            }

        }
    }
    else
    {
        return 1;
    }
    if (passed == true)
    {
        string message = get_string("plaintext: ");
        printf("ciphertext: ");

        int j = 0;
        int i = 0;
        while (j < strlen(message))
        {

            string key = argv[1];

            //roll key index back to 0 after it reaches the end
            if (i >= strlen(key))
            {
                i = 0;
            }

            //get individual characters in the key and plaintext
            char indexed_plaintext = message[j];
            char indexed_key = key[i];
            //printf("%c", indexed_key);

            //change characters to integers
            indexed_plaintext = (int)indexed_plaintext;
            indexed_key = (int)indexed_key;
            int cypher_text;

            //only encipher letters
            if (indexed_plaintext >= 'A' && indexed_plaintext <= 'z')
            {
                //reduce key to 0-26
                indexed_key -= 'A';
                if (indexed_key > 25)
                {
                    indexed_key -= ('a' - 'A');
                }

                //add key and plaintext together
                cypher_text = indexed_key + indexed_plaintext;

                //bring cyphertext back to text ascii values
                if (indexed_plaintext <= 'Z')
                {
                    while (cypher_text > 'Z')
                    {
                        cypher_text -= 26;
                    }
                }
                if (indexed_plaintext <= 'z')
                {
                    while (cypher_text > 'z')
                    {
                        cypher_text -= 26;
                    }
                }
                i++;
            }
            else
            {
                cypher_text = indexed_plaintext;
            }

            //convert back to text
            cypher_text = (char)cypher_text;

            //printf("key: %i %c ", indexed_key, indexed_key);
            //printf("plaintext: %i %c ", indexed_plaintext, indexed_plaintext);
            //printf("cypher: %i", cypher_text);
            //printf("cypher: %c\n", cypher_text);
            printf("%c", cypher_text);
            j ++;
            indexed_plaintext = (char)indexed_plaintext;

        }
        printf("\n");
        return 0;
    }
    else
    {
        return 1;
    }

}
