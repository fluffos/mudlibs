inherit "/std/races/demonic";

void setup() {
   set_long( "This isn't really a demon, but people usually call nasty "
             "creatures they know nothing about demons.\n" );
   set_name( "sektarian demon" );
   set_height( 250 );
   set_weight( 5000 );
   set_desc( "a nasty-looking demon with seven arms" );

   bits = ({
      "head", "head", ({ 0, 40, 0, 
         "left ear", "right ear", "left eye", "right eye", "nose", "scalp",
         "tongue", "teeth", "skull" }),
      "left ear", "ear", ({ "head", 1, 0 }),
      "right ear", "ear", ({ "head", 1, 0 }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "nose", "nose", ({ "head", 1, 0 }),
      "scalp", "scalp", ({ "head", 3, 0 }),
      "tongue", "tongue", ({ "head", 2, 0 }),
      "teeth", "teeth", ({ "head", 2, "/std/bit_set" }),
      "skull", "skull", ({ "head", 20, 0 }),
      "lower left arm", "arm", ({ 0, 70, 0, "lower left hand" }),
      "lower right arm", "arm", ({ 0, 70, 0, "lower right hand" }),
      "middle left arm", "arm", ({ 0, 70, 0, "middle left hand" }),
      "middle right arm", "arm", ({ 0, 70, 0, "middle right hand" }),
      "upper left arm", "arm", ({ 0, 70, 0, "upper left hand" }),
      "upper right arm", "arm", ({ 0, 70, 0, "upper right hand" }),
      "top arm", "arm", ({ 0, 70, 0, "top hand" }),
      "torso", "torso", ({ 0, 400, 0 }),
      "lower left hand", "hand", ({ "lower left arm", 15, 0,
         "left little finger", "left third finger", "left index finger",
         "left ring finger", "left thumb" }),
      "lower right hand", "hand", ({ "lower right arm", 15, 0,
         "right little finger", "right third finger", "right index finger",
         "right ring finger", "right thumb" }),
      "middle left hand", "hand", ({ "middle left arm", 15, 0,
         "left little finger", "left third finger", "left index finger",
         "left ring finger", "left thumb" }),
      "middle right hand", "hand", ({ "middle right arm", 15, 0,
         "right little finger", "right third finger", "right index finger",
         "right ring finger", "right thumb" }),
      "upper left hand", "hand", ({ "upper left arm", 15, 0,
         "left little finger", "left third finger", "left index finger",
         "left ring finger", "left thumb" }),
      "upper right hand", "hand", ({ "upper right arm", 15, 0,
         "right little finger", "right third finger", "right index finger",
         "right ring finger", "right thumb" }),
      "top hand", "hand", ({ "top arm", 15, 0, "left little finger", 
         "left third finger", "left index finger", "left ring finger",
         "left thumb" }),
      "left little finger", "finger", ({ "lower left hand", 1, 0 }),
      "left third finger", "finger", ({ "lower left hand", 1, 0 }),
      "left index finger", "finger", ({ "lower left hand", 1, 0 }),
      "left ring finger", "finger", ({ "lower left hand", 1, 0 }),
      "left thumb", "finger", ({ "lower left hand", 1, 0 }),
      "right little finger", "finger", ({ "lower right hand", 1, 0 }),
      "right third finger", "finger", ({ "lower right hand", 1, 0 }),
      "right index finger", "finger", ({ "lower right hand", 1, 0 }),
      "right ring finger", "finger", ({ "lower right hand", 1, 0 }),
      "right thumb", "finger", ({ "lower right hand", 1, 0 }),
      "left little finger", "finger", ({ "middle left hand", 1, 0 }),
      "left third finger", "finger", ({ "middle left hand", 1, 0 }),
      "left index finger", "finger", ({ "middle left hand", 1, 0 }),
      "left ring finger", "finger", ({ "middle left hand", 1, 0 }),
      "left thumb", "finger", ({ "middle left hand", 1, 0 }),
      "right little finger", "finger", ({ "middle right hand", 1, 0 }),
      "right third finger", "finger", ({ "middle right hand", 1, 0 }),
      "right index finger", "finger", ({ "middle right hand", 1, 0 }),
      "right ring finger", "finger", ({ "middle right hand", 1, 0 }),
      "right thumb", "finger", ({ "middle right hand", 1, 0 }),
      "left little finger", "finger", ({ "upper left hand", 1, 0 }),
      "left third finger", "finger", ({ "upper left hand", 1, 0 }),
      "left index finger", "finger", ({ "upper left hand", 1, 0 }),
      "left ring finger", "finger", ({ "upper left hand", 1, 0 }),
      "left thumb", "finger", ({ "upper left hand", 1, 0 }),
      "right little finger", "finger", ({ "upper right hand", 1, 0 }),
      "right third finger", "finger", ({ "upper right hand", 1, 0 }),
      "right index finger", "finger", ({ "upper right hand", 1, 0 }),
      "right ring finger", "finger", ({ "upper right hand", 1, 0 }),
      "right thumb", "finger", ({ "upper right hand", 1, 0 }),
      "top little finger", "finger", ({ "top hand", 1, 0 }),
      "top third finger", "finger", ({ "top hand", 1, 0 }),
      "top index finger", "finger", ({ "top hand", 1, 0 }),
      "top ring finger", "finger", ({ "top hand", 1, 0 }),
      "top thumb", "finger", ({ "top hand", 1, 0 }),
      "genitals", "genitals", ({ 0, 5, 0 }),
      "left leg", "leg", ({ 0, 200, 0, "left foot" }),
      "right leg", "leg", ({ 0, 200, 0, "right foot" }),
      "left foot", "foot", ({ "left leg", 25, 0,
         "left big toe", "left second toe", "left third toe",
         "left fourth toe", "left little toe" }),
      "right foot", "foot", ({ "right leg", 25, 0,
         "right big toe", "right second toe", "right third toe",
         "right fourth toe", "right little toe" }),
      "right little toe", "toe", ({ "right foot", 1, 0 }),
      "right second toe", "toe", ({ "right foot", 1, 0 }),
      "right third toe", "toe", ({ "right foot", 1, 0 }),
      "right fourth toe", "toe", ({ "right foot", 1, 0 }),
      "right big toe", "toe", ({ "right foot", 1, 0 }),
      "left little toe", "toe", ({ "left foot", 1, 0 }),
      "left second toe", "toe", ({ "left foot", 1, 0 }),
      "left third toe", "toe", ({ "left foot", 1, 0 }),
      "left fourth toe", "toe", ({ "left foot", 1, 0 }),
      "left big toe", "toe", ({ "left foot", 1, 0 }),
      "skin", "skin", ({ 0, 175, 0 })
   });

   inedible = ({ "skull", "teeth", "skin" });
   unrottable = ({ "skull", "teeth" });
   set_skin( "skin" );

   set_stats( ({ 10, 0, -2, 14, 4 }) );
} /* setup() */

void new_set_level( mixed *args ) {
   int level;
   object thing;

   if( sizeof(args) < 2 || !args[1] )
      return;

   level = args[ 0 ];
   thing = args[ 1 ];

   thing->add_skill_level( "general.health", level * 2 );
   thing->add_ac( "blunt", "blunt", level / 2 );
   thing->add_ac( "pierce", "pierce", level / 4 );
   thing->add_ac( "sharp", "sharp", level / 3 );
} /* new_set_level() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "claws" );
   thing->remove_attack( "bite" );

   thing->add_attack( "claws", 250, ({ 2 * number, 8, number }),
      "sharp", "unarmed", 0 );
   thing->add_attack( "bite", 25, ({ 3 * number, 10, number }),
      "pierce", "unarmed", 0 );
} /* set_unarmed_attacks() */
