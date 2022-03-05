/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Verifying Group commands frame.
 * @file Validate_Group_IP_Frame.c
 * @brief This program will verify input frames with the group command template.
 *
 * This function is called in Validate_IP_Frame.c
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

#include "../include/Validate_Group_IP_Frame.h"
#include "../include/commons.h"

BYTE Validate_Group_IP_Frame(BYTE IP_Frame[28])                 
{
    memset(Set_Response_Frame,0x00,6);
    if(IP_Frame[0]==0x55 && IP_Frame[1]==0xAA)               //Will check for guard/padding presence in the recieved frame
    {        
        switch(IP_Frame[2])
        {
            case SET_ADV_FREQ:
                if ((IP_Frame[3]==LENGTH_ADV_FREQ) &&

                    (IP_Frame[4]==NORMAL_ADV_FREQ && IP_Frame[5]==LENGTH_NORMAL_ADV_FREQ) &&

                    (IP_Frame[10]==CHECKIN_ADV_FREQ && IP_Frame[11]==LENGTH_CHECKIN_ADV_FREQ) &&

                    (IP_Frame[16]==HIE_ADV_FREQ && IP_Frame[17]==LENGTH_HIE_ADV_FREQ) &&

                    (IP_Frame[22]==ALERT_ADV_FREQ && IP_Frame[23]==LENGTH_ALERT_ADV_FREQ))
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of each subframe or subcommand.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case GET_ADV_FREQ:
                if (IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Length of get command should be 00\n");
                    return 0;
                }


            case SET_ADV_TIMEOUT:
                if ((IP_Frame[3]==LENGTH_ADV_TIMEOUT) &&

                    (IP_Frame[4]==NORMAL_ADV_TIMEOUT && IP_Frame[5]==LENGTH_NORMAL_ADV_TIMEOUT) &&

                    (IP_Frame[10]==CHECKIN_ADV_TIMEOUT && IP_Frame[11]==LENGTH_CHECKIN_ADV_TIMEOUT) &&

                    (IP_Frame[16]==HIE_ADV_TIMEOUT && IP_Frame[17]==LENGTH_HIE_ADV_TIMEOUT) &&

                    (IP_Frame[22]==ALERT_ADV_TIMEOUT && IP_Frame[23]==LENGTH_ALERT_ADV_TIMEOUT))
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of each subframe or subcommand.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case GET_ADV_TIMEOUT:
                if (IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Length of get command should be 00\n");
                    return 0;
                }


            case SET_ACC_CONFIG:
                if ((IP_Frame[3]==LENGTH_ACC_CONFIG) &&

                    (IP_Frame[4]==ACC_SCALE && IP_Frame[5]==LENGTH_ACC_SCALE) &&

                    (IP_Frame[7]==ACC_WAKEUP_THRESHOLD && IP_Frame[8]==LENGTH_ACC_WAKEUP_THRESHOLD))
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of each subframe or subcommand.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }            
            case GET_ACC_CONFIG:
                if (IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Length of get command should be 00\n");
                    return 0;
                }


            case SET_IMPACT_CONFIG:
                if ((IP_Frame[3]==LENGTH_IMPACT_CONFIG) &&

                    (IP_Frame[4]==EMFIT_SENSING_THRESHOLD && IP_Frame[5]==LENGTH_EMFIT_SENSING_THRESHOLD) &&

                    (IP_Frame[8]==EMFIT_SAMPLE_RATE && IP_Frame[9]==LENGTH_EMFIT_SAMPLE_RATE) &&

                    (IP_Frame[12]==EMFIT_TOTAL_SAMPLE && IP_Frame[13]==LENGTH_EMFIT_TOTAL_SAMPLE))
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of each subframe or subcommand.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }   
            case GET_IMPACT_CONFIG:
                if (IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Length of get command should be 00\n");
                    return 0;
                }


            case SET_DEVICE_CONFIG:
                if ((IP_Frame[3]==LENGTH_DEVICE_CONFIG) &&

                    (IP_Frame[4]==CHECKIN_INTERVAL && IP_Frame[5]==LENGTH_CHECKIN_INTERVAL) &&

                    (IP_Frame[10]==INACTIVE_TIMEOUT && IP_Frame[11]==LENGTH_INACTIVE_TIMEOUT))
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of each subframe or subcommand.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }             
            case GET_DEVICE_CONFIG:
                if (IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Length of get command should be 00\n");
                    return 0;
                }    
            case SET_HIE_CONFIG:
                if ((IP_Frame[3]==LENGTH_HIE_CONFIG) &&

                    (IP_Frame[4]==HIE_QUEUE_SIZE && IP_Frame[5]==LENGTH_HIE_QUEUE_SIZE) &&

                    (IP_Frame[7]==HIE_THRESHOLD && IP_Frame[8]==LENGTH_HIE_THRESHOLD) &&

                    (IP_Frame[10]==HIE_TIMEOUT && IP_Frame[11]==LENGTH_HIE_TIMEOUT))
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of each subframe or subcommand.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }            
            case GET_HIE_CONFIG:
                if (IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Length of get command should be 00\n");
                    return 0;
                }
            default:
                return 0;
        }

    }
    else
    {
        return 0;
    }
}