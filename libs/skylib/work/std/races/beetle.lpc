inherit "/std/races/insect_base";
 
void setup() {
   set_name( "beetle" );
   set_desc( "a hard-carapaced insect that scuttles along the ground" );
   set_height( 5 );
   set_weight( 2 );

   add_bit( "left wing cover", "cover", ({ "thorax", 1, 0 }) );
   add_bit( "right wing cover", "cover", ({ "thorax", 1, 0 }) );

   inedible += ({ "left wing cover", "right wing cover" });

   set_stats( ({ -6, 4, -8, -6, -8 }) );
} /* setup() */

void start_player( object thing ) {
   ::start_player( thing );
   thing->set_combat_response("dodge");
   thing->set_combat_attitude("defensive");
} /* start_player() */
