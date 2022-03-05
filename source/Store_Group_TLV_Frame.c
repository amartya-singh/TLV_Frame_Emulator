/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Storing values for group command.
 * @file Store_Group_TLV_Frame.c
 * @brief This program will store group set command values in structures.
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

#include "../include/Store_Group_TLV_Frame.h"
#include "../include/commons.h"

BYTE* Store_Group_TLV_Frame(BYTE IP_Frame[28]) //stores tlv frame and genrates reponse
{    
    memset(Get_Response_Frame,0x00,28); //Intializing all members to 0x00

    int index = 0;

    switch (IP_Frame[2])
    {
        case SET_ADV_FREQ:
            Adv_Freq.Normal_Adv_Freq = 0;
            Adv_Freq.Checkin_Adv_Freq = 0;
            Adv_Freq.HIE_Adv_Freq = 0;
            Adv_Freq.Alert_Adv_Freq = 0;
            //value[0] subframe type
            //value[1] subframe length
            index =2;
            for(int i=index, j=(LENGTH_NORMAL_ADV_FREQ-1); i<(LENGTH_NORMAL_ADV_FREQ+index), j>=0;i++,j--)
            {
                Adv_Freq.Normal_Adv_Freq |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[6] subframe type
            //value[7] subframe length
            index =8;
            for(int i=index, j=(LENGTH_CHECKIN_ADV_FREQ-1); i<(LENGTH_CHECKIN_ADV_FREQ+index), j>=0;i++,j--)
            {
                Adv_Freq.Checkin_Adv_Freq |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[12] subframe type
            //value[13] subframe length
            index =14;
            for(int i=index, j=(LENGTH_HIE_ADV_FREQ-1); i<(LENGTH_HIE_ADV_FREQ+index), j>=0;i++,j--)
            {
                Adv_Freq.HIE_Adv_Freq |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[18] subframe type
            //value[19] subframe length
            index =20;
            for(int i=index, j=(LENGTH_ALERT_ADV_FREQ-1); i<(LENGTH_ALERT_ADV_FREQ+index), j>=0;i++,j--)
            {
                Adv_Freq.Alert_Adv_Freq |= (TLV_Frame.Value[i]<<(8*j));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case GET_ADV_FREQ:
            Genrate_Group_Get_Response(IP_Frame[2]);
            return Get_Response_Frame;

        case SET_ADV_TIMEOUT:
            Adv_Timeout.Normal_Adv_Timeout = 0;
            Adv_Timeout.Checkin_Adv_Timeout = 0;
            Adv_Timeout.HIE_Adv_Timeout = 0;
            Adv_Timeout.Alert_Adv_Timeout = 0;
            //value[0] subframe type
            //value[1] subframe length
            index =2;
            for(int i=index, j=(LENGTH_NORMAL_ADV_TIMEOUT-1); i<(LENGTH_NORMAL_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Adv_Timeout.Normal_Adv_Timeout |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[6] subframe type
            //value[7] subframe length
            index =8;
            for(int i=index, j=(LENGTH_CHECKIN_ADV_TIMEOUT-1); i<(LENGTH_CHECKIN_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Adv_Timeout.Checkin_Adv_Timeout |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[12] subframe type
            //value[13] subframe length
            index =14;
            for(int i=index, j=(LENGTH_HIE_ADV_TIMEOUT-1); i<(LENGTH_HIE_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Adv_Timeout.HIE_Adv_Timeout |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[18] subframe type
            //value[19] subframe length
            index =20;
            for(int i=index, j=(LENGTH_ALERT_ADV_TIMEOUT-1); i<(LENGTH_ALERT_ADV_TIMEOUT+index), j>=0;i++,j--)
            {
                Adv_Timeout.Alert_Adv_Timeout |= (TLV_Frame.Value[i]<<(8*j));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case GET_ADV_TIMEOUT:
            Genrate_Group_Get_Response(IP_Frame[2]);
            return Get_Response_Frame;

        case SET_ACC_CONFIG:
            Acc.Acc_Scale = 0;
            Acc.Acc_Wakeup_Threshold = 0;
            //value[0] subframe type
            //value[1] subframe length
            index =2;
            for(int i=index, j=(LENGTH_ACC_SCALE-1); i<(LENGTH_ACC_SCALE+index), j>=0;i++,j--)
            {
                Acc.Acc_Scale |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[3] subframe type
            //value[4] subframe length
            index =5;
            for(int i=index, j=(LENGTH_ACC_WAKEUP_THRESHOLD-1); i<(LENGTH_ACC_WAKEUP_THRESHOLD+index), j>=0;i++,j--)
            {
                Acc.Acc_Wakeup_Threshold |= (TLV_Frame.Value[i]<<(8*j));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case GET_ACC_CONFIG:
            Genrate_Group_Get_Response(IP_Frame[2]);
            return Get_Response_Frame;

        case SET_IMPACT_CONFIG:
            Impact.Emfit_Sensing_Threshold = 0;
            Impact.Emfit_Sample_Rate = 0;
            Impact.Emfit_Total_Sample = 0;
            //value[0] subframe type
            //value[1] subframe length
            index =2;
            for(int i=index, j=(LENGTH_EMFIT_SENSING_THRESHOLD-1); i<(LENGTH_EMFIT_SENSING_THRESHOLD+index), j>=0;i++,j--)
            {
                Impact.Emfit_Sensing_Threshold |= (TLV_Frame.Value[i]<<(8*j));
            }
/*
    //Testing//
    printf("******%x\n", Impact.Emfit_Sensing_Threshold);
*/
            //value[4] subframe type
            //value[5] subframe length
            index =6;
            for(int i=index, j=(LENGTH_EMFIT_SAMPLE_RATE-1); i<(LENGTH_EMFIT_SAMPLE_RATE+index), j>=0;i++,j--)
            {
                Impact.Emfit_Sample_Rate|= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[8] subframe type
            //value[9] subframe length
            index =10;
            for(int i=index, j=(LENGTH_EMFIT_TOTAL_SAMPLE-1); i<(LENGTH_EMFIT_TOTAL_SAMPLE+index), j>=0;i++,j--)
            {
                Impact.Emfit_Total_Sample|= (TLV_Frame.Value[i]<<(8*j));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case GET_IMPACT_CONFIG:
            Genrate_Group_Get_Response(IP_Frame[2]);
            return Get_Response_Frame;

        case SET_DEVICE_CONFIG:
            Device.Checkin_Interval = 0;
            Device.Inactive_Timeout = 0;
            //value[0] subframe type
            //value[1] subframe length
            index =2;
            for(int i=index, j=(LENGTH_CHECKIN_INTERVAL-1); i<(LENGTH_CHECKIN_INTERVAL+index), j>=0;i++,j--)
            {
                Device.Checkin_Interval |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[6] subframe type
            //value[7] subframe length
            index =8;
            for(int i=index, j=(LENGTH_INACTIVE_TIMEOUT-1); i<(LENGTH_INACTIVE_TIMEOUT+index), j>=0;i++,j--)
            {
                Device.Inactive_Timeout |= (TLV_Frame.Value[i]<<(8*j));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case GET_DEVICE_CONFIG:
            Genrate_Group_Get_Response(IP_Frame[2]);
            return Get_Response_Frame;

        case SET_HIE_CONFIG:
            HIE.HIE_Queue_Size = 0;
            HIE.HIE_Threshold = 0;
            HIE.HIE_Timeout = 0;
            //value[0] subframe type
            //value[1] subframe length
            index =2;
            for(int i=index, j=(LENGTH_HIE_QUEUE_SIZE-1); i<(LENGTH_HIE_QUEUE_SIZE+index), j>=0;i++,j--)
            {
                HIE.HIE_Queue_Size |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[3] subframe type
            //value[4] subframe length
            index =5;
            for(int i=index, j=(LENGTH_HIE_THRESHOLD-1); i<(LENGTH_HIE_THRESHOLD+index), j>=0;i++,j--)
            {
                HIE.HIE_Threshold |= (TLV_Frame.Value[i]<<(8*j));
            }
            //value[6] subframe type
            //value[7] subframe length
            index =8;
            for(int i=index, j=(LENGTH_HIE_TIMEOUT-1); i<(LENGTH_HIE_TIMEOUT+index), j>=0;i++,j--)
            {
                HIE.HIE_Timeout |= (TLV_Frame.Value[i]<<(8*j));
            }
            //Genrating and returning Response
            Genrate_Set_Success_Response(IP_Frame[2]);
            return Set_Response_Frame;

        case GET_HIE_CONFIG:
            Genrate_Group_Get_Response(IP_Frame[2]);
            return Get_Response_Frame;       
    }    
}