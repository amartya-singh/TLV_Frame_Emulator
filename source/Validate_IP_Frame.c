/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Verifying Group & Single commands frame.
 * @file Validate_IP_Frame.c
 * @brief This program will verify input frames with the group and single command template.
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

#include "../include/Validate_IP_Frame.h"
#include "../include/commons.h"

BYTE Validate_IP_Frame(BYTE IP_Frame[28])
{
    if(Validate_Group_IP_Frame(IP_Frame))
    {
        if(Range_Validate(IP_Frame,0x01)||IP_Frame[3]==LENGTH_GET_CMD)
        {
            return 0x01;
        }
        
        else
        {
            Genrate_Set_Failed_Response(IP_Frame[2]);
            return 0;
        }
    }
    else if (Validate_Single_IP_Frame(IP_Frame))
    {
        if(Range_Validate(IP_Frame,0x02)||IP_Frame[3]==LENGTH_GET_CMD)
        {
            return 0x02;
        }
        else
        {
            Genrate_Set_Failed_Response(IP_Frame[2]);
            return 0;
        }
    }
    else
    {
        return 0;
    }

} 