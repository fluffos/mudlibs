inherit NPC_OBJ;

int oeid;
object owner;
mapping knockers;

void setup() {
   set_name( "cloud" );
   set_short( "small rain cloud" );
   add_adjective( ({ "small", "rain" }) );
   set_main_plural( "small rain clouds" );
   set_long( "This small cloud is floating in the air, occationally letting a "
            "few drops of rain fall.\n" );

   add_property( "non-solid", 1 );
   add_property( "floating", 1 );

   add_extra_look( this_object() );
   basic_setup("elemental", 1, 0 );
   set_height( 10 );
   set_base_weight( 1 );
   knockers = ([ ]);
} /* setup() */

string extra_look( object thing ) {
   if ( !objectp( owner ) )
      return "It seems to be floating around, following whatever wind is "
             "here.\n";
   return "It seems to be mostly floating around over "+
         (string)owner->the_short() +".\n";
} /* extra_look() */

int attack_by( object thing ) {
   if ( thing ) {
      knockers[ thing ]++;
      if ( knockers[ thing ] > 5 ) {
         tell_object( thing, "You get fed up with seeing all your blows "
                     "passing harmlessly though the cloud, so you stop "
                     "fighting it.\n" );
         thing->stop_fight( this_object() );
         map_delete( knockers, thing );
         return 0;
      }
   }
   return 1;
} /* attack_by() */

void attack_ob( object thing ) { return; }

int query_ac( string type, int amount, string zone ) {
   if ( type != "magic" )
      return amount;
   return ::query_ac( type, amount, zone );
} /* query_ac() */

int query_oeid() { return oeid; }
object query_owner() { return owner; }

void set_owner( object thing, int number ) {
   owner = thing;
   oeid = number;
   owner->add_follower( this_object() );
} /* set_owner() */

void go_away() {
   if ( objectp( owner ) ) {
      owner->remove_follower( this_object() );
      if ( environment( owner ) == environment() )
         tell_object( owner, "Your small cloud dissipates.\n" );
      tell_room( environment(), "The small cloud dissipates.\n",
            owner );
   } else
      tell_room( environment(), "The small cloud dissipates.\n" );
   oeid = -1;
   move( "/room/rubbish" );
} /* go_away() */

void init() {
   ::init();
   if ( !objectp( owner ) && ( oeid != -1 ) )
      call_out( "go_away", 0 );
} /* init() */

void event_exit( object thing, string mess, object dest ) {
   ::event_exit( thing, mess, dest );
   if ( thing != owner )
      return;
   if ( find_call_out( "check_owner" ) == -1 )
      call_out( "check_owner", 2 );
} /* event_exit() */

void check_owner() {
   if ( !objectp( owner ) ) {
      go_away();
      return;
   }
   if ( environment() != environment( owner ) ) {
      move( environment( owner ), "$N slowly form$s in mid-air.",
            "$N slowly dissipate$s." );
      owner->add_follower( this_object() );
   }
} /* check_em() */

void do_rain() {
   if ( !objectp( owner ) ) {
      go_away();
      return;
   }
   if ( environment() == environment( owner ) ) {
      if ( environment( owner ) == environment() ) {
         tell_object( owner, "A few drops of rain fall on you.\n" );
         /* the rain of pishe ignores umbrellas */
         owner->add_effect("/std/effects/other/wetness", 15 );
      }
      tell_room( environment(), "A few drops of rain fall from the cloud.\n",
            owner );
   }
} /* do_rain() */

int second_life() {
   if ( objectp( owner ) )
      owner->delete_effect( (int)owner->sid_to_enum( oeid ) );
   else
      go_away();
   return 1;
} /* second_life() */
