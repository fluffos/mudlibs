/* $Id: zombie.c,v 1.2 1999/05/18 09:08:04 taffyd Exp $
 * $Log: zombie.c,v $
 * Revision 1.2  1999/05/18 09:08:04  taffyd
 * Fixed bug with inventory being destructed when zombie was killed.
 * Now it falls to the ground.
 *
 * Revision 1.1  1998/03/12 11:17:30  pinkfish
 * Initial revision
 *
 * Revision 1.2  1996/09/24 18:10:54  root
 * Added comments
 *
 */
inherit "/obj/monster/controlled_monster";
/* a basic zombie monster. */

void setup() {
    set_name( "zombie" );
    set_summoned( 0 );
    basic_setup("human", 1, 0 );
    add_property( "undead", 1 );
}

object make_corpse(){
    object dust;

    dust = clone_object( "/std/object" );
    dust->set_name( "zombie dust" );
    dust->set_short( "zombie dust" );
    dust->add_alias( "dust" );
    dust->set_long( "The dust is all that remains of a zombie.\n" );
    dust->add_property( "determinate", "some " );
    dust->move( environment() );
    return dust;
}

int second_life() {
    object room;
    room = environment( this_object() );
    if ( room ) {
        all_inventory()->move( room, "$N fall$s to the ground." );
        tell_room( room,
          (string)the_short() +" dissolves into dust.\n" );
    }
} /* second_life() */

int query_theft_command() {
    return -1;
} /* query_theft_command() */
