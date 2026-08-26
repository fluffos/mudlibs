inherit "/std/races/reptile_base";

void setup() {
   set_name( "grflx" );
   set_long( "A large scaled reptile, very big but very fast and very "
      "mean.\n" );
   set_height( 500 );
   set_weight( 5000 );

   remove_bit( "torso" );
   remove_bit( "skin" );

   add_bit( "torso", "body", ({ 0, 500, 0,
      "heart", "liver", "left kidney", "right kidney", "left lung",
      "right lung", "spleen", "intestine", "pancreas", "scale" }) );
   add_bit( "scale", "scale", ({ "torso", 1,
      ({ "/obj/armours/grflx_scale.arm", 1 }) }) );
   inedible += ({ "scale" });

   add_ac( "blunt", "blunt", 50 );
   add_ac( "pierce", "pierce", 20 );
   add_ac( "sharp", "sharp", 20 );

   set_stats( ({ 8, 10, -6, 10, -6 }) );
} /* setup() */

string query_desc( object thing ) {
   return "A blur of deadly motion.  You suspect that " +
         (string)thing->query_pronoun() + " is a grflx.\n";
} /* query_desc() */

void start_player( object thing ) {
   ::start_player( thing );
   thing->set_combat_response("dodge");
   thing->set_combat_attitude("offensive");
} /* start_player() */
