/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Storing values for single command.
 * @file Store_Single_TLV_Frame.c
 * @brief This program will store single set command values in structures.
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

#include "../include/Store_Single_TLV_Frame.h"
#include "../include/commons.h"

BYTE* Store_Single_TLV_Frame(BYTE IP_Frame[28]) //stores tlv frame and genrates response
{
    
    memset(Get_Response_Frame,0x00,28); //Intializing all members to 0x00

    if (TLV_Frame.Length==0x00)
    {
        Genrate_Single_Get_Response(IP_Frame[2]);
        return Get_Response_Frame;
    }

    switch (IP_Frame[2])
    {
        case NORMAL_ADV_FREQ:    
            Adv_Freq.Normal_Adv_Freq = 0;        
            for(int i=0; i<LENGTH_NORMAL_ADV_FREQ;i++)
            {
                Adv_Freq.Normal_Adv_Freq |= (TLV_Frame.Value[i]<<(8*((LENGTH_NORMAL_ADV_FREQ-1)-i)));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case CHECKIN_ADV_FREQ:
            Adv_Freq.Checkin_Adv_Freq = 0;
            for(int i=0; i<LENGTH_CHECKIN_ADV_FREQ;i++)
            {
                Adv_Freq.Checkin_Adv_Freq |= TLV_Frame.Value[i]<<(8*((LENGTH_CHECKIN_ADV_FREQ-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case HIE_ADV_FREQ:
            Adv_Freq.HIE_Adv_Freq = 0;
            for(int i=0; i<LENGTH_HIE_ADV_FREQ;i++)
            {
                Adv_Freq.HIE_Adv_Freq |= TLV_Frame.Value[i]<<(8*((LENGTH_HIE_ADV_FREQ-1)-i));
            }

            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case ALERT_ADV_FREQ:
            Adv_Freq.Alert_Adv_Freq = 0;
            for(int i=0; i<LENGTH_ALERT_ADV_FREQ;i++)
            {
                Adv_Freq.Alert_Adv_Freq |= TLV_Frame.Value[i]<<(8*((LENGTH_ALERT_ADV_FREQ-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case NORMAL_ADV_TIMEOUT:
            Adv_Timeout.Normal_Adv_Timeout = 0;
            for(int i=0; i<LENGTH_NORMAL_ADV_TIMEOUT;i++)
            {
                Adv_Timeout.Normal_Adv_Timeout |= TLV_Frame.Value[i]<<(8*((LENGTH_NORMAL_ADV_TIMEOUT-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case CHECKIN_ADV_TIMEOUT:
            Adv_Timeout.Checkin_Adv_Timeout = 0;
            for(int i=0; i<LENGTH_CHECKIN_ADV_TIMEOUT;i++)
            {
                Adv_Timeout.Checkin_Adv_Timeout |= TLV_Frame.Value[i]<<(8*((LENGTH_CHECKIN_ADV_TIMEOUT-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case HIE_ADV_TIMEOUT:
            Adv_Timeout.HIE_Adv_Timeout = 0;
            for(int i=0; i<LENGTH_HIE_ADV_TIMEOUT;i++)
            {
                Adv_Timeout.HIE_Adv_Timeout |= TLV_Frame.Value[i]<<(8*((LENGTH_HIE_ADV_TIMEOUT-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case ALERT_ADV_TIMEOUT:
            Adv_Timeout.Alert_Adv_Timeout = 0;
            for(int i=0; i<LENGTH_ALERT_ADV_TIMEOUT;i++)
            {
                Adv_Timeout.Alert_Adv_Timeout |= TLV_Frame.Value[i]<<(8*((LENGTH_ALERT_ADV_TIMEOUT-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case ACC_SCALE:
            Acc.Acc_Scale = 0;
            for(int i=0; i<LENGTH_ACC_SCALE;i++)
            {
                Acc.Acc_Scale |= TLV_Frame.Value[i]<<(8*((LENGTH_ACC_SCALE-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case ACC_WAKEUP_THRESHOLD:
            Acc.Acc_Wakeup_Threshold = 0;
            for(int i=0; i<LENGTH_ACC_WAKEUP_THRESHOLD;i++)
            {
                Acc.Acc_Wakeup_Threshold |= TLV_Frame.Value[i]<<(8*((LENGTH_ACC_WAKEUP_THRESHOLD-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case EMFIT_SENSING_THRESHOLD:
            Impact.Emfit_Sensing_Threshold = 0;
            for(int i=0; i<LENGTH_EMFIT_SENSING_THRESHOLD;i++)
            {
                Impact.Emfit_Sensing_Threshold |= TLV_Frame.Value[i]<<(8*((LENGTH_EMFIT_SENSING_THRESHOLD-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case EMFIT_SAMPLE_RATE:
            Impact.Emfit_Sample_Rate = 0;
            for(int i=0; i<LENGTH_EMFIT_SAMPLE_RATE;i++)
            {
                Impact.Emfit_Sample_Rate |= TLV_Frame.Value[i]<<(8*((LENGTH_EMFIT_SAMPLE_RATE-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case EMFIT_TOTAL_SAMPLE:
            Impact.Emfit_Total_Sample = 0;
            for(int i=0; i<LENGTH_EMFIT_TOTAL_SAMPLE;i++)
            {
                Impact.Emfit_Total_Sample |= TLV_Frame.Value[i]<<(8*((LENGTH_EMFIT_TOTAL_SAMPLE-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case CHECKIN_INTERVAL:
            Device.Checkin_Interval = 0;
            for(int i=0; i<LENGTH_CHECKIN_INTERVAL;i++)
            {
                Device.Checkin_Interval |= TLV_Frame.Value[i]<<(8*((LENGTH_CHECKIN_INTERVAL-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case INACTIVE_TIMEOUT:
            Device.Inactive_Timeout = 0;
            for(int i=0; i<LENGTH_INACTIVE_TIMEOUT;i++)
            {
                Device.Inactive_Timeout |= TLV_Frame.Value[i]<<(8*((LENGTH_INACTIVE_TIMEOUT-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case HIE_QUEUE_SIZE:
            HIE.HIE_Queue_Size = 0;
            for(int i=0; i<LENGTH_HIE_QUEUE_SIZE;i++)
            {
                HIE.HIE_Queue_Size |= TLV_Frame.Value[i]<<(8*((LENGTH_HIE_QUEUE_SIZE-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case HIE_THRESHOLD:
            HIE.HIE_Threshold = 0;
            for(int i=0; i<LENGTH_HIE_THRESHOLD;i++)
            {
                HIE.HIE_Threshold |= TLV_Frame.Value[i]<<(8*((LENGTH_HIE_THRESHOLD-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case HIE_TIMEOUT:
            HIE.HIE_Timeout = 0;
            for(int i=0; i<LENGTH_HIE_TIMEOUT;i++)
            {
                HIE.HIE_Timeout |= TLV_Frame.Value[i]<<(8*((LENGTH_HIE_TIMEOUT-1)-i));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;
    }

}