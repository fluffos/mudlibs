// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/accept_objects.h
// Description:	Defines fuer set_accept_objects()
// Author:	Garthan
//
// $Log: accept_objects.h,v $
// Revision 1.4  2002/02/14 04:51:30  gnomi
// Bugfix zur vorherigen Aenderung
//
// Revision 1.3  2002/02/13 22:18:02  gnomi
// Closures ueber den Closure-Container laufen lassen.
// Zusaetzliches Define AO_MASTER_CALL.
//
// Revision 1.2  2001/03/14 20:17:57  freaky
// CVS-Log eingebaut.
//

#ifndef ACCEPT_OBJECTS_H
#define ACCEPT_OBJECTS_H 1

#include "apps.h"

#define AO_CALL(x)   	    lambda(({'a,'b, 'c, 'd}),\
				({#'call_other, this_object(), "x", 'a, 'b, 'c,'d}))
#define AO_MASTER_CALL(master,fun)\
			    CLOSURE_CONTAINER->do_bind(unbound_lambda(\
				({'a,'b, 'c, 'd}),\
				({#'call_other, (master), "fun", 'a, 'b, 'c,'d})))
#define AO_ACCEPT	    CLOSURE_CONTAINER->do_bind(unbound_lambda(\
				({'a,'b, 'c, 'd}),\
				({#'call_other, 'c,"accept", 'a, 'b, 'c, 'd})))
#define AO_REFUSE	    CLOSURE_CONTAINER->do_bind(unbound_lambda(\
				({'a,'b, 'c, 'd}),\
				({#'call_other, 'c,"refuse", 'a, 'b, 'c, 'd})))
#define AO_ACCEPT_FROM_VOID CLOSURE_CONTAINER->do_bind(unbound_lambda(\
				({'a,'b, 'c, 'd}),\
				({#'call_other, 'c,"accept_from_void", \
				'a, 'b, 'c, 'd})))
#define AO_ACCEPT_INVIS     CLOSURE_CONTAINER->do_bind(unbound_lambda(\
				({'a,'b, 'c, 'd}),\
                    		({#'call_other, 'c,"accept_invis", \
				'a, 'b, 'c, 'd})))

#endif // ACCEPT_OBJECTS_H
