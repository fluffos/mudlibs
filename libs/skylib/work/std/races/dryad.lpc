inherit "/std/races/humanoid";

void setup() {
   set_name( "dryad" );
   set_long( "The dryad race.  They were thought to be extinct until they "
      "were encountered by Rincewind.  The first dryad he encountered was "
      "called Druellae, a shedryad (female).  Male dryads are called "
      "hedryads and they are quite tall and their skin is like the colour "
      "of walnut husks, under which muscles bulge like sacks of melons.  "
      "Female dryads on the other hand have luminous green eyes that have "
      "no pupils and their skin unlike the males is green coloured.  It "
      "must be noted that all dryads wear nothing unless you count the "
      "medallion they wear around their neck.\n" );
   set_weight( 1600 );
   set_height( 175 );

   add_ac( "blunt", "blunt", 60 );
   add_ac( "pierce", "pierce", 60 );
   add_ac( "sharp", "sharp", 50 );

   add_attack( "hands", 75, ({ 45, 8, 11 }) );
   add_attack( "feet", 25, ({ 70, 10, 11 }) );

   set_sight( ({ 5, 20, 200, 300 }) );
   set_stats( ({ 2, 8, -2, 8, -4 }) );
} /* setup() */

string query_desc( object thing ) {
   if( (int)thing->query_gender() == 1 )
      return "He is a string-looking young hedryad.\n";

   return "She is a cute-looking young shedryad.\n";
} /* query_desc() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->add_attack( "hands", 75, ({ 2 * number, 8, number }),
      "blunt", "unarmed", "unarmed_hands" );
   thing->add_attack( "feet", 25, ({ 3 * number, 10, number }),
      "blunt", "unarmed", 0 );
} /* set_unarmed_attacks() */


void start_player( object thing ) {
   ::start_player( thing );
   clone_object( "/std/races/shadows/dryad_race" )->setup_shadow( thing );
} /* start_player() */
