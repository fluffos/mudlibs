/* Updates by Lemming, 9/1/2000 */

#include <move_failures.h>

#define PAPER_LONG "This is a lovely big piece of " + colour + " wrapping paper.  It looks like it could be used to wrap up something as a present.  Try \"wrap <objects> in paper\".\n"
#define PRESENT_LONG "This lovely piece of " + colour + " paper has been used to wrap up something as a present.  Try \"unwrap\".\n"

inherit "/obj/baggage";

int do_wrap( object *things );
int do_unwrap();

private int wrapped;
private string colour;

/* @ignore yes */
void setup() {
   set_name( "wrappingpaper" );

   set_short( "piece of wrapping paper" );
   add_alias( "paper" );
   add_adjective( ({ "piece of", "wrapping" }) );
   set_main_plural( "pieces of wrapping paper" );
   add_plural( ({ "pieces of wrapping paper", "pieces of paper",
                  "papers" }) );
   set_long( PAPER_LONG );

   set_weight( 2 );
   set_max_weight( 225 ); /* 25 pounds */ 
   set_value( 600 );
   set_stuck(1);    
} /* setup() */

/**
 * This method sets the colour of the present.
 * @param word the colour of the present
 */
int set_colour( string word ) {
   if( colour ) {
      return 0;
   }
   colour = word;
   if (!colour) {
      return 0;
   }

   set_short( colour + " piece of wrapping paper" );
   add_adjective( explode( colour, " " ) );
   set_main_plural( colour + " pieces of wrapping paper" );
   set_long( PAPER_LONG );

   return 1;
} /* set_colour() */

#ifdef MY_TEST_FUNC
/** @ignore yes */
int test_remove( object thing, int flag ) {
   if( ( query_verb() == "get" ) || ( query_verb() == "take" ) ) {
      return !wrapped;
   }
   return 1;
} /* test_remove() */

/** @ignore yes */
int test_add( object thing, int flag ) {
   if( ( query_verb() == "put" ) || ( query_verb() == "give" ) ) {
      return 0;
   }
   return 1;
} /* test_add() */
#endif

/** @ignore yes */
void init() {
   add_command( "wrap", "<indirect:object:me> in <direct:object'present'>" );
   add_command( "unwrap", "<direct:object:'present'>", (: do_unwrap :) );
   add_command( "open", "<direct:object:'present'>", (: do_unwrap :) );
} /* init() */

/**
 * This is the main entry point and wraps up the given objects into the
 * wrapping paper.
 * @param things the things to wrap up
 * @return 1 on success, 0 on failure
 */
int do_wrap( object *things ) {
   object *valid, *failed;

   things -= ({ this_object() });

   if( wrapped ) {
      add_failed_mess( "The paper has already been used to wrap something.\n" );
      return 0;
   }

   if( !( sizeof( things ) ) ) {
      add_failed_mess( "You must wrap something!\n" );
      return 0;
   }

   valid = filter( things, (: !living( $1 ) &&
                              $1->move( this_object() ) == MOVE_OK :) );
   failed = things - valid;

   if( sizeof( failed ) ) {
      tell_object( this_player(), "You could not wrap " +
         query_multiple_short( failed ) + " in " + the_short() + ".\n" );
   }

   if( sizeof( valid ) ) {
      wrapped = 1;

      remove_alias( "paper" );
      remove_adjective( "piece of" );
      remove_adjective( "wrapping" );
      remove_plural( "pieces of wrapping paper" );
      remove_plural( "pieces of paper" );
      remove_plural( "papers" );

      call_out( "set_short", 1, colour + " present" );
      add_alias( "present" );
      set_main_plural( colour + " presents" );
      add_plural( "presents" );
      set_long( PRESENT_LONG );
        
      add_succeeded_mess( "$N $V $I in $D.\n", valid );
   } else {
      add_succeeded_mess( "" );
   }

   return 1;
} /* do_wrap() */

/**
 * This method unwraps the wrapping paper and sets up all the exiting
 * bits which pop out of it.
 * @return 1 on success, 0 on failure
 */
int do_unwrap() {
   int i;
   object *things;

   if( !wrapped ) {
      write( "There is nothing wrapped in the paper.\n" );
      return 0;
   }

   wrapped = 0;

   things = all_inventory();
   write( "You open the present and find "+ query_multiple_short( things ) +
      " inside.\n" );

   for( i = 0; i < sizeof( things ); i++ ) {
      if( things[ i ]->move( environment() ) ) {
         if( environment( environment() ) ) {
            things[ i ]->move( environment( environment() ) );
            write( "The " + things[ i ]->short() + " falls onto the " +
               "floor as you unwrap the present.\n" );
         }
      }
   }

   remove_alias( "present" );
   remove_plural( "presents" );

   call_out( "set_short", 1, colour + " piece of wrapping paper" );
   add_alias( "paper" );
   add_adjective( ({ "piece of", "wrapping" }) );
   set_main_plural( colour + " pieces of wrapping paper" );
   add_plural( ({ "pieces of wrapping paper", "pieces of paper",
                  "papers" }) );
   set_long( PAPER_LONG );

   add_succeeded_mess("$N unwrap$s $D.\n");

   return 1;
} /* do_unwrap() */

/** @ignore yes */
mixed *stats() {
    return ::stats() + ({
      ({ "colour", colour }),
      ({ "wrapped", wrapped }),
    });
} /* stats() */

/** @ignore yes */
mapping query_static_auto_load() {
    return ([
      "colour": colour,
      "::": ::int_query_static_auto_load(),
    ]);
} /* query_static_auto_load() */

/** @ignore yes */
void init_static_arg( mapping args ) {
    colour = args[ "colour" ];
    ::init_static_arg( args[ "::" ] );
} /* init_static_arg() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    return ([
      "wrapped": wrapped,
      "::": ::query_dynamic_auto_load(),
    ]);
} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping args ) {
    wrapped = args[ "wrapped" ];
    ::init_dynamic_arg( args[ "::" ] );
} /* init_dynamic_arg() */

int query_closed() {
    return 1;
} /* query_closed() */

string long_status() {
    return "";
} /* long_status() */
