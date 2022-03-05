/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Storing In TLV Structure.
 * @file Store_TLV_Frame.c
 * @brief This program will store Input frame in TLV structure.
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

#include "../include/Store_TLV_Frame.h"
#include "../include/commons.h"

void Store_TLV_Frame(BYTE IP_Frame[28])
{
    TLV_Frame.Type = IP_Frame[2];
    TLV_Frame.Length = IP_Frame[3];
    int index = 3;
    for(int i=0; i<MAX_VALUE_SIZE; i++)
    {
        TLV_Frame.Value[i]=IP_Frame[++index];
    }

/*
    //Testing//
    printf("%x\n", TLV_Frame.Type);
    printf("%x\n", TLV_Frame.Length);
    for(int i=0; i<MAX_VALUE_SIZE; i++)
    {
        printf("%x\n", TLV_Frame.Value[i]);
    }
*/
}