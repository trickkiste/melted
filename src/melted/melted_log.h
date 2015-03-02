/*
 * melted_log.h -- logging facility header
 * Copyright (C) 2002-2015 Meltytech, LLC
 * Author: Dan Dennedy <dan@dennedy.org>
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

#ifndef _MELTED_LOG_H_
#define _MELTED_LOG_H_

#include <syslog.h>

#ifdef __cplusplus
extern "C"
{
#endif

enum log_output {
	log_stderr,
	log_syslog
};

void melted_log_init( enum log_output method, int threshold );
void melted_log( int priority, const char *format, ... );

#ifdef __cplusplus
}
#endif

#endif
