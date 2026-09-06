#include <const.h>
#define ASPECT_STR ("/daemon/material"->query_aspect_string(product_aspect))
inherit "/obj/food";

int product_aspect;
int query_product_aspect() { return product_aspect; }
void set_product_aspect(int x) { product_aspect = x; }

int fertile;
int query_fertile() { return fertile; }
void set_fertile(int x) { fertile = x; }

TASTE( "It tastes yucky." )
FOOD_VALUE( 30 )
DRINK_VALUE( 20 )

FOOD_BUFF( (["con":1+fertile]) )
FOOD_BUFF_TIME( 6 )

WEIGHT( 20 + (fertile?20:0) )
BULK( 25 + (fertile?10:0) )
GETTABLE( 1 )
DROPPABLE( 1 )
		
NAME( (fertile?"fertile ":"") + ASPECT_STR + " egg" )
PLURAL( (fertile?"fertile ":"") + ASPECT_STR + " eggs" )
DISTANT( "a " + ASPECT_STR + " egg" )
SPECIFIC( "the " + ASPECT_STR + " egg" )
ALT_NAME( ({ ASPECT_STR+" egg", "egg", (fertile?"fertile egg":"infertile egg") }) )
ALT_PLURAL( ({ ASPECT_STR+" eggs", "eggs", (fertile?"fertile eggs":"infertile eggs") }) )

LOOK( "An egg. This particular one appears to have been laid by a "+ASPECT_STR+(fertile?", and if left in a nest should hatch into another one of the critters.":". It is too small to be fertile."))
				
create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_use_msg( "After gnawing at the shell for a bit, ~name ~verbsucceed in choking down a raw egg. Yummy." );
/* } OBJEDIT */
}

/*
 * We are doing away with this system...
 *
int on_crack( object dest ) {
   object ob;

   if( !dest || !dest->query_container() )
      return 0;

   ob = clone_object( "/items/food/liquid_egg" );
   ob->move( dest );
   set_target(dest);
   this_player()->msg_local( "~CACT~Name ~verbcrack an egg into ~targ.~CDEF" );
   destruct( this_object() );
   return MOVE_OK_FLAG | MOVE_SILENCE_FLAG;
}
*/

mapping query_aspects() {
   return ([ C_FOOD, C_EGG ]) + ([ query_product_aspect() ]) + (fertile?([C_FERTILE]):([]));
}
