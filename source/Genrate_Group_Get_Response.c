/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function will fetch all the stored value from the structures for Group Get Command.
 * @file Genrate_Group_Get_Response.c
 * @brief This function is will genrate Get_Response_Frame for Group Frame Get Command
 *
 * This function is called in Store_Group_TLV_Frame.c.
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

#include "../include/Genrate_Group_Get_Response.h"
#include "../include/commons.h"

void Genrate_Group_Get_Response(BYTE Command_ID)
{
    memset(Get_Response_Frame,0x00,28); //Intializing all members to 0x00

    int index = 0;

    switch (IP_Frame[2])
    {
        case GET_ADV_FREQ:
            Get_Response_Frame[0] = 0x55;
            Get_Response_Frame[1] = 0xAA;

            Get_Response_Frame[2] = GET_ADV_FREQ;
            Get_Response_Frame[3] = LENGTH_ADV_FREQ;

            Get_Response_Frame[4] = NORMAL_ADV_FREQ;
            Get_Response_Frame[5] = LENGTH_NORMAL_ADV_FREQ;
            index =6;
            for(int i=index, j=(LENGTH_NORMAL_ADV_FREQ-1); i<(LENGTH_NORMAL_ADV_FREQ+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Freq.Normal_Adv_Freq >> (8*j));
            }

            Get_Response_Frame[10] = CHECKIN_ADV_FREQ;
            Get_Response_Frame[11] = LENGTH_CHECKIN_ADV_FREQ;
            index =12;
            for(int i=index, j=(LENGTH_CHECKIN_ADV_FREQ-1); i<(LENGTH_CHECKIN_ADV_FREQ+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Freq.Checkin_Adv_Freq >> (8*j));
            }

            Get_Response_Frame[16] = HIE_ADV_FREQ;
            Get_Response_Frame[17] = LENGTH_HIE_ADV_FREQ;
            index =18;
            for(int i=index, j=(LENGTH_HIE_ADV_FREQ-1); i<(LENGTH_HIE_ADV_FREQ+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Freq.HIE_Adv_Freq >> (8*j));
            }

            Get_Response_Frame[22] = ALERT_ADV_FREQ;
            Get_Response_Frame[23] = LENGTH_ALERT_ADV_FREQ;
            index =24;
            for(int i=index, j=(LENGTH_ALERT_ADV_FREQ-1); i<(LENGTH_ALERT_ADV_FREQ+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Freq.Alert_Adv_Freq >> (8*j));
            }
            break;

        case GET_ADV_TIMEOUT:
            Get_Response_Frame[0] = 0x55;
            Get_Response_Frame[1] = 0xAA;

            Get_Response_Frame[2] = GET_ADV_TIMEOUT;
            Get_Response_Frame[3] = LENGTH_ADV_TIMEOUT;

            Get_Response_Frame[4] = NORMAL_ADV_TIMEOUT;
            Get_Response_Frame[5] = LENGTH_NORMAL_ADV_TIMEOUT;
            index =6;
            for(int i=index, j=(LENGTH_NORMAL_ADV_TIMEOUT-1); i<(LENGTH_NORMAL_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Timeout.Normal_Adv_Timeout >> (8*j));
            }

            Get_Response_Frame[10] = CHECKIN_ADV_TIMEOUT;
            Get_Response_Frame[11] = LENGTH_CHECKIN_ADV_TIMEOUT;
            index =12;
            for(int i=index, j=(LENGTH_CHECKIN_ADV_TIMEOUT-1); i<(LENGTH_CHECKIN_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Timeout.Checkin_Adv_Timeout >> (8*j));
            }

            Get_Response_Frame[16] = HIE_ADV_TIMEOUT;
            Get_Response_Frame[17] = LENGTH_HIE_ADV_TIMEOUT;
            index =18;
            for(int i=index, j=(LENGTH_HIE_ADV_TIMEOUT-1); i<(LENGTH_HIE_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Timeout.HIE_Adv_Timeout >> (8*j));
            }

            Get_Response_Frame[22] = ALERT_ADV_TIMEOUT;
            Get_Response_Frame[23] = LENGTH_ALERT_ADV_TIMEOUT;
            index =24;
            for(int i=index, j=(LENGTH_ALERT_ADV_TIMEOUT-1); i<(LENGTH_ALERT_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Adv_Timeout.Alert_Adv_Timeout >> (8*j));
            }
            break;

        case GET_ACC_CONFIG:
            Get_Response_Frame[0] = 0x55;
            Get_Response_Frame[1] = 0xAA;

            Get_Response_Frame[2] = GET_ACC_CONFIG;
            Get_Response_Frame[3] = LENGTH_ACC_CONFIG;

            Get_Response_Frame[4] = ACC_SCALE;
            Get_Response_Frame[5] = LENGTH_ACC_SCALE;
            index =6;
            for(int i=index, j=(LENGTH_ACC_SCALE-1); i<(LENGTH_ACC_SCALE+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Acc.Acc_Scale >> (8*j));
            }

            Get_Response_Frame[7] = ACC_WAKEUP_THRESHOLD;
            Get_Response_Frame[8] = LENGTH_ACC_WAKEUP_THRESHOLD;
            index =9;
            for(int i=index, j=(LENGTH_ACC_WAKEUP_THRESHOLD-1); i<(LENGTH_ACC_WAKEUP_THRESHOLD+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Acc.Acc_Wakeup_Threshold >> (8*j));
            }
            break;

        case GET_IMPACT_CONFIG:
            Get_Response_Frame[0] = 0x55;
            Get_Response_Frame[1] = 0xAA;

            Get_Response_Frame[2] = GET_IMPACT_CONFIG;
            Get_Response_Frame[3] = LENGTH_IMPACT_CONFIG;

            Get_Response_Frame[4] = EMFIT_SENSING_THRESHOLD;
            Get_Response_Frame[5] = LENGTH_EMFIT_SENSING_THRESHOLD;
            index =6;
            for(int i=index, j=(LENGTH_EMFIT_SENSING_THRESHOLD-1); i<(LENGTH_EMFIT_SENSING_THRESHOLD+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Impact.Emfit_Sensing_Threshold >> (8*j));

            }
            Get_Response_Frame[8] = EMFIT_SAMPLE_RATE;
            Get_Response_Frame[9] = LENGTH_EMFIT_SAMPLE_RATE;
            index =10;
            for(int i=index, j=(LENGTH_EMFIT_SAMPLE_RATE-1); i<(LENGTH_EMFIT_SAMPLE_RATE+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Impact.Emfit_Sample_Rate >> (8*j));
            }

            Get_Response_Frame[12] = EMFIT_TOTAL_SAMPLE;
            Get_Response_Frame[13] = LENGTH_EMFIT_TOTAL_SAMPLE;
            index =14;
            for(int i=index, j=(LENGTH_EMFIT_TOTAL_SAMPLE-1); i<(LENGTH_EMFIT_TOTAL_SAMPLE+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Impact.Emfit_Total_Sample >> (8*j));
            }
            break;

        case GET_DEVICE_CONFIG:
            Get_Response_Frame[0] = 0x55;
            Get_Response_Frame[1] = 0xAA;

            Get_Response_Frame[2] = GET_DEVICE_CONFIG;
            Get_Response_Frame[3] = LENGTH_DEVICE_CONFIG;

            Get_Response_Frame[4] = CHECKIN_INTERVAL;
            Get_Response_Frame[5] = LENGTH_CHECKIN_INTERVAL;
            index =6;
            for(int i=index, j=(LENGTH_CHECKIN_INTERVAL-1); i<(LENGTH_CHECKIN_INTERVAL+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Device.Checkin_Interval >> (8*j));
            }

            Get_Response_Frame[10] = INACTIVE_TIMEOUT;
            Get_Response_Frame[11] = LENGTH_INACTIVE_TIMEOUT;
            index =12;
            for(int i=index, j=(LENGTH_INACTIVE_TIMEOUT-1); i<(LENGTH_INACTIVE_TIMEOUT+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (Device.Inactive_Timeout >> (8*j));
            }
            break;

        case GET_HIE_CONFIG:
            Get_Response_Frame[0] = 0x55;
            Get_Response_Frame[1] = 0xAA;

            Get_Response_Frame[2] = GET_HIE_CONFIG;
            Get_Response_Frame[3] = LENGTH_HIE_CONFIG;

            Get_Response_Frame[4] = HIE_QUEUE_SIZE;
            Get_Response_Frame[5] = LENGTH_HIE_QUEUE_SIZE;
            index =6;
            for(int i=index, j=(LENGTH_HIE_QUEUE_SIZE-1); i<(LENGTH_HIE_QUEUE_SIZE+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (HIE.HIE_Queue_Size >> (8*j));
            }

            Get_Response_Frame[7] = HIE_THRESHOLD;
            Get_Response_Frame[8] = LENGTH_HIE_THRESHOLD;
            index =9;
            for(int i=index, j=(LENGTH_HIE_THRESHOLD-1); i<(LENGTH_HIE_THRESHOLD+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (HIE.HIE_Threshold >> (8*j));
            }

            Get_Response_Frame[10] = HIE_TIMEOUT;
            Get_Response_Frame[11] = LENGTH_HIE_TIMEOUT;
            index =12;
            for(int i=index, j=(LENGTH_HIE_TIMEOUT-1); i<(LENGTH_HIE_TIMEOUT+index), j>=0;i++,j--)
            {
                Get_Response_Frame[i] = (HIE.HIE_Timeout >> (8*j));
            }
            break;
    }
}