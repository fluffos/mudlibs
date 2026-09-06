#include <const.h>

#ifndef __VERSION__
#define __VERSION__ "(unknown MUDdriver)"
#endif

int main() {
	msg( MUD_TITLE + " is running " + VERSION );
	if( this_player()->query_level() > WIZLEVEL )
   		msg( "Driver is running v" + __VERSION__ );
	return 1;
}
