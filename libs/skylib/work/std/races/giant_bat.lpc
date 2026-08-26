inherit "/std/races/base";

void setup() {
   set_name( "giant bat" );
   set_long( "A large flying mammal.\n" );
   set_height( 100 );
   set_weight( 700 );

   bits= ({
      "head", "head", ({ 0, 135, 0,
         "left eye", "right eye", "skull", "left ear", "right ear", "tongue" }),
      "left eye", "eye", ({ "head", 2, 0 }),
      "right eye", "eye", ({ "head", 2, 0 }),
      "skull", "cranium", ({ "head", 45, 0, "teeth", "brain" }),
      "brain", "brain", ({ "skull", 27, 0 }),
      "left ear", "ear", ({"head", 4, 0 }),
      "right ear", "ear", ({"head", 4, 0 }),
      "teeth", "teeth", ({ "skull", 5, ({"/std/bit_set", 1}) }),
      "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 28}) }),
      "tongue", "tongue", ({ "head", 9, 0 }),
      "torso", "body", ({ 0, 500, 0,
         "heart", "liver", "left kidney", "right kidney", "left lung",
         "right lung", "spleen", "intestine" }),
      "heart", "heart", ({ "torso", 45, 0 }),
      "liver", "liver", ({ "torso", 45, 0 }),
      "left kidney", "kidney", ({ "torso", 27, 0 }),
      "right kidney", "kidney", ({ "torso", 27, 0 }),
      "left lung", "lung", ({ "torso", 45, 0 }),
      "right lung", "lung", ({ "torso", 45, 0 }),
      "spleen", "spleen", ({ "torso", 27, 0 }),
      "intestine", "gut", ({ "torso", 90, 0 }),
      "left wing", "wing", ({ 0, 170, 0, "left wing claw" }),
      "left wing claw", "claw", ({ 0, 8, 0 }),
      "right wing", "wing", ({ 0, 170, 0, "right wing claw" }),
      "right wing claw", "claw", ({ 0, 8, 0 }),
      "left leg", "leg", ({ 0, 180, 0, "left leg claws" }),
      "left leg claws", "claws", ({ "left leg", 27, ({"/std/bit_set", 1}),
         "claw" }),
      "claw", "claw", ({ "left leg claws", 6, ({"/std/bit", 4}) }),
      "right leg", "leg", ({ 0, 180, 0, "right leg claws" }),
      "right leg claws", "claws", ({ "right leg", 27, ({"/std/bit_set", 1}),
         "claw" }),
      "claw", "claw", ({ "left leg claws", 6, ({"/std/bit", 4}) }),
      "skin", "skin", ({ 0, 175, 0 })
   });

   inedible = ({ "skull", "tooth", "teeth", "left leg claws",
      "right leg claws", "left wing claw", "right wing claw", "claw",
      "left wing", "right wing", "skin" });
   unrottable = ({ "skull", "tooth", "teeth", "left leg claws",
      "right leg claws", "left wing claw", "right wing claw", "claw" });
   set_desc( "a large flappy thing, quite bat-like" );

   add_ac( "blunt", "blunt", 10 );
   add_ac( "sharp", "sharp", 10 );
   add_ac( "pierce", "pierce", 10 );
   set_skin( "skin" );

   set_sight( ({ -20, 0, 80, 120 }) );
   set_stats( ({ 5, 10, 0, 8, 0 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "chew" );
   thing->remove_attack( "claws" );

   thing->add_attack( "chew", 50, ({ 2 * number, 2, 2 * number }),
      "sharp", "unarmed", 0 );
   thing->add_attack( "claws", 70, ({ number, 5, 2 * number }),
      "sharp", "unarmed", 0 );

   thing->set_combat_response("dodge");
} /* set_unarmed_attacks() */
