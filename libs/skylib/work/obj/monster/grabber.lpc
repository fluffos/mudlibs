#define  HAND_STOPPED         0
#define  HAND_GOING_OUT       1
#define  HAND_COMING_BACK     2

inherit NPC_OBJ;

object   _player;
int      _heading;
int      _got_it;

string owner_present();

void setup() {

   set_name( "hand" );
   set_short( "severed hand" );

   add_adjective( ({ "severed", "grappling" }) );

   set_long( (: "This is a severed hand from a corpse.  It hangs ominously "
                "in the air, twitching occasionally in response to some "
                "arcane stimulus.  $C$" + owner_present() :) );

   basic_setup("strange", 1, 0 );

   set_cannot_change_position( 1 );
   set_default_position( ({ "hanging ominously in the air" }) );
   return_to_default_position( 1 );
   
   add_property( "floating", 1 );

   _heading    = HAND_STOPPED;

} /* setup() */


void init() {
  ::init();
  if( this_player() == _player ) {
    this_player()->add_command("grab",
                               this_object(),
                               "<string'item'> from [the] <string'direction'>");
  }
} /* init() */


void dest_me()
{
   object ob;
   
   if( environment() )
   {
      if( sizeof( all_inventory( this_object() ) ) )
      {
         foreach( ob in all_inventory( this_object() ) )
         {
            ob->move( environment() );
         }
      }
   }   
   ::dest_me();
} /* dest_me() */


string query_msgin()  {
   return "$N creep$s in from $F.";
} /* query_msgin() */


string query_msgout()  {
   return "$N creep$s out $T.";
} /* query_msgout() */


int second_life() {
   call_out( "dest_me", 2 );
   return 1;
} /* second_life() */


void setup_player( object ob ) {
   _player = ob;
} /* setup_player() */


object query_my_player() { return _player; }


int do_grab( object *, string, string, mixed *args ) {

   /* Ok, in theory args[1] will contain the place to go to... */

   tell_creator( this_player(), "Args: %O\n", args );
   
   if( _heading != HAND_STOPPED )
   {
      return notify_fail( "You have already given the hand an order.\n" );
   }
   
   // dir   = args[ 1 ];
   // bits  = ( explode( args[ 0 ], " " ) - ({ "" }) );
   
   _heading = HAND_GOING_OUT;

   call_out( "go_to_dest", 1, args[ 0 ], args[ 1 ] );
   
   this_player()->add_succeeded_mess( this_object(),
      "$N send$s $D off on an errand.\n", ({ }) );

   return 1;

} /* do_grab() */


void go_to_dest( string what, string where )  {

   string here, there, dest;

   tell_creator( _player, "Attempting to move to destination...\n" );
   
   here  = file_name( environment() );

   dest = environment()->query_destination( where );
   
   if( !dest || !find_object( dest ) || !do_command( where ) )
   {
      tell_object( _player, "A sense of confusion briefly flows back "
        "through your link with the hand.  It appears to be "
        "unable to find a way there.\n" );
      tell_room( environment(), this_object()->one_short() +
         " looks dazed and confused as it disintegrates.\n" );
      call_out( "dest_me", 2 );
      return;
   }
   else
   {
      there = file_name( find_object( dest ) );
      call_out( "fetch_objects", 4, what, there, here );
   }

} /* go_to_dest() */


void fetch_objects( string what, string destination, string origin )
{
   // We haven't arrived to the right destination.

   tell_creator( _player, "Attempting to fetch objects...\n" );
   
   if( !environment() || file_name( environment() ) != destination )
   {
      tell_object( _player, "A sense of confusion briefly flows back "
        "through your link with the hand.  It appears to be "
        "unable to find a way there.\n" );
      tell_room( environment(), this_object()->one_short() +
         " looks dazed and confused as it disintegrates.\n" );
      call_out( "dest_me", 2 );
      return;
   }

   // Let's try to get what we came for.
   
   if( !do_command( "get " + what ) )
   {
      tell_object( _player, "A sense of confusion briefly flows back "
         "through your link with the hand.  " );
      
      if( !sizeof( match_objects_for_existence( what, environment() ) ) )
      {
         tell_object( _player, "It appears to be unable to find what you "
            "asked.\n" );
      }
      else
      {
         tell_object( _player, "It appears to be unable to lift what you "
            "asked.\n" );
      }
      
      call_out( "dest_me", 2 );
      return;
   }
   
   tell_creator( _player, "Hand inventory: %O\n",
      all_inventory() );
      
   call_out( "return_back", 1, what, origin );
   
} /* fetch_objects() */


void return_back( string what, string origin )
{
   string exit, exit_to_use;
   object destination;
   
   tell_creator( _player, "Attempting to return back...\n" );
   
   _heading = HAND_COMING_BACK;
   exit_to_use = 0;
   
   foreach( exit in environment()->query_exits() )
   {
      destination = find_object( environment()->query_destination( exit ) );
      if( destination && file_name( destination ) == origin )
      {
         exit_to_use = exit;
         break;
      }
   }
   
   if( !exit_to_use || !do_command( exit_to_use ) )
   {
      tell_object( _player, "A sense of confusion briefly flows back "
        "through your link with the hand.  It appears to be "
        "unable to find a way back.\n" );
      tell_room( environment(), this_object()->one_short() +
         " looks dazed and confused as it disintegrates.\n" );
      call_out( "dest_me", 2 );
      return;
   }

   call_out( "return_items", 4, what );
   
} /* return_back() */


void return_items( string what )
{
   tell_creator( _player, "Attempting to return items...\n" );
   
   if( _player )
   {
      if( environment( _player ) != environment() || !_player->query_visible( this_object() ) )
      {
         tell_object( _player, "A sense of sadness briefly flows back "
            "through your link with the hand.  It appears the hand "
            "can't find you.\n" );
         tell_room( environment(), this_object()->one_short() +
            " looks sad and forlorn as it disintegrates.\n" );
         call_out( "dest_me", 2 );
         return;
      }
      
      if( do_command( "give " + what + " to " + _player->query_name() ) )
      {
         tell_room( environment(), this_object()->one_short() +
            " disintegrates happily.\n" );
      }
      else
      {
         tell_room( environment(), this_object()->one_short() +
            " looks ashamed as it disintegrates into nothingness.\n" );
      }
      
      call_out( "dest_me", 2 );

   }
} /* return_items() */


string owner_present()  {
   if ( _player && environment() == environment( _player ) )  {
      return "It looks curiously at " + _player->one_short() + ".\n";
   }
   else  {
      return "\n";
   }
} /* owner_present() */
   

void event_exit( object ob ) {
  if ( ob == _player && _heading == HAND_STOPPED )  {
      tell_room( environment(), this_object()->one_short() + " looks "
                "hurt as its owner abandons it.  It crumbles into a sad "
                "little pile of dust.\n" );
      tell_object( _player, "A brief sense of rejection comes through "
                  "your link with the hand as you abandon it.\n");
      call_out( "dest_me", 2 );
  }
} /* event_exit() */

