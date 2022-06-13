#include<stdio.h>

int main()

{

  char str_message[500], ch;

  int j, key;

  printf("Enter a message to decrypt: ");

  scanf("%s",str_message);

  printf("Enter key: ");

  scanf("%d", &key);

  for(j = 0; str_message[j] != '\0'; ++j){

    ch = str_message[j];

    if(ch >= 'a' && ch <= 'z'){

      ch = ch - key;

      if(ch < 'a'){

        ch = ch + 'z' - 'a' + 1;

      }

      str_message[j] = ch;

    }

    else if(ch >= 'A' && ch <= 'Z'){

      ch = ch - key;

      if(ch < 'A'){

        ch = ch + 'Z' - 'A' + 1;

      }

      str_message[j] = ch;

    }

  }

  printf("Decrypted message: %s", str_message);

  return 0;

}