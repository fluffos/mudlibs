// Slice Humans.
// Thirteen fingers.
// Thirteen toes.
// And stupid.

inherit "/std/races/humanoid";

void setup() {
   set_name( "human" );
   set_weight( 1600 );
   set_height( 175 );
   set_long( "Humans from Slice are rather in-bred, resulting in "
             "deformity and stupidity.\n" );

   add_ac( "blunt", "blunt", 15 );
   add_ac( "pierce", "pierce", 12 );
   add_ac( "sharp", "sharp", 10 );

   add_attack( "hands", 75, ({ 21, 8, 11 }) );
   add_attack( "feet", 25, ({ 32, 10, 11 }) );

   remove_bit( "left hand" );
   remove_bit( "right hand" );
   remove_bit( "left foot" );
   remove_bit( "right foot" );

   add_bit( "left hand", "hand", ({ "left arm", 15, 0,
      "left little finger", "left third finger", "left index finger",
      "left ring finger", "left sixth finger", "left seventh finger",
      "left thumb" }) );
   add_bit( "left sixth finger", "finger", ({ "left hand", 1, 0 }) );
   add_bit( "left seventh finger", "finger", ({ "left hand", 1, 0 }) );
   add_bit( "right hand", "hand", ({ "right arm", 15, 0,
      "right little finger", "right third finger", "right index finger",
      "right ring finger", "right sixth finger", "right thumb" }) );
   add_bit( "right sixth finger", "finger", ({ "right hand", 1, 0 }) );
   add_bit( "left foot", "foot", ({ "left leg", 50, 0,
      "left big toe", "left second toe", "left third toe",
      "left fourth toe", "left fifth toe", "left sixth toe",
      "left little toe" }) );
   add_bit( "left fifth toe", "toe", ({ "left foot", 1, 0 }) );
   add_bit( "left sixth toe", "toe", ({ "left foot", 1, 0 }) );
   add_bit( "right foot", "foot", ({ "right leg", 50, 0,
      "right big toe", "right second toe", "right third toe",
      "right fourth toe", "right fifth toe", "right little toe" }) );
   add_bit( "right fifth toe", "toe", ({ "right foot", 1, 0 }) );

   set_sight( ({ 5, 20, 200, 300 }) );
   set_stats( ({ 0, -2, -2, 0, -4 }) );
} /* setup() */

string query_race() {
   return "human";
} /* query_race() */