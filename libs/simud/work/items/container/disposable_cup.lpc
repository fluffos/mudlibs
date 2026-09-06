#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

TASTE( "Curiously enough. It doesn't taste like anything. Seriously. It tastes like nothing at all." )

NAME( "disposable cup" )
LOOK( "A thin, disposable paper cup.?(HASINV: It contains $(INV).)" )
DISTANT( "a disposable cup" )
SPECIFIC( "the disposable cup" )
PLURAL( "disposable cups" )
ALT_NAME( ({ "cup", "paper cup", "disposable paper cup" }) )
ALT_PLURAL( ({ "cups", "paper cups", "disposable paper cups" }) )

GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 100 )
BULK( 300 )

void create() {
	::create();
	set_bulk_capacity( 300 );
	set_weight_capacity( 2500 );
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_PAPER ]);
}

void dest_me() {
	destruct(this_object());
}

void check_empty() {
	if( !sizeof(all_inventory()) ) {
		if( environment() && environment()->query_is_living() ) {
			set_target(this_object());
			set_actor(environment());
			environment()->msg_local("~CACT~Name ~verbcrumple up ~targ and throw ~prot away.~CDEF");
		}
		move(load_object("/obj/void"));
		call_out( "dest_me", 2 );
	}
}

// disappear when you drink it all
int on_consume( int max ) {
	int res = ::on_consume(max);
	check_empty();
	return res;
}

// also disappear if you pour it out, eh?
void on_pour_out( object player, int volume ) {
	check_empty();
}
