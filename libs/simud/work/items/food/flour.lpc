#include <const.h>
inherit "/obj/ingredient";

int grain_aspect;
string query_grain_type() {
	if( grain_aspect )
		return "/daemon/material"->query_aspect_string(grain_aspect);
	else
		return "generic";
}

TASTE( "Kinda dry and plain, really." )

DISTANT( query_grain_type() + " flour" )
NAME( query_grain_type() + " flour" )
PLURAL( query_grain_type() + " flour" )
SPECIFIC( "the " + query_grain_type() + " flour" )
ALT_NAME( ({ "flour", "meal" }) )
ALT_PLURAL( ({ "flour", "meal" }) )
LOOK( "Flour, the result of mercilessly crushing innocent little "+query_grain_type()+" kernels." )

// density of wheat flour is about 593kg/m^3
WEIGHT( 590 )
BULK( 1000 )
FOOD_VALUE( 1500 )	// per kilo, grain is 2000 so this isn't as nutritious

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_use_msg( "~Name ~verbeat the flour plain. Ick!" );
/* } OBJEDIT */
}

void apply_aspect( int x ) { grain_aspect = x; }

mapping query_aspects() {
   return ([ C_FLOUR ]) + ([ grain_aspect ]);
}
