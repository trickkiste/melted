/**
 * \file mlt_filter.h
 * \brief abstraction for all filter services
 * \see mlt_filter_s
 *
 * Copyright (C) 2003-2009 Ushodaya Enterprises Limited
 * \author Charles Yates <charles.yates@pandora.be>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _MLT_FILTER_H_
#define _MLT_FILTER_H_

#include "mlt_service.h"

/** \brief Filter abstract service class
 *
 * A filter is a service that may modify the output of a single producer.
 *
 * \extends mlt_service_s
 * \properties \em track the index of the track of a multitrack on which the filter is applied
 */

struct mlt_filter_s
{
	/** We're implementing service here */
	struct mlt_service_s parent;

	/** public virtual */
	void ( *close )( mlt_filter );

	/** protected filter method */
	mlt_frame ( *process )( mlt_filter, mlt_frame );

	/** Protected */
	void *child;
};

#define MLT_FILTER_SERVICE( filter )		( &( filter )->parent )
#define MLT_FILTER_PROPERTIES( filter )		MLT_SERVICE_PROPERTIES( MLT_FILTER_SERVICE( filter ) )

extern int mlt_filter_init( mlt_filter self, void *child );
extern mlt_filter mlt_filter_new( );
extern mlt_service mlt_filter_service( mlt_filter self );
extern mlt_properties mlt_filter_properties( mlt_filter self );
extern mlt_frame mlt_filter_process( mlt_filter self, mlt_frame that );
extern int mlt_filter_connect( mlt_filter self, mlt_service producer, int index );
extern void mlt_filter_set_in_and_out( mlt_filter self, mlt_position in, mlt_position out );
extern int mlt_filter_get_track( mlt_filter self );
extern mlt_position mlt_filter_get_in( mlt_filter self );
extern mlt_position mlt_filter_get_out( mlt_filter self );
extern void mlt_filter_close( mlt_filter );

#endif