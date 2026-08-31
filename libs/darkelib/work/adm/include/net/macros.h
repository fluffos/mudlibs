//  This file contains useful network macros.
#ifndef __NET__MACROS_H
#define __NET__MACROS_H

#ifndef DNS_MASTER
#include "net/daemons.h"
#endif
#include <driver/origin.h>

// for converting hostnames in the host representation to the
// network representation and vice-versa
string htonn( string x ) {
   x = replace_string( lower_case( (x) ? (x) : "" ), " ", "." );  
     while( last_char( x, '.' ) )
        x = x[ 0..<2 ];  
   return x;  
}

#define nntoh(x) cap_words(replace_string((x)?(x):"","."," "))

string mud_alias( string x ) {
  string y; 
  if( !(y = (string) DNS_MASTER -> query_alias(x)) )  
      y = nntoh(x); 
  return y; 
}

// macros for getting resources
//#define Mud_name() "TMI-2"

// Use this one normally.
#define Mud_name() capitalize(mud_name())
#define mud_nname() htonn( Mud_name() )
#define udp_port() (int)DNS_MASTER->query_udp_port()

// macros for the sequencer
#define index_add(x)     (int)DNS_MASTER->idx_request((x))
#define index_call(x,y)  (int)DNS_MASTER->idx_callback((x),(y))


#if 0
#define ACCESS_CHECK(x) ((origin()==1)||(geteuid((x)) == ROOT_UID)||(geteuid((x))=="inspiral"))
#else
#define ACCESS_CHECK(x)	\
        ((origin() == ORIGIN_DRIVER || origin() == ORIGIN_LOCAL || \
         origin() == ORIGIN_CALL_OUT) || \
	(x && (geteuid(x) == ROOT_UID)))
#endif


// for logging and stuff
#define dns_log(x, y)   DNS_MASTER->aux_log((x), (y))
#define dns_warning(x)  DNS_MASTER->aux_warning((x))

// I want to turn this into a simul_efun sometime

#endif //__NET__MACROS_H
