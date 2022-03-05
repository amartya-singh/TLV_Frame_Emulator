/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Verifying Group & Single commands frame.
 * @file Validate_IP_Frame.h
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

#ifndef VALIDATE_IP_FRAME_H_
#define VALIDATE_IP_FRAME_H_
/******************
* Includes
*******************/

#include "../include/commons.h"
#include "../include/Validate_Group_IP_Frame.h"
#include "../include/Validate_Single_IP_Frame.h"
#include "../include/Range_Validate.h"
#include "../include/Genrate_Set_Failed_Response.h"

/*************************
 * Defines
 *************************/

/* None */

/**************************************
 * Structures, Enumerations, Typedefs
 *************************************/

/* None */

/************************
 * Function Prototypes
 ************************/

/** This function will validate if the provided frame is valid or not and also checks for the range
 *
 * This function is defined in Validate_IP_Frame.c
 *
 * @param[in] BYTE IP_Frame [28]
 *
 * @param[out] None
 *
 * @return BYTE 0, 0x01, 0x02
 */
BYTE Validate_IP_Frame(BYTE IP_Frame[28]);


#endif