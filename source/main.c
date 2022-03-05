/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This cointains the main() of the Project.
 * @file TLV_Frame_Emulator.c
 * @brief This program will contiously run.
 *
 * This is main driver program of this project.
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

#include "../include/main.h"
#include "../include/commons.h"

BYTE Response_Frame[28];
BYTE Set_Response_Frame[6]; 
BYTE Get_Response_Frame[28];
BYTE IP_Frame [28]; // 2 BYTE for guard, 1 BYTE for TYPE, 1 BYTE for Length, 24 BYTE for Value So Total is 28

int main(void)
{
    //Fetch_Data();
while(1)
{
    //external while loop to handle break condition of internal while loop
while(1)
{
    /* Intialization */    
    memset(IP_Frame,0x00,28); //Intializing all members to 0x00
    memset(Response_Frame,0x00,28);

    BYTE *Response_Byte;

    /* Taking Input */  
    if(!(Get_Input_Frame()))
    {
        while ((getchar()) != '\n');
        printf("Enter in Hexadecimal Only.\n");
        break;
    }

    /*Checking validity of Input Frame & Storing the TLV Frame and capturing the response*/
    if(Validate_IP_Frame(IP_Frame)==0x01)
    {
        Store_TLV_Frame(IP_Frame);
        Response_Byte = Store_Group_TLV_Frame(IP_Frame);
        //Store_Data(IP_Frame[2]);
    }
    else if(Validate_IP_Frame(IP_Frame)==0x02)
    {
        Store_TLV_Frame(IP_Frame);
        Response_Byte = Store_Single_TLV_Frame(IP_Frame);
        //Store_Data(IP_Frame[2]);
    }
    else
    {
        printf("Value is not in range. Set Command failed.\n");
        Store_TLV_Frame(IP_Frame);
        for(int i=0;i<6;i++)
        {
        Response_Frame[i]=Set_Response_Frame[i];
        }
        Response_Output(Response_Frame);
        continue;
    }
        
    /*Accessing each byte of array genrated in Store_TLV_Frame and storing it in Response_Frame*/
    for(int i=0;i<28;i++)
    {
        Response_Frame[i]=Response_Byte[i];
    }
    
    /* Showing Output */
    Response_Output(Response_Frame);
}
}
return 0;
}