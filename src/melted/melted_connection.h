/*
 * melted_connection.h -- Connection Handler
 * Copyright (C) 2002-2015 Meltytech, LLC
 * Author: Charles Yates <charles.yates@pandora.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _MELTED_CONNECTION_H_
#define _MELTED_CONNECTION_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <mvcp/mvcp_parser.h>
#include <mvcp/mvcp_tokeniser.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** Connection structure
*/

typedef struct 
{
	mlt_properties owner;
	int fd;
	struct sockaddr_in sin;
	mvcp_parser parser;
} 
connection_t;

/** Enumeration for responses.
*/

typedef enum 
{
	RESPONSE_SUCCESS = 200,
	RESPONSE_SUCCESS_N = 201,
	RESPONSE_SUCCESS_1 = 202,
	RESPONSE_UNKNOWN_COMMAND = 400,
	RESPONSE_TIMEOUT = 401,
	RESPONSE_MISSING_ARG = 402,
	RESPONSE_INVALID_UNIT = 403,
	RESPONSE_BAD_FILE = 404,
	RESPONSE_OUT_OF_RANGE = 405,
	RESPONSE_TOO_MANY_FILES = 406,
	RESPONSE_ERROR = 500
} 
response_codes;

/* the following struct is passed as the single argument 
   to all command callback functions */

typedef struct 
{
	mvcp_parser    parser;
	mvcp_response  response;
	mvcp_tokeniser tokeniser;
	char         *command;
	int           unit;
	void         *argument;
	char         *root_dir;
} 
command_argument_t, *command_argument;

/* A handler is defined as follows. */
typedef int (*command_handler_t) ( command_argument );


extern void *parser_thread( void *arg );

#ifdef __cplusplus
}
#endif

#endif
