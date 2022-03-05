/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function takes input from user in form of char array then convert it to hex array.
 * @file Get_Input_Frame.c
 * @brief This is capable to handle invalid input.
 *
 * This function is called in main.c
 *
 * Author       - Amartya Singh
 *******************************************************************************
 *
 * History
 *
 * March/2/2021, Amartya Singh, Completed TLV Frame Emulator
 *
 * Feb/16/2021, Amartya Singh, Created (TLV Frame Emulator)
 *
 ******************************************************************************/

#include "../include/Get_Input_Frame.h"
#include "../include/commons.h"

BYTE Get_Input_Frame()
{
    BYTE IP_Char_String [56];
    BYTE *ptr = IP_Char_String;

    /* Taking Input as Character String */
    printf("Input String (In Hexadecimal): ");

    //28*2 because each byte will be represented by 2 character in hex value
    for(int i=0; i<(28*2) ; i++)                   
    {
        IP_Char_String[i]=getchar();
        if(IP_Char_String[i]=='\n')
        {
            break;
        }
        else if(!((IP_Char_String[i]>='0' && IP_Char_String[i]<='9') || 
                  (IP_Char_String[i]>='A' && IP_Char_String[i]<='F') ||
                  (IP_Char_String[i]>='a' && IP_Char_String[i]<='f')))
        {
            return 0;
        }
    }

    /* Converting Character string to hexadecimal array */
    for (unsigned long count = 0; count < sizeof IP_Frame/sizeof *IP_Frame; count++) 
    {
        sscanf(ptr, "%2X", &IP_Frame[count]);
        ptr = ptr+2;
    }

    return 1;

    /*printf("\n");
    for(int i=0; i<28 ; i++)
    {
         printf("%02X", IP_Frame[i]);
    }*/
}