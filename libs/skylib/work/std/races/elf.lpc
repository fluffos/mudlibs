inherit "/std/races/humanoid";

void setup() {
   set_long( "The elves are a tall, bloodthirsty, murderous, evil race, "
      "but they have style.\n" );
   set_name( "elf" );
   set_height( 200 );
   set_weight( 1400 );

   set_sight( ({ -10, 0, 150, 200 }) );
   set_stats( ({ -2, 4, -2, -2, -2 }) );
} /* setup() */

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
      return "A tall elvish lad who'll probably whip out a bronze sword "
         "and cut off your head soon to see the pretty patterns the "
         "spurting blood makes.\n";

   return "A tall elvish lass who'll probably whip out a bronze dagger "
      "and slit your throat to see the pretty patterns the blood makes.\n";
} /* query_desc() */
