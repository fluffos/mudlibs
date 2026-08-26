inherit "/std/races/base";

void setup() {
   set_name( "centaur" );
   set_long( "Half man, half beast, centaurs have the body of a horse and "
      "the torso of a man, with a man's intelligence but fearsome strength "
      "from the powerful horse body.\n" );
   set_desc( "half man, half beast, centaurs have the body of a horse and "
      "the torso and head of a man; subsequently they have the man's "
      "intelligence but fearsome strength from the powerful horse body" );
   set_height( 260 );
   set_weight( 8000 );

   bits = ({
      "head", "head", ({ 0, 20, 0,
         "left ear", "right ear", "left eye", "right eye", "nose", "mane",
         "scalp", "tongue", "skull" }),
      "left ear", "ear", ({ "head", 1, 0 }),
      "right ear", "ear", ({ "head", 1, 0 }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "nose", "nose", ({ "head", 1, 0 }),
      "scalp", "scalp", ({ "head", 1, 0 }),
      "tongue", "tongue", ({ "head", 1, 0 }),
      "skull", "skull", ({ "head", 10, 0, "teeth", "brain" }),
      "brain", "brain", ({ "skull", 20, 0 }),
      "teeth", "teeth", ({ "skull", 2, ({"/std/bit_set", 1}), "tooth" }),
      "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 32}) }),
      "torso", "chest", ({ 0, 500, 0,
         "heart", "liver", "left kidney", "right kidney", "left lung",
         "right lung", "spleen", "first stomach", "second stomach",
         "third stomach", "fourth stomach", "intestine", "pancreas",
         "genitals" }),
      "heart", "heart", ({ "torso", 10, 0 }),
      "liver", "liver", ({ "torso", 5, 0 }),
      "left kidney", "kidney", ({ "torso", 5, 0 }),
      "right kidney", "kidney", ({ "torso", 5, 0 }),
      "left lung", "lung", ({ "torso", 10, 0 }),
      "right lung", "lung", ({ "torso", 10, 0 }),
      "spleen", "spleen", ({ "torso", 5, 0 }),
      "intestine", "gut", ({ "torso", 30, 0 }),
      "pancreas", "pancreas", ({ "torso", 5, 0 }),
      "first stomach", "stomach", ({ "torso", 30, 0 }),
      "second stomach", "stomach", ({ "torso", 30, 0 }),
      "third stomach", "stomach", ({ "torso", 30, 0 }),
      "fourth stomach", "stomach", ({ "torso", 30, 0 }),
      "genitals", "genitals", ({ 0, 5, 0 }),
      "left arm", "arm", ({ 0, 40, 0, "left hand" }),
      "left hand", "hand", ({ "left arm", 10, 0,
         "left little finger", "left third finger", "left index finger",
         "left ring finger", "left thumb" }),
      "right arm", "arm", ({ 0, 40, 0, "right hand" }),
      "right hand", "hand", ({ "right arm", 10, 0,
         "right little finger", "right third finger", "right index finger",
         "right ring finger", "right thumb" }),
      "left little finger", "finger", ({ "left hand", 1, 0 }),
      "left third finger", "finger", ({ "left hand", 1, 0 }),
      "left index finger", "finger", ({ "left hand", 1, 0 }),
      "left ring finger", "finger", ({ "left hand", 1, 0 }),
      "left thumb", "finger", ({ "left hand", 1, 0 }),
      "right little finger", "finger", ({ "right hand", 1, 0 }),
      "right third finger", "finger", ({ "right hand", 1, 0 }),
      "right index finger", "finger", ({ "right hand", 1, 0 }),
      "right ring finger", "finger", ({ "right hand", 1, 0 }),
      "right thumb", "finger", ({ "right hand", 1, 0 }),
      "left front leg", "leg", ({ 0, 130, 0, "left front hoof" }),
      "left front hoof", "hoof", ({ "left front leg", 10, 0 }),
      "right front leg", "leg", ({ 0, 130, 0, "right front hoof" }),
      "right front hoof","hoof", ({ "right front leg", 10, 0 }),
      "left back leg", "leg", ({ 0, 180, 0, "left back hoof" }),
      "left back hoof","hoof",({ "left back leg", 10, 0 }),
      "right back leg", "leg", ({ 0, 180, 0, "right back hoof"}),
      "right back hoof", "hoof", ({ "right back leg", 10, 0 }),
      "tail", "tail", ({ 0, 15, 0 }),
      "skin", "skin", ({ 0, 175, 0 })
   });

   inedible = ({ "skull", "left front hoof", "right front hoof",
      "left back hoof", "right back hoof", "tail", "teeth", "tooth",
      "skull" });
   unrottable = ({ "skull", "left front hoof", "right front hoof",
      "left back hoof", "right back hoof", "tail", "teeth", "tooth",
      "skull" });
   set_skin("hide");

   add_ac( "blunt", "blunt", 80 );
   add_ac( "sharp", "sharp", 70 );
   add_ac( "pierce", "pierce", 50 );

   set_sight( ({ 0, 5, 100, 125 }) );
   set_stats( ({ 4, 4, 0, 8, 2 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->remove_attack( "standard" );

   thing->remove_attack( "hoof" );

   thing->add_attack( "hands", 75, ({ 2 * number, 8, number }),
      "blunt", "unarmed", "unarmed_hands" );
   thing->add_attack( "hoof", 50, ({ 4 * number, 10, number }), 
      "blunt", "unarmed", 0 );
} /* set_unarmed_attacks() */

