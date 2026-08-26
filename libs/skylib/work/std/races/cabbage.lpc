/* Cabbage race object. */

inherit "/std/races/base";

void setup() {
   set_name( "cabbage" );
   set_long("A green, leafy vegetable.  Probably full of vitamins and "+
      "minerals, and plenty of roughage.\n" );
   set_height( 20 );
   set_weight( 40 );
   set_desc( "a cute little green-fronded cabbage.  Awww" );
   set_skin( "fronds" );

   /* throw away the human bits and replace totally */
   bits = ({
      "frond", "frond", ({ 0, 100, ({"/std/bit", 10}) }),
      "stalk", "stalk", ({ 0, 500, 0 })
   });
   
   inedible = ({ });
   unrottable = ({ });

   set_stats( ({ -4, -4, -8, -4, -8 }) );
}  /* end setup */

void player_heart_beat( string word, object brassica ) {
   object *caterpillars;

   if( !environment( brassica ) ) {
      return; 
   }
   caterpillars = match_objects_for_existence( "caterpillar", environment( brassica ) );
   if( !sizeof( caterpillars ) ) {
      return;
   }
   if( brassica->caterpillars_here( caterpillars ) ) {
      return;
   }

   brassica->do_command( "gibber" );
   brassica->run_away();
} /* player_heart_beat() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "fronds" );

   thing->add_attack( "fronds", 160, ({ 4 * number, 5, 3 * number }),
      "sharp", "unarmed", 0 );

   thing->add_attack_message( "fronds", "sharp", ({
      50, ({
         "You scratch $hcname$ with a frond.\n",
         "$mcname$ scratches you with a frond.\n",
         "$mcname$ scratches $hcname$ with a frond.\n"}),
      100, ({
         "You jab a sharp frond into $hcname$.\n",
         "$mcname$ jabs a sharp frond into you.\n",
         "$mcname$ jabs a sharp frond into $hcname$.\n"}),
      140, ({
         "You chew on $hcname$'s ankle.\n",
         "$mcname$ chews on your ankle.\n",
         "$mcname$ chews on $hcname$'s ankle.\n"}),
      180, ({
         "You slash $hcname$'s feet with your fronds.\n",
         "$mcname$ slashes your feet with $mposs$ fronds.\n",
         "$mcname$ slashes $hcname$'s feet with $mposs$ fronds.\n"}),
      230, ({
         "You climb onto $hcname$ and cuts $hposs$ belly with a sharp "
            "frond.\n",
         "$mcname$ climbs onto you and cuts your belly with a sharp "
            "frond.\n",
         "$mcname$ climbs onto $hcname$ and cuts $hposs$ with a sharp "
            "frond.\n"}),
      0, ({
         "You bite $hcname$'s legs off!\n",
         "$mcname$ bites your legs off!\n",
         "$mcname$ bites $hcname$'s legs off!\n" })
   }) );

   thing->set_combat_response("dodge");
   thing->set_combat_attitude("offensive");
} /* set_unarmed_attacks() */
