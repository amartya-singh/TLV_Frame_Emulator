/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function prints the output.
 * @file Response_Output.c
 * @brief This program is equipped with clearing input buffer feature so next data is not corrupted.
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

#include "../include/Response_Output.h"
#include "../include/commons.h"

void Response_Output(BYTE Response_Frame[28])
{
    if(Response_Frame[2]==0x00)
    {
        printf("Invalid Frame! Can not process this frame further.\n");
        while ((getchar()) != '\n');//to clear input buffer

    }
    else
    {
        printf("Response Frame Output: ");
        if (Response_Frame[2] == 0x0F)                     //for set command response
        {
            for(int i=0; i<6; i++)
            {
                printf("%02X", Response_Frame[i]);
            }
            printf("\n");   
            while ((getchar()) != '\n');//to clear input buffer
        }
        else if(Response_Frame[3]==0x00)
        {
                printf("No Data is stored.\n");
                while ((getchar()) != '\n');
        }
        else                                               //for get command response
        {
            printf("%02X", Response_Frame[0]);
            printf("%02X", Response_Frame[1]);
            printf("%02X", Response_Frame[2]);
            printf("%02X", Response_Frame[3]);
            for(int i=4; i<(Response_Frame[3]+4); i++)
            {
                printf("%02X", Response_Frame[i]);
            }
            printf("\n");
            while ((getchar()) != '\n');//to clear input buffer
        }
    }    
}

