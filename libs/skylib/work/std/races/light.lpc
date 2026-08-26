/* Race object for small lights */

inherit "/std/races/base";

void setup() {
   set_name( "light" );
   set_long( "A small sphere of magical blue light.\n" );
   set_weight( 1 );
   set_height( 1 );
   set_desc( "a small ball of blue light hovering in the air." );
   
   /* throw away the human bits and replace totally */
   bits = ({ });
   inedible = ({ });
   unrottable = ({ });

   set_stats( ({ 0, 14, -6, -6, -6 }) );
}  /* setup() */

void start_player( object thing ) {
   ::start_player( thing );
   thing->set_combat_response("dodge");
} /* start_player() */
