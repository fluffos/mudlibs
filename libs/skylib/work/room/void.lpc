#include <config.h>
inherit "/std/room/basic_room";

object  button;

void setup() {
   set_short( "convention in the void" );
   add_property( "determinate", "the " );
   add_property( "no teleport", 1 );
   set_light( 100 );
   set_long("This is where you come when you fall out a room and have " 
      "nowhere to go.  You are inside a large igloo.  Penguin " 
      "waiters (in tuxedos of course) are serving drinks to the " 
      "assembled crowd.  A large wombat sits at the end of a " 
      "banquet table, his head resting peacefully in a bowl of " 
      "soup.\n");
   add_item( "igloo", "The igloo is nice and warm despite the icy decor." );
   add_item( ({ "penguin waiter", "penguin" }),
         "The penguins are all rather formally dressed." );
   add_item( "drink", "The drinks come in a variety of colours and smells." );
   add_item( "crowd", "The crowd consists mostly of iguanas." );
   add_item( "bowl", "The bowl holds the soup.  It is green and hums." );
   add_item( "soup", "The soup is pink and comfortable-looking." );
   add_item( "wombat", "Perhaps you should tell the wombat to use a spoon." );
   add_exit( "pub", CONFIG_START_LOCATION, "path" );
   co_ord = 0;
} /* setup() */

void reset() {
   if ( !button ) {
      button = clone_object( "/obj/misc/button" );
      button->move( this_object() );
   }
} /* reset() */

void init() {
   ::init();
   co_ord = 0;
} /* init() */

int *query_co_ord() { return 0; }

void clean_up( int i ) { return; }
