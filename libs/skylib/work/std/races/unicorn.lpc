inherit "/std/races/base";

void setup() {
   set_name( "unicorn" );
   set_long( "The unicorn is a creature that looks like a large horse, with "
             "a long horn on it's forehead.\n" );
   set_desc( "a large, hairy quadruped.  It looks like a horse with a large "
      "horn" );
   set_height( 250 );
   set_weight( 9000 );

   bits= ({
      "head", "head", ({ 0, 120, 0,
         "left eye", "right eye", "skull", "brain", "left ear",
         "right ear", "tongue", "horn" }),
      "left eye", "eye", ({ "head", 2, 0 }),
      "right eye", "eye", ({ "head", 2, 0 }),
      "skull", "cranium", ({ "head", 45, 0, "teeth" }),
      "brain", "brain", ({ "head", 20, 0 }),
      "left ear", "ear", ({"head", 4, 0 }),
      "right ear", "ear", ({"head", 4, 0 }),
      "teeth", "teeth", ({ "skull", 5, ({"/std/bit_set", 1}) }),
      "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 18}) }),
      "tongue", "tongue", ({ "head", 9, 0 }),
      "horn", "horn", ({ "head", 20, 0 }),
      "neck", "neck", ({ 0, 120, 0 }),
      "torso", "body", ({ 0, 400, 0,
         "heart", "liver", "left kidney", "right kidney", "left lung",
         "right lung", "spleen", "intestine", "pancreas" }),
      "heart", "heart", ({ "torso", 35, 0 }),
      "liver", "liver", ({ "torso", 35, 0 }),
      "left kidney", "kidney", ({ "torso", 20, 0 }),
      "right kidney", "kidney", ({ "torso", 20, 0 }),
      "left lung", "lung", ({ "torso", 35, 0 }),
      "right lung", "lung", ({ "torso", 35, 0 }),
      "spleen", "spleen", ({ "torso", 20, 0 }),
      "intestine", "gut", ({ "torso", 75, 0 }),
      "pancreas", "pancreas", ({ "torso", 20, 0 }),
      "left front leg", "leg", ({ 0, 140, 0, "left front hoof" }),
      "left front hoof", "hoof", ({ "left front leg", 20, 0 }),
      "right front leg", "leg", ({ 0, 140, 0, "right front hoof" }),
      "right front hoof", "hoof", ({ "right front leg", 20, 0 }),
      "left rear leg", "leg", ({ 0, 160, 0, "left rear hoof" }),
      "left rear hoof", "hoof", ({ "left rear leg", 20, 0 }),
      "right rear leg", "leg", ({ 0, 160, 0, "right rear hoof" }),
      "right rear hoof", "hoof", ({ "right rear leg", 20, 0 }),
      "tail", "tail", ({ 0, 15, 0 }),
      "skin", "skin", ({ 0, 175, 0 })
   });
   
   inedible = ({ "skull", "left front hoof", "right front hoof",
      "left rear hoof", "right rear hoof", "tail", "teeth", "tooth",
      "skin", "horn" });
   unrottable = ({ "skull", "left front hoof", "right front hoof",
      "left rear hoof", "right rear hoof", "teeth", "tooth", "horn" });

   add_ac( "blunt", "blunt", 60 );
   add_ac( "sharp", "sharp", 40 );
   add_ac( "pierce", "pierce", 40 );
   set_skin( "skin" );

   set_stats( ({ 10, 10, -4, 10, -4 }) );
}  /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "hoof" );
   thing->remove_attack( "chew" );
   thing->remove_attack( "horn" );

   thing->add_attack( "hoof", 80, ({ 6 * number, 5, 4 * number }), 
      "blunt", "unarmed", 0 );
   thing->add_attack( "chew", 50, ({ 4 * number, 3, 2 * number }),
      "sharp", "unarmed", 0 );
   thing->add_attack( "horn", 70, ({ 8 * number, 5, 4 * number }), 
      "pierce", "unarmed", 0 );

   thing->add_attack_message( "horn", "pierce", ({
      20, ({
        "You prod $hcname$ with your horn.\n",
        "$mcname$ prods you with $mposs$ horn.\n",
        "$mcname$ prods $hcname$ with $mposs$ horn.\n" }),
      60, ({
        "You poke $hcname$ with your horn.\n",
        "$mcname$ pokes you with $mposs$ horn.\n",
        "$mcname$ pokes $hcname$ with $mposs$ horn.\n" }),
      100, ({
        "You jab your horn into $hcname$.\n",
        "$mcname$ jabs $mposs$ horn into you.\n",
        "$mcname$ jabs $mposs$ horn into $hcname$.\n" }),
      140, ({
        "You pierce $hcname$ deeply with your horn.\n",
        "$mcname$ pierces you deeply with $mposs$ horn.\n",
        "$mcname$ pierces $hcname$ deeply with $mposs$ horn.\n" }),
      180, ({
        "You ram $hcname$ with your horn.\n",
        "$mcname$ rams you with $mposs$ horn.\n",
        "$mcname$ rams $hcname$ with $mposs$ horn.\n" }),
      220, ({
        "You gore $hcname$ with your horn.\n",
        "$mcname$ gores you with $mposs$ horn.\n",
        "$mcname$ gores $hcname$ with $mposs$ horn.\n" }),
      0, ({
        "You impale $hcname$ with your horn.\n",
        "$mcname$ impales you with $mposs$ horn.\n",
        "$mcname$ impales $hcname$ with $mposs$ horn.\n" })
   }) );

   thing->set_combat_response("dodge");
   thing->set_combat_attitude("offensive");
} /* set_unarmed_attacks() */


string query_determinate( object ) {
   return "a ";
} /* query_determinate() */
