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

#ifndef VALIDATE_SINGLE_IP_FRAME_H_
#define VALIDATE_SINGLE_IP_FRAME_H_
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

/** This function will validate the input Frame with template of Single command Frame
 *
 * This function is defined in Validate_Single_IP_Frame.c
 *
 * @param[in] BYTE IP_Frame [28]
 *
 * @param[out] None.
 *
 * @return BYTE 0,1
 */
BYTE Validate_Single_IP_Frame(BYTE IP_Frame[28]);

#endif