inherit NPC_OBJ;

int oeid;
object owner;
mapping knockers;

void setup() {
   set_name( "eye" );
   set_short( "floating eye" );
   add_adjective( "floating" );
   set_main_plural( "floating eyes" );
   set_long( "This slightly decayed eye hovers nearby.  It looks at you "+
         "balefully, but with little interest.\n" );
   basic_setup("elemental", 1, 0 );
   set_height( 2 );
   set_base_weight( 1 );
   adjust_bonus_dex( 25 );
   knockers = ([ ]);
   add_property( "wizard eye", 50 );
   add_property( "floating", 1 );
   add_property( "no fleas", 1 );
} /* setup() */

int attack_by( object thing ) {
   if ( thing ) {
      knockers[ thing ]++;
      if ( knockers[ thing ] > 5 ) {
         tell_object( thing, "You get fed up with seeing "+ the_short() +
               " dodge aside, so you stop fighting it.\n" );
         thing->stop_fight( this_object() );
         map_delete( knockers, thing );
         return 0;
      }
   }
   return 1;
} /* attack_by() */

void attack_ob( object thing ) { return; }

int query_unambushable() { return 1; }

void do_ambushed() {
   write( "The eye quickly floats out of reach.\n" );
   say( "The eye quickly floats away from "+
         (string)this_player()->one_short() +".\n" );
} /* do_ambushed() */

int query_skill_bonus( string word ) {
   if ( sscanf( word, "%*sdodging%*s" ) == 2 )
      return 1000000;
   return ::query_skill_bonus( word );
} /* query_skill_bonus() */

int query_oeid() { return oeid; }
object query_owner() { return owner; }
int query_slave() { return objectp( owner ); }

void set_owner( object thing, int number ) {
   owner = thing;
   oeid = number;
} /* set_owner() */

void go_away() {
   if ( objectp( owner ) )
      tell_object( owner, "You lose contact with your eye.\n" );
   tell_room( environment(), the_short() +" falls apart, crumbling "
         "into dust.\n", this_object() );
   owner = 0;
   move( "/room/rubbish" );
} /* go_away() */

int second_life() {
   if ( objectp( owner ) )
      owner->delete_effect( (int)owner->sid_to_enum( oeid ) );
   else
      go_away();
   return 1;
} /* second_life() */

void add_message( string message, mixed *things ) {
   string bit;
   if ( objectp( owner ) ) {
      sscanf( message, "$P$%s$P$", bit, message );
      message = "$I$ 6,6=(eye) $C$"+
            evaluate_message( reform_message( message, things ) ) +
            "$I$ -6,-6=";
      if ( stringp( bit ) )
         message = "$P$"+ bit +"$P$"+ message;
      owner->add_message( message, ({ }) );
   } else
      call_out( "go_away", 0 );
} /* add_message() */

void event_person_say( object thing, string start, string mess, string lang ) {
   add_message( "$C$$0$ opens and closes "+ (string)thing->query_possessive() +
         " mouth.\n", ({ ({ "my_one_short:"+ file_name( thing ) }) }) );
} /* event_person_say() */

void event_person_shout( object thing, string start, string mess,
      string lang ) {
   if ( environment( thing) != environment() )
      return;
   add_message( "$C$$0$ opens and closes "+ (string)thing->query_possessive() +
         " mouth.\n", ({ ({ "my_one_short:"+ file_name( thing ) }) }) );
} /* event_person_shout() */
