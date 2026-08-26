// Gototh 12/04/98

inherit "/std/races/base";

void setup() {
   set_name( "satyr" );
   set_long( "Half human and half beast; the satyr has a goat's tail, "
      "flanks and hooves.  While the upper part of the body is that of a "
      "human, they also have the horns of a goat.\n" );
   set_desc( "half human and half beast; the satyr has a goat's tail, "
      "flanks and hooves.  While the upper part of the body is that of a "
      "human, they also have the horns of a goat" );
   set_height( 200 );
   set_weight( 3000 );

   bits = ({
      "head", "head", ({ 0, 30, 0,
         "left ear", "right ear", "left eye", "right eye", "nose", "scalp",
         "tongue", "skull", "left horn", "right horn" }),
      "left ear", "ear", ({ "head", 1, 0 }),
      "right ear", "ear", ({ "head", 1, 0 }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "nose", "nose", ({ "head", 1, 0 }),
      "scalp", "scalp", ({ "head", 3, 0 }),
      "tongue", "tongue", ({ "head", 2, 0 }),
      "left horn", "horn", ({ "head", 2, 0 }),
      "right horn", "horn", ({ "head", 2, 0 }),
      "skull", "skull", ({ "head", 15, 0, "teeth", "brain" }),
      "brain", "brain", ({ "skull", 30, 0 }),
      "teeth", "teeth", ({ "skull", 2, ({"/std/bit_set", 1}), "tooth" }),
      "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 32}) }),
      "torso", "chest", ({ 0, 400, 0,
         "heart", "liver", "left kidney", "right kidney", "left lung",
         "right lung", "spleen", "first stomach", "second stomach",
         "third stomach", "fourth stomach", "intestine", "pancreas" }),
      "heart", "heart", ({ "torso", 10, 0 }),
      "liver", "liver", ({ "torso", 10, 0 }),
      "left kidney", "kidney", ({ "torso", 5, 0 }),
      "right kidney", "kidney", ({ "torso", 5, 0 }),
      "left lung", "lung", ({ "torso", 10, 0 }),
      "right lung", "lung", ({ "torso", 10, 0 }),
      "spleen", "spleen", ({ "torso", 5, 0 }),
      "intestine", "gut", ({ "torso", 50, 0 }),
      "pancreas", "pancreas", ({ "torso", 5, 0 }),
      "first stomach", "stomach", ({ "torso", 20, 0 }),
      "second stomach", "stomach", ({ "torso", 20, 0 }),
      "third stomach", "stomach", ({ "torso", 20, 0 }),
      "fourth stomach", "stomach", ({ "torso", 20, 0 }),
      "genitals", "genitals", ({ 0, 5, 0 }),
      "left arm", "arm", ({ 0, 60, 0, "left hand" }),
      "left hand", "hand", ({ "left arm", 10, 0,
         "left little finger", "left third finger", "left index finger",
         "left ring finger", "left thumb"}),
      "left little finger", "finger", ({ "left hand", 1, 0 }),
      "left third finger", "finger", ({ "left hand", 1, 0 }),
      "left index finger", "finger", ({ "left hand", 1, 0 }),
      "left ring finger", "finger", ({ "left hand", 1, 0 }),
      "left thumb", "finger", ({ "left hand", 1, 0 }),
      "right arm", "arm", ({ 0, 60, 0, "right hand" }),
      "right hand", "hand", ({ "right arm", 10, 0,
        "right little finger", "right third finger", "right index finger",
        "right ring finger", "right thumb" }),
      "right little finger", "finger", ({ "right hand", 1, 0 }),
      "right third finger", "finger", ({ "right hand", 1, 0 }),
      "right index finger", "finger", ({ "right hand", 1, 0 }),
      "right ring finger", "finger", ({ "right hand", 1, 0 }),
      "right thumb", "finger", ({ "right hand", 1, 0 }),
      "left front leg", "leg", ({ 0, 150, 0, "left front cloven hoof" }),
      "left front cloven hoof", "hoof", ({ "left front leg", 20, 0 }),
      "right front leg", "leg", ({ 0, 150, 0, "right front cloven hoof" }),
      "right front cloven hoof", "hoof", ({ "right front leg", 20, 0 }),
      "left back leg", "leg", ({ 0, 150, 0, "left back cloven hoof" }),
      "left back cloven hoof", "hoof", ({ "left back leg", 20, 0 }),
      "right back leg", "leg", ({ 0, 150, 0, "right back cloven hoof" }),
      "right back cloven hoof", "hoof", ({ "right back leg", 20, 0 }),
      "tail", "tail", ({ 0, 10, 0 }),
      "skin", "skin", ({ 0, 175, 0 })
   });

   inedible = ({ "skull", "left front cloven hoof",
      "right front cloven hoof", "left back cloven hoof",
      "right back cloven hoof", "tail", "teeth", "tooth", "right horn",
      "left horn", "skull", "skin" });
   unrottable = ({ "skull", "left front cloven hoof",
      "right front cloven hoof", "left back cloven hoof",
      "right back cloven hoof", "tail", "teeth", "tooth", "right horn",
      "left horn", "skull" });
   set_skin( "hide" );

   add_ac( "blunt", "blunt", 80 );
   add_ac( "sharp", "sharp", 70 );
   add_ac( "pierce", "pierce", 50 );

   set_sight( ({ 0, 5, 100, 125 }) );
   set_stats( ({ 2, 8, 0, 6, 0 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt(number) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->remove_attack( "standard" );

   thing->remove_attack( "hoof" );
   thing->remove_attack( "horns" );

   thing->add_attack( "hands", 75, ({ 2 * number, 8, number }), 
      "blunt", "unarmed", "unarmed_hands" );
   thing->add_attack( "hoof", 50, ({ 4 * number, 10, number }), 
      "blunt", "unarmed", 0 );
   thing->add_attack( "horns", 60, ({ 3 * number, 8, number }), 
      "pierce", "unarmed", 0 );
} /* set_unarmed_attacks() */
