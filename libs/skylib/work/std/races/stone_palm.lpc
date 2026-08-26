#include <bit.h>

#define SHADOW "/std/races/shadows/troll_race"

inherit "/std/races/base";

void setup() {
   set_name( "stone palm" );
   set_long( "Stone palms look like normal palm trees, but seem related to "
      "trolls.\n" );
   set_height( 300 );
   set_weight( 40000 );
   set_desc( "a palm tree apparantly made from stone" );
   set_skin( "bark" );

   bits = ({
      "trunk", "trunk", ({ 0, 1000, 0, "leaf", "nut" }),
      "leaf", "leaf", ({ "trunk", 100, ({"/std/bit", 6}) }),
      "nut", "nut", ({ "trunk", 35, ({"/std/bit", 4}) }) 
   });

/*
** Actually, it'd be nice to have all of these made of stone, so that
** stone-eaters (e.g. other trolls) can still eat them, but until then...
*/
   inedible = ({ "trunk", "leaf", "nut" });
   unrottable = ({ });

   add_ac( "blunt", "blunt", 50 );
   add_ac( "pierce", "pierce", 15 );
   add_ac( "sharp", "sharp", 25 );

   set_sight( ({ 0, 5, 100, 125 }) );
   set_stats( ({ 14, -8, -4, 12, 2 }) );
} /* setup() */

void start_player( object thing ) {
   ::start_player( thing );
   clone_object( SHADOW )->setup_shadow( thing );
} /* start_player() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "leaf" );
   thing->remove_attack( "nut" );

   thing->add_attack( "leaf", 80, ({ 3 * number, 5, 4 * number }), 
         "blunt", "unarmed" );
   thing->add_attack( "nut", 50, ({ 4 * number, 3, 3 * number }),
         "blunt", "unarmed" );

   thing->add_attack_message( "leaf", "blunt", ({
      20, ({
         "You prod $hcname$ with one of your leaves.\n",
         "$mcname$ prods you with one of $mposs$ leaves.\n",
         "$mcname$ prods $hcname$ with one of $mposs$ leaves.\n" }),
      100, ({
         "You bash $hcname$ hard with one of your leaves.\n",
         "$mcname$ bashes you hard with one of $mposs$ leaves.\n",
         "$mcname$ bashes $hcname$ hard with one of $mposs$ leaves.\n" }),
      180, ({
         "You mash $hcname$ with one of your leaves.\n",
         "$mcname$ mashes you with one of $mposs$ leaves.\n",
         "$mcname$ mashes $hcname$ with one of $mposs$ leaves.\n" }),
      0, ({
         "You beat $hcname$ into a pulp with one of your leaves.\n",
         "$mcname$ beats you into a pulp with one of $mposs$ leaves.\n",
         "$mcname$ beats $hcname$ into a pulp with one of $mposs$ "
            "leaves.\n" })
   }) );

   thing->add_attack_message( "nut", "blunt", ({
      100, ({
         "You drop a stone nut on $hcname$'s head.\n",
         "$mcname$ drops a stone nut on your head.\n",
         "$mcname$ drops a stone nut on $hcname$'s head.\n" }),
      160, ({
         "You fling a stone nut at $hcname$ with incredible force.\n",
         "$mcname$ flings a stone nut at you with incredible force.\n",
         "$mcname$ flings a stone nut at $hcname$ with incredible "
            "force.\n" }),
      0, ({
        "You hurl a stone nut at $hcname$.  There is a cracking noise from "
           "$hposs$ head.\n",
        "$mcname$ hurls a stone nut at you.  There is a cracking noise from "
           "your head.\n",
        "$mcname$ hurls a stone nut at $hcname$.  There is a cracking noise "
           "from $hposs$ head.\n" })
      }) );
} /* set_unarmed_attacks() */
