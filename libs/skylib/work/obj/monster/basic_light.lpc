#include <position.h>

#define ANTI_LIGHT_SPELL "/obj/spells/anti-light"

inherit NPC_OBJ;

object owner;
mapping knockers;
int going_away;

void create() {
   ::create();
   add_extra_look( this_object() );
   basic_setup("elemental", 1, 0);
   set_height( 10 );
   set_base_weight( 1 );
   adjust_bonus_dex( 25 );
   knockers = ([ ]);
   add_property( "no fleas", 1 );
   add_property( "floating", 1 );
   set_cannot_change_position(1);
   set_default_position( ({ "zipping about" }) );
   return_to_default_position(1);
} /* create() */

string extra_look( object thing ) {
   if ( !objectp( owner ) )
      return "It seems to be zipping about rather aimlessly.\n";
   return "It seems to be mostly zipping about "+
         (string)owner->the_short() +".\n";
} /* extra_look() */

int attack_by( object thing ) {
  if(!userp(thing)) {
    this_object()->stop_fight(thing);
    return 1;
  }

  if ( thing ) {
    knockers[ thing ]++;
    if ( knockers[ thing ] > 5 ) {
      tell_object( thing, "You get fed up with seeing "+ the_short() +
                  " dodge aside, so you stop fighting it.\n" );
      thing->stop_fight( this_object() );
      map_delete( knockers, thing );
      return 0;
    } else
      call_out( "zap_bugger", 1, thing );
  }
  return 1;
} /* attack_by() */

void zap_bugger( object thing ) {
   int damage;
   if ( !thing )
      return;
   if ( environment( thing ) != environment() )
      return;
   tell_object( thing, "A small bolt of lightning shoots from "+
         the_short() +" and hits you on the arm.\n" );
   tell_room( environment(), "A small bolt of lightning shoots from "+
         the_short() +" and hits "+ (string)thing->the_short() +
         " on the arm.\n", thing );
   damage = roll_MdN( 5, 40 );
   damage -= (int)thing->query_ac( "lightning", damage, "arms" );
   thing->adjust_hp( -damage, this_object() );
   thing->attack_by( this_object() );
} /* zap_bugger() */

void attack_ob( object thing ) { return; }

int query_skill_bonus( string word ) {
   string temp;
   if ( sscanf( word, "%sdodging%s", temp, temp ) == 2 )
      return 1000000;
   return ::query_skill_bonus( word );
} /* query_skill_bonus() */

int query_ac( string type, int amount, string zone ) {
   if ( type != "magic" )
      return amount;
   return ::query_ac( type, amount, zone );
} /* query_ac() */

object query_owner() { return owner; }

void set_owner( object thing ) {
   owner = thing;
   owner->add_follower( this_object() );
} /* set_owner() */

void go_away() {
   if ( objectp( owner ) ) {
      owner->remove_follower( this_object() );
      if ( environment( owner ) == environment() )
         tell_object( owner, "Your small blue light crumples to dust.\n" );
      tell_room( environment(), "The small blue light crumples to dust.\n",
            owner );
   } else {
      tell_room( environment(), "The small blue light crumples to dust.\n" );
   }
   move( "/room/rubbish" );
} /* go_away() */

void remove_effect() {
   if( objectp( owner ) )
      ANTI_LIGHT_SPELL->spell_succeeded( owner, ({ this_object() }), 500 );
}

int do_shoo() {
   if( this_player() == owner ) {
      call_out( (: remove_effect :), 2 );
      this_player()->
         add_succeeded_mess( this_object(), "$N $V $D away.\n", ({ }) );
      return 1;
   } else {
      return 0;
   }
}

void init() {
   ::init();
   if( !(objectp( owner ) || going_away) ) {
      going_away = 1;
      call_out( "go_away", 0 );
   } else {
      if( this_player() == owner )
         this_player()->add_command( "shoo", this_object() );
   }
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
   if ( environment() != environment( owner ) &&
        environment() != find_object( "/room/rubbish" ) ) {
      move( environment( owner ), "$N dart$s into the area and zip$s around "+
            (string)owner->the_short() +".",
            "$N zip$s off, leaving a faint smell of ozone." );
      owner->add_follower( this_object() );
   }
} /* check_owner() */
