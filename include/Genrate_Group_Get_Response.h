/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function will fetch all the stored value from the structures for Group Get Command.
 * @file Genrate_Group_Get_Response.h
 * @brief This function will genrate Get_Response_Frame for Group Frame Get Command
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
 * Feb/2/2021, Amartya Singh, Created (TLV Frame Emulator)
 *
 ******************************************************************************/

#ifndef GENRATE_GROUP_GET_RESPONSE_H_
#define GENRATE_GROUP_GET_RESPONSE_H_

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

/** For Group Frame get command this function will genrate output.
 *
 * This function is defined in Genrate_Group_Get_Response.c
 *
 * @param[in] BYTE Command_ID (BYTE here is unsigned char)
 *
 * @param[out] BYTE Get_Response_Frame[28]
 *
 * @return None
 */
void Genrate_Group_Get_Response(BYTE Command_ID);

#endif
