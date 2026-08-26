inherit "/std/races/humanoid";

void setup() {
   set_long( "The drow are a tall, bloodthirsty, murderous, evil race, "
      "but they have style.\n" );
   set_name( "drow" );
   set_height( 200 );
   set_weight( 1400 );

   set_sight( ({ -100, -80, 80, 100 }) );
   set_stats( ({ -2, 4, 4, -2, -2 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;
   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->add_attack( "hands", 75, ({ 2 * number, 8, number }), "blunt",
         "unarmed", "unarmed_hands" );
   thing->add_attack( "feet", 25, ({ 3 * number, 10, number }), "blunt",
         "unarmed", 0 );
} /* set_unarmed_attacks() */

/*
int query_skill_bonus( int lvl, string skill ) {
   if( skill == "magic.spells" )
      return 4;
   if( skill == "other.covert.stealth" )
      return 5;

   return 0;
}  query_skill_bonus() */

string query_desc( object ob ) {
   if( (int)ob->query_gender() == 1 )
      return "A tall dark elf who'll probably whip out a sword "
         "and cut off your head soon to see the pretty patterns the "
         "spurting blood makes.\n";

   return "A tall dark elf who'll probably whip out a dagger "
      "and slit your throat to see the pretty patterns the blood makes.\n";
} /* query_desc() */
