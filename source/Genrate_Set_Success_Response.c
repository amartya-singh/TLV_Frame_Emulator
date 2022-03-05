/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This command will genrate response for sucessful set command.
 * @file Genrate_Set_Success_Response.c
 * @brief This function will be called if the values are in range and got stored in the structures.
 *
 * This function is called in Store_Group_TLV_Frame.c & Store_Single_TLV_Frame.c
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

#include "../include/Genrate_Set_Success_Response.h"
#include "../include/commons.h"

void Genrate_Set_Success_Response(BYTE Command_ID)
{
    memset(Set_Response_Frame,0x00,6); //Intializing all members to 0x00 
    
    Set_Response_Frame[0] = 0x55; //guard/padding
    Set_Response_Frame[1] = 0xAA; //guard/padding
    Set_Response_Frame[2] = 0x0F; //Response ID
    Set_Response_Frame[3] = 0x02; //Length
    Set_Response_Frame[4] = Command_ID; //Command ID
    Set_Response_Frame[5] = SUCCESS; //status
}