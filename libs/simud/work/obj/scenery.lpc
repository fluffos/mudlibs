#include <desc.h>
#include <inven.h>
#include <scenedesc.h>
#include <object.h>
#include <coord.h>
#include <const.h>

/** Scenery is an alternate use of the description/item combination
 * (as it appears in trinkets). Unlike a trinket, scenery should provide
 * a "phrase" in the short description. This phrase, which is always a
 * complete sentence, is tacked on immediately to the end of the long
 * description and will not show up on the "You see" list. It should have
 * no extra spaces on the beginning or end, and it is polite to drop the
 * color back to light gray at the end of the phrase if you use color
 * changes.
 *
 * The main purpose of scenery is to allow for player level flexibility
 * in the fine art of interior design. Scenery could be inherited and
 * modified to make it destroyable. I also intend to make scenery in
 * which you can hide objects, secrete yourself, etc.
 */

NAME( "scenery" )
DISTANT( "a piece of scenery" )
SPECIFIC( "the scenery" )
LOOK( "This is a piece of scenery. It has not been described yet." )
PHRASE( "There is a piece of scenery ~plac." )


void create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint( query_x(), query_y(), '=', 11, LAYER_FURNITURE );
}

void set_coord( int c ) {
   ::set_coord(c);
   if( environment() ) environment()->clear_map();
}

void on_move( object src ) {
   environment()->clear_map();
}

string destructor( object ob ) {
   if( environment() ) environment()->clear_map();
   return ::destructor(ob);;
}
