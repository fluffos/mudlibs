#include <position.h>

/* Current time for broom flight is 12 seconds */
#define TIME_LIMIT 15
#define BROOMSTICK "/d/guilds/witches/items/broomstick"

inherit "/std/room/basic_room";

string *people;

void setup() {
   set_light( 70 );
   set_short( "above discworld" );
   set_long( "You are high above the Disc, flying through the air.\n" );
   add_property( "determinate", "" );
   people = ({ });
}

int query_flying( string who ) {
   if( member_array( who, people ) > -1 )
      return 1;
   else
      return 0;
}

void down_they_go( object witch ) {
   object *obs, broom;

   if( !witch )
      return;

   /*  Damn, they're still here.  Put them down somewhere.  */
   if( environment( witch ) == this_object() ) {
      obs = match_objects_for_existence( "witches broomstick", witch );
      if( sizeof( obs ) )
        broom = obs[0];
      else
        broom = load_object( BROOMSTICK );
      broom->land( witch, broom->random_dest( witch ) );
   }
   people -= ({ witch->query_name() });
}

void init() {
   /*  Sometimes the call_out in the broom gets lost.  This 
    *  shouldn't be needed too often, but still...  */ 
   people += ({ this_player()->query_name() });
   call_out( (: down_they_go :), TIME_LIMIT, this_player() );
   ::init();
}

mixed query_default_position() {
   return ({ "flying through the air" }); 
}

void event_exit(object ob, string message, object to) {

   tell_object( ob, "You plummet towards the ground.\n" );
   tell_room( this_object(), ob->the_short()
         +" plummets towards the ground.\n", ob );

   STANDING_CMD->position( ob, 1 );
}
