/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Verifying Group commands frame.
 * @file Validate_Group_IP_Frame.h
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

#ifndef VALIDATE_GROUP_IP_FRAME_H_
#define VALIDATE_GROUP_IP_FRAME_H_
/******************
* Includes
*******************/

#include "../include/commons.h"

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

/** This function will validate the input Frame with template of Group command Frame
 *
 * This function is defined in Validate_Group_IP_Frame.c
 *
 * @param[in] BYTE IP_Frame [28]
 *
 * @param[out] None.
 *
 * @return BYTE 0,1
 */
BYTE Validate_Group_IP_Frame(BYTE IP_Frame[28]);

#endif