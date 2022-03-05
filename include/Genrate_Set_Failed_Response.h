/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This command will genrate response for failed set command.
 * @file Genrate_Set_Failed_Response.h
 * @brief This function will be called if template of Set command is valid but value is not in range.
 *
 * This function is called in Validate_IP_Frame.c.
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

#ifndef GENRATE_SET_FAILED_RESPONSE_H_
#define GENRATE_SET_FAILED_RESPONSE_H_

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

/** If the value is out of range and failed to store then this command will genrate Set command Fail response.
 *
 * This function is defined in Genrate_Set_Failed_Response.c
 *
 * @param[in] BYTE Command_ID (BYTE here is unsigned char)
 *
 * @param[out] BYTE Set_Response_Frame[6]
 *
 * @return None
 */
void Genrate_Set_Failed_Response(BYTE Command_ID);

#endif