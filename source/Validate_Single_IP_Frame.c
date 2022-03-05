/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Verifying Single commands frame.
 * @file Validate_Single_IP_Frame.c
 * @brief This program will verify input frames with the single command template.
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

#include "../include/Validate_Single_IP_Frame.h"
#include "../include/commons.h"

BYTE Validate_Single_IP_Frame(BYTE IP_Frame[28])
{
    memset(Set_Response_Frame,0x00,6);
    if(IP_Frame[0]==0x55 && IP_Frame[1]==0xAA)               //Will check for guard/padding presence in the recieved frame
    {        
        switch(IP_Frame[2])
        {
            case NORMAL_ADV_FREQ:
                if (IP_Frame[3]==LENGTH_NORMAL_ADV_FREQ || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }

            case CHECKIN_ADV_FREQ:
                if (IP_Frame[3]==LENGTH_CHECKIN_ADV_FREQ || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case HIE_ADV_FREQ:
                if (IP_Frame[3]==LENGTH_HIE_ADV_FREQ || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case ALERT_ADV_FREQ:
                if (IP_Frame[3]==LENGTH_ALERT_ADV_FREQ || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case NORMAL_ADV_TIMEOUT:
                if (IP_Frame[3]==LENGTH_NORMAL_ADV_TIMEOUT || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case CHECKIN_ADV_TIMEOUT:
                if (IP_Frame[3]==LENGTH_CHECKIN_ADV_TIMEOUT || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case HIE_ADV_TIMEOUT:
                if (IP_Frame[3]==LENGTH_HIE_ADV_TIMEOUT || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case ALERT_ADV_TIMEOUT:
                if (IP_Frame[3]==LENGTH_ALERT_ADV_TIMEOUT || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case ACC_SCALE:
                if (IP_Frame[3]==LENGTH_ACC_SCALE || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case ACC_WAKEUP_THRESHOLD:
                if (IP_Frame[3]==LENGTH_ACC_WAKEUP_THRESHOLD || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case EMFIT_SENSING_THRESHOLD:
                if (IP_Frame[3]==LENGTH_EMFIT_SENSING_THRESHOLD || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case EMFIT_SAMPLE_RATE:
                if (IP_Frame[3]==LENGTH_EMFIT_SAMPLE_RATE || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case EMFIT_TOTAL_SAMPLE:
                if (IP_Frame[3]==LENGTH_EMFIT_TOTAL_SAMPLE || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case CHECKIN_INTERVAL:
                if (IP_Frame[3]==LENGTH_CHECKIN_INTERVAL || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case INACTIVE_TIMEOUT:
                if (IP_Frame[3]==LENGTH_INACTIVE_TIMEOUT || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case HIE_QUEUE_SIZE:
                if (IP_Frame[3]==LENGTH_HIE_QUEUE_SIZE || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case HIE_THRESHOLD:
                if (IP_Frame[3]==LENGTH_HIE_THRESHOLD || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
                    return 0;
                }
            case HIE_TIMEOUT:
                if (IP_Frame[3]==LENGTH_HIE_TIMEOUT || IP_Frame[3]==LENGTH_GET_CMD)
                {
                    return 1;
                }
                else
                {
                    printf("Please check the length value of the command.\n");
                    Genrate_Set_Failed_Response(IP_Frame[2]);
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