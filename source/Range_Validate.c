/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function will validate the range for the values of the command ID passed to it.
 * @file Range_Validate.c
 * @brief Range will be verified only for set command before storage. Range will be verified once the template of set command is verified.
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

#include "../include/Range_Validate.h"
#include "../include/commons.h"

BYTE Range_Validate(BYTE IP_Frame[28], BYTE Type)
{
    BYTE_4 value,value_1,value_2,value_3,value_4;
    /* Verifing Range for Group Command Frame */
    if (Type == 0x01)
    {
    switch (IP_Frame[2])
    {
        case SET_ADV_FREQ:
            value_1 = (IP_Frame[6]<<24) | (IP_Frame[7]<<16) | (IP_Frame[8]<<8) | IP_Frame[9];
            value_2 = (IP_Frame[12]<<24) | (IP_Frame[13]<<16) | (IP_Frame[14]<<8) | IP_Frame[15];
            value_3 = (IP_Frame[18]<<24) | (IP_Frame[19]<<16) | (IP_Frame[20]<<8) | IP_Frame[21];
            value_4 = (IP_Frame[24]<<24) | (IP_Frame[25]<<16) | (IP_Frame[26]<<8) | IP_Frame[27];
            if (((value_1 >= MIN_NORMAL_ADV_FREQ) && (value_1 <= MAX_NORMAL_ADV_FREQ)) &&
                ((value_2 >= MIN_CHECKIN_ADV_FREQ) && (value_2 <= MAX_CHECKIN_ADV_FREQ)) &&
                ((value_3 >= MIN_HIE_ADV_FREQ) && (value_3 <= MAX_HIE_ADV_FREQ)) &&
                ((value_4 >= MIN_ALERT_ADV_FREQ) && (value_4 <= MAX_ALERT_ADV_FREQ)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        case SET_ADV_TIMEOUT:
            value_1 = (IP_Frame[6]<<24) | (IP_Frame[7]<<16) | (IP_Frame[8]<<8) | IP_Frame[9];
            value_2 = (IP_Frame[12]<<24) | (IP_Frame[13]<<16) | (IP_Frame[14]<<8) | IP_Frame[15];
            value_3 = (IP_Frame[18]<<24) | (IP_Frame[19]<<16) | (IP_Frame[20]<<8) | IP_Frame[21];
            value_4 = (IP_Frame[24]<<24) | (IP_Frame[25]<<16) | (IP_Frame[26]<<8) | IP_Frame[27];
            if (((value_1 >= MIN_NORMAL_ADV_TIMEOUT) && (value_1 <= MAX_NORMAL_ADV_TIMEOUT)) &&
                ((value_2 >= MIN_CHECKIN_ADV_TIMEOUT) && (value_2 <= MAX_CHECKIN_ADV_TIMEOUT)) &&
                ((value_3 >= MIN_HIE_ADV_TIMEOUT) && (value_3 <= MAX_HIE_ADV_TIMEOUT)) &&
                ((value_4 >= MIN_ALERT_ADV_TIMEOUT) && (value_4 <= MAX_ALERT_ADV_TIMEOUT)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        case SET_ACC_CONFIG:
            value_1 = IP_Frame[6];
            value_2 = (IP_Frame[9]<<8) | IP_Frame[10];
            if (
                ((value_1 == ACC_SCALE_2) && (value_2 >= MIN_ACC_WAKEUP_THRESHOLD) && (value_2 <= MAX_ACC_WAKEUP_THRESHOLD_2)) ||
                ((value_1 == ACC_SCALE_4) && (value_2 >= MIN_ACC_WAKEUP_THRESHOLD) && (value_2 <= MAX_ACC_WAKEUP_THRESHOLD_4)) ||
                ((value_1 == ACC_SCALE_8) && (value_2 >= MIN_ACC_WAKEUP_THRESHOLD) && (value_2 <= MAX_ACC_WAKEUP_THRESHOLD_8)) ||
                ((value_1 == ACC_SCALE_16) && (value_2 >= MIN_ACC_WAKEUP_THRESHOLD) && (value_2 <= MAX_ACC_WAKEUP_THRESHOLD_16))
               )
            {
                return 1;
            }
            else
            {
                return 0;
            }
        case SET_IMPACT_CONFIG:
            value_1 = (IP_Frame[6]<<8) | IP_Frame[7];
            value_2 = (IP_Frame[10]<<8) | IP_Frame[11];
            value_3 = (IP_Frame[14]<<8) | IP_Frame[15];
            if (((value_1 >= MIN_EMFIT_SENSING_THRESHOLD) && (value_1 <= MAX_EMFIT_SENSING_THRESHOLD)) &&
                ((value_2 >= MIN_EMFIT_SAMPLE_RATE) && (value_2 <= MAX_EMFIT_SAMPLE_RATE)) &&
                ((value_3 >= MIN_EMFIT_TOTAL_SAMPLE) && (value_3 <= MAX_EMFIT_TOTAL_SAMPLE)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        case SET_DEVICE_CONFIG:
            value_1 = (IP_Frame[6]<<24) | (IP_Frame[7]<<16) | (IP_Frame[8]<<8) | IP_Frame[9];
            value_2 = (IP_Frame[12]<<24) | (IP_Frame[13]<<16) | (IP_Frame[14]<<8) | IP_Frame[15];
            if (((value_1 >= MIN_CHECKIN_INTERVAL && value_1 <= MAX_CHECKIN_INTERVAL)) &&
                ((value_2 >= MIN_INACTIVE_TIMEOUT && value_2 <= MAX_INACTIVE_TIMEOUT)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        case SET_HIE_CONFIG:  
            value_1 = IP_Frame[6];
            value_2 = IP_Frame[9];
            value_3 = (IP_Frame[12]<<24) | (IP_Frame[13]<<16) | (IP_Frame[14]<<8) | IP_Frame[15];
            if (((value_1 >= MIN_HIE_QUEUE_SIZE && value_1 <= MAX_HIE_QUEUE_SIZE)) &&
                ((value_2 >= MIN_HIE_THRESHOLD && value_2 <= MAX_HIE_THRESHOLD)) &&
                ((value_3 >= MIN_HIE_TIMEOUT && value_3 <= MAX_HIE_TIMEOUT)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }
    }

    /* Verifing Range for Single Command Frame */
    else if (Type == 0x02)
    {
    switch (IP_Frame[2])
    {
        case NORMAL_ADV_FREQ:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);

            /*This commented part should be used when value part is entered in decimal*/
            /*char str[8];
            sprintf(str, "%x", value);
            value = atoi(str);
            printf("%d\n", value);
            printf("%d\n", MIN_NORMAL_ADV_FREQ);*/

            if ((value >= MIN_NORMAL_ADV_FREQ) && (value <= MAX_NORMAL_ADV_FREQ))
            {
                return 1;
            }

            else 
            {
                return 0;
            }
        case CHECKIN_ADV_FREQ:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_CHECKIN_ADV_FREQ) && (value <= MAX_CHECKIN_ADV_FREQ))
            {
                return 1;
            }
            else 
            {
                return 0;
            }            
        case HIE_ADV_FREQ:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_HIE_ADV_FREQ) && (value <= MAX_HIE_ADV_FREQ))
            {
                return 1;
            }
            else 
            {
                return 0;
            } 
        case ALERT_ADV_FREQ:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_ALERT_ADV_FREQ) && (value <= MAX_ALERT_ADV_FREQ))
            {
                return 1;
            }
            else 
            {
                return 0;
            } 
        case NORMAL_ADV_TIMEOUT:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_NORMAL_ADV_TIMEOUT) && (value <= MAX_NORMAL_ADV_TIMEOUT))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case CHECKIN_ADV_TIMEOUT:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_CHECKIN_ADV_TIMEOUT) && (value <= MAX_CHECKIN_ADV_TIMEOUT))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case HIE_ADV_TIMEOUT:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_HIE_ADV_TIMEOUT) && (value <= MAX_HIE_ADV_TIMEOUT))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case ALERT_ADV_TIMEOUT:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_ALERT_ADV_TIMEOUT) && (value <= MAX_ALERT_ADV_TIMEOUT))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case ACC_SCALE:
            value = IP_Frame[4];
            if ((value == ACC_SCALE_2) || (value == ACC_SCALE_4) || (value == ACC_SCALE_8) || (value == ACC_SCALE_16))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case ACC_WAKEUP_THRESHOLD:
            value = ((IP_Frame[4]<<8) | IP_Frame[5]);
            if (
                ((Acc.Acc_Scale == ACC_SCALE_2) && (value >= MIN_ACC_WAKEUP_THRESHOLD) && (value <= MAX_ACC_WAKEUP_THRESHOLD_2))||
                ((Acc.Acc_Scale == ACC_SCALE_4) && (value >= MIN_ACC_WAKEUP_THRESHOLD) && (value <= MAX_ACC_WAKEUP_THRESHOLD_4))||
                ((Acc.Acc_Scale == ACC_SCALE_8) && (value >= MIN_ACC_WAKEUP_THRESHOLD) && (value <= MAX_ACC_WAKEUP_THRESHOLD_8))||
                ((Acc.Acc_Scale == ACC_SCALE_16) && (value >= MIN_ACC_WAKEUP_THRESHOLD) && (value <= MAX_ACC_WAKEUP_THRESHOLD_16))
               )
            {
                return 1;
            }
            else
            {
                return 0;
            }
        case EMFIT_SENSING_THRESHOLD:
            value = ((IP_Frame[4]<<8) | IP_Frame[5]);
            if ((value >= MIN_EMFIT_SENSING_THRESHOLD) && (value <= MAX_EMFIT_SENSING_THRESHOLD))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case EMFIT_SAMPLE_RATE:
            value = ((IP_Frame[4]<<8) | IP_Frame[5]);
            if ((value >= MIN_EMFIT_SAMPLE_RATE) && (value <= MAX_EMFIT_SAMPLE_RATE))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case EMFIT_TOTAL_SAMPLE:
            value = ((IP_Frame[4]<<8) | IP_Frame[5]);
            if ((value >= MIN_EMFIT_TOTAL_SAMPLE) && (value <= MAX_EMFIT_TOTAL_SAMPLE))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case CHECKIN_INTERVAL:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_CHECKIN_INTERVAL) && (value <= MAX_CHECKIN_INTERVAL))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case INACTIVE_TIMEOUT:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_INACTIVE_TIMEOUT) && (value <= MAX_INACTIVE_TIMEOUT))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case HIE_QUEUE_SIZE:
            value = IP_Frame[4];
            if ((value >= MIN_HIE_QUEUE_SIZE) && (value <= MAX_HIE_QUEUE_SIZE))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case HIE_THRESHOLD:
            value = IP_Frame[4];
            if ((value >= MIN_HIE_THRESHOLD) && (value <= MAX_HIE_THRESHOLD))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        case HIE_TIMEOUT:
            value = ((IP_Frame[4]<<24) | (IP_Frame[5]<<16) | (IP_Frame[6]<<8) | IP_Frame[7]);
            if ((value >= MIN_HIE_TIMEOUT) && (value <= MAX_HIE_TIMEOUT))
            {
                return 1;
            }
            else 
            {
                return 0;
            }
    }
    }

    else
    {
        return 0;
    }

}