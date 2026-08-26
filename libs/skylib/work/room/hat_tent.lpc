/**
 * This is the tent erected from the wizards' tent hats.
 *
 * @author Gruper
 * @started March 97
 */

inherit "/std/room/basic_room";

void    setup();
void    set_locations( object o );
void    dest_me();
string  query_quit_handler();
int     inside_tent();
int     trap_tell( string words, object thing, int silent );

object outside;

/** @ignore */
void setup() {
   set_short( "pointy tent" );
   set_room_size( 3 );
   set_light( 50 );
   add_property( "no teleport", 1 );
   add_property( "inside_tent", 1 );
   set_long( "This tent seems to have been constructed by pulling "
         "four telescopic legs from a wizard's hat, turning it inside-out, "
         "and then rolling down flaps of oiled canvas from the brim. "
         "A small magical light zips around near the ceiling, bathing the "
         "room with its cheery, blueish glow. A small sign is sewn to the "
         "wall.\n" );
   add_item( "small magical light", "The small light emits a cheerful, "
         "blue glow as it zips 'round and 'round near the ceiling.\n" );
   add_item( ({ "canvas", "walls" }), "The walls are made of oiled "
         "canvas.\n" );
   add_item( "telescopic legs", "The four legs have literally been "
         "pulled out of a hat.  Without them, you'd just be standing "
         "inside a very large bag.\n" );
   add_item( ({ "tent flap", "door" }), "The tent flap keeps foul "
         "weather and irritating insects out.\n" );
   add_sign("The sign has been stitched to the wall. It appears to "
         "contain instructions for how to handle the tent.",
         "Ynstructionnes:\n"
         "===============\n"
         "Wenne the Hatte is nothing butte a Hatte, thou canst\n"
         "\"erect tent\", and wenne thou hast tired of the Tent,\n"
         "thou canst \"collapse tent\", but make sure thou art\n "
         "Outside yt, or be Trapped!\n");

} /* setup() */

/** @ignore */
string query_quit_handler() {
   if( outside )
      return file_name( outside );
   else
      return 0;
}

/** @ignore */
void set_locations( object o ){
   outside = o;
}

/** @ignore */
void dest_me() {
   object *things;

   things = all_inventory( this_object() );
   tell_room( this_object(), "Someone collapses the tent and you "
         "tumble outside.\n" );
   if( sizeof( things ) > 1 ){ 
      tell_object( this_player(), query_multiple_short( things ) +
            " tumble out from the collapsing tent.\n" );
      tell_room( outside, query_multiple_short( things ) + " tumble "
         "out from the collapsing tent.\n", this_player() ); 
   } else if( sizeof( things ) ){
      tell_object( this_player(), query_multiple_short( things ) +
            " tumbles out from the collapsing tent.\n" );
      tell_room( outside, query_multiple_short( things ) + " tumbles "
            "out from the collapsing tent.\n", this_player() );
   }
   things->move( outside );
   ::dest_me();
}

/** @ignore */
int trap_tell( string words, object thing, int silent ) {
   if( function_exists( "trap_tell", outside ) )
      return outside->trap_tell( words, thing, silent );
   else
      return "/cmds/living/t_ell"->cmd( words, thing, silent );
}

/** @ignore */
int trap_cast( string command ) {
   string *words;

   words = explode( command, " " );

   if( sizeof( words ) > 0 && words[0] == "cast" ) {
      /* Trap the command */
      write( "There's not enough room to cast spells in here!\n" );
      say( this_player()->one_short() +" looks disappointed.\n" );
      return 1;
   } else {
      /* Don't trap the command */
      return 0;
   }
}


/** @ignore */
void init() {
   ::init();
   this_player()->command_override( (: trap_cast :) );
} /* init() */


/** @ignore */
mixed *stats() {
   return ::stats() + ({ ({ "outside", outside }) });
} /* stats() */

// Make sure room isn't unloaded
/** @ignore */
int query_keep_room_loaded() {
   return 1;
}

/** @ignore */
int dont_free() {
   return 1;
}

/** @ignore */
int clean_up() {
   return 1;
}
