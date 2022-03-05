/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This command will genrate response for sucessful set command.
 * @file Genrate_Set_Success_Response.h
 * @brief This function will be called if the values are in range and got stored in the structures.
 *
 * This function is called in Store_Group_TLV_Frame.c & Store_Single_TLV_Frame.c.
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

#ifndef GENRATE_SET_SUCCESS_RESPONSE_H_
#define GENRATE_SET_SUCCESS_RESPONSE_H_

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

/** If the value is successfully stored then this command will genrate Set command Sucess response.
 *
 * This function is defined in Genrate_Set_Success_Response.c
 *
 * @param[in] BYTE Command_ID (BYTE here is unsigned char)
 *
 * @param[out] BYTE Set_Response_Frame[6]
 *
 * @return None
 */
void Genrate_Set_Success_Response(BYTE Command_ID);

#endif