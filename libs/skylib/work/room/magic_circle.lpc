/* By Gruper, May 98 */

#define SKILL "magic.spells.special"
#define DEF_SKILL "magic.spells.defensive"

object outside_circle;

void setup() {
   set_short( "inside the magic circle" );
   set_long( "This is a magic circle.  It will stop any magic trying to "
         "go through it, as well as many other things, until it is "
         "\"dispel\"led.\n" );
   add_item( "magic circle", "The circle doesn't look like much; just "
         "an uneven line in the dust." );
   add_property( "no teleport", 1 );
   add_property( "magic circle", 1 );
   add_property( "determinate", "" );
}

void init() {
   this_player()->add_command( "dispel", this_object(), "circle" );
   ::init();
}

string query_death_reason() {
   return "trying to dispel an overcharged magic circle";
}

string query_quit_handler() {
   if( !outside_circle )
      return 0;

   if( query_verb() == "quit" )
      this_player()->move( outside_circle, "", "$N leave$s the game." );

   if( outside_circle->query_quit_handler() )
      return outside_circle->query_quit_handler();
   else
      return file_name( outside_circle );
}

string query_owner() { return outside_circle->query_owner(); }

int query_power() { return outside_circle->query_power(); }

void set_outside_circle( object ob ) { outside_circle = ob; }

object query_outside_circle() { return outside_circle; }

int query_keep_room_loaded() {
   return 1;
}

int dont_free() {
   return 1;
}

object query_circle() {
   return this_object();
}

int do_dispel() {
   int bonus, damage;

   if( !outside_circle )
      return notify_fail( "FZZZZT\n" );

   bonus = this_player()->query_skill_bonus( SKILL );
   if( this_player()->query_name() == outside_circle->query_owner() )
      bonus *= 4;

   damage = query_power() - bonus;
   damage -= this_player()->query_ac( "magic", damage );

   if( damage > 0 ) {
      this_player()->adjust_hp( -damage );
      if( this_player()->query_hp() < 1 )
         this_player()->attack_by( this_object() );

      tell_room( this_object(), "As "+ this_player()->one_short() +" tries "
            "to cross the boundary of the magic circle, a flash of "
            "occult energy forces "+ this_player()->query_objective()
            +" back.\n",
            this_player() );
      return notify_fail( "A flash of occult energy forces you back "
            "from the boundary of the magic circle.\n" );
   }
   if( (bonus/2 + random(bonus)) > query_power() ) {
      outside_circle->dispel_circle();
   } else {
      return notify_fail( "You are not strong enough to dispel the "
            "magic circle.\n" );
   }

   this_player()->add_succeeded_mess( this_object(),
         "$N $V the magic circle.\n", ({ }) );
   return 1;
}

void dispel_circle() {
   if( outside_circle )
      outside_circle->dispel_circle();
}

void event_person_say( object person, string start, string rest, string
      language ) {

   if( !outside_circle )
      return;

   if( start[ 0..3 ] == "the " )
      start = explode( (string)person->a_short(), " " )[ 0 ] +
            start[ 3 .. strlen( start ) - 1 ];

   all_inventory( outside_circle )->event_person_say( person,
         "Inside the circle, "+ start, rest, language );

} /* event_person_say() */

/* No event_exit/enter here since only way to leave
 * should be via the one exit to the outside. */
