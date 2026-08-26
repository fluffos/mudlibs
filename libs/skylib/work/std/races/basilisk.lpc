inherit "/std/races/base";

void do_deadly_stare( object victim, object aggressor );
void stare( int damage, object him, object me, string atype, string aname );

void setup() {
   set_name( "basilisk" );
   set_long( "This is a basilisk.  A reptilian creature that often coils up "
      "like a snake when it is resting. It has legendary saucer shaped eyes "
      "that can produce a deadly stare.\n" );
   set_height( 600 );
   set_weight( 200000 );

   bits= ({
      "head", "head", ({ 0, 135, 0,
         "left eye", "right eye", "skull", "brain", "teeth", "tongue" }),
      "left eye", "eye", ({ "head", 2, 0 }),
      "right eye", "eye", ({ "head", 2, 0 }),
      "skull", "skull", ({ "head", 45, 0, "brain" }),
      "brain", "brain", ({ "skull", 27, 0 }),
      "teeth", "teeth", ({ "head", 5, ({"/std/bit_set", 1}), "tooth" }),
      "tooth", "tooth", ({ "head", 1, ({"/std/bit", 32}) }),
      "tongue", "tongue", ({ "head", 9, 0 }),
      "neck", "neck", ({ 0, 100, 0 }),
      "torso", "body", ({ 0, 340, 0,
         "heart", "liver", "left kidney", "right kidney", "left lung",
         "right lung", "spleen", "intestine", "pancreas" }),
      "heart", "heart", ({ "torso", 45, 0 }),
      "liver", "liver", ({ "torso", 45, 0 }),
      "left kidney", "kidney", ({ "torso", 27, 0 }),
      "right kidney", "kidney", ({ "torso", 27, 0 }),
      "left lung", "lung", ({ "torso", 45, 0 }),
      "right lung", "lung", ({ "torso", 45, 0 }),
      "spleen", "spleen", ({ "torso", 27, 0 }),
      "intestine", "gut", ({ "torso", 90, 0 }),
      "pancreas", "pancreas", ({ "torso", 27, 0 }),
      "left leg", "leg", ({ 0, 140, 0, "left foot" }),
      "left foot", "foot", ({ "left leg", 27, 0 }),
      "right leg", "leg", ({ 0, 140, 0, "right foot" }),
      "right foot", "foot", ({ "right leg", 27, 0 }),
      "tail", "tail", ({0, 100, 0 }),
      "skin", "skin", ({ 0, 175, 0 })
   });

   inedible = ({ "skull", "left foot", "right foot", "tail", "teeth",
      "tooth", "skin" });
   unrottable = ({ "skull", "teeth", "tooth" });

   add_ac( "blunt", "blunt", 80 );
   add_ac( "pierce", "pierce", 80 );
   add_ac( "sharp", "sharp", 80 );
   add_ac( "acid", "acid", 80 );

   set_stats( ({ 12, -8, -6, 16, -6 }) );
} /* setup() */

string query_desc( object thing ) {
   return "A basilisk, massive and deadly.\n";
} /* query_desc() */

int query_eat( string word ) {
   return ( member_array( word, inedible ) == -1 );
} /* query_eat() */

void set_unarmed_attacks( object thing ) {
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->remove_attack( "standard" );

   thing->remove_attack( "bite" );
   thing->remove_attack( "tail" );
   thing->remove_attack( "slime" );
   thing->remove_attack( "stare" );

   thing->add_attack( "bite", 50, ({90, 1, 30}),
      "pierce", "unarmed", 0 );
   thing->add_attack( "tail", 35, ({120, 1, 40}),
      "blunt", "unarmed", 0 );
   thing->add_attack( "slime", 50, ({50, 1, 30}),
      "corrosive", "unarmed", 0 );
   thing->add_attack( "stare", 10, ({1, 1, 1}),
      "magic", "unarmed", ({ "stare", this_object() }) );

   thing->add_attack_message( "slime", "corrosive", ({
      20, ({
         "You flake some skin off of $hcname$ with your slime.\n",
         "$mcname$ flakes some skin off of you with $mposs$ slime.\n",
         "$mcname$ flakes some skin off of $hcname$ with $mposs$ slime.\n" }),
      60, ({
         "You singe $hcname$ with your slime.\n",
         "$mcname$ singes you with $mposs$ slime.\n",
         "$mcname$ singes $hcname$ with $mposs$ slime.\n" }),
      100, ({
         "You eat a small hole in $hcname$ with your slime.\n",
         "$mcname$ eats a small hole in you with $mposs$ slime.\n",
         "$mcname$ eats a small hole in $hcname$ with $mposs$ slime.\n" }),
      140, ({
         "You eat the flesh from $hcname$ with your slime.\n",
         "$mcname$ eats the flesh from you with $mposs$ slime.\n",
         "$mcname$ eats the flesh from $hcname$ with $mposs$ slime.\n" }),
      180, ({
         "You eat a gaping hole in $hcname$ with your slime.\n",
         "$mcname$ eats a gaping hole in you with $mposs$ slime.\n",
         "$mcname$ eats a gaping hole in $hcname$ with $mposs$ slime.\n" }),
      220, ({
         "You eat clear through $hcname$ with your slime.\n",
         "$mcname$ eats clear through you with $mposs$ slime.\n",
         "$mcname$ eats clear through $hcname$ with $mposs$ slime.\n" }),
      0, ({
         "You dissolve $hcname$ with your slime.\n",
         "$mcname$ dissolves you with $mposs$ slime.\n",
         "$mcname$ dissolves $hcname$ with $mposs$ slime.\n" })
      }) );

   thing->set_combat_response("dodge");
   thing->set_combat_attitude("offensive");
} /* set_unarmed_attacks() */

void do_deadly_stare( object victim, object aggressor ) {
   if( creatorp(victim) && victim->query_visible(aggressor) )
      return;
   if( victim->query_property("dead") )
      return;
   if( environment(victim) != environment(aggressor) )
      return;

   if( find_object("/obj/shut") ) {
      aggressor->move("/room/rubbish", "fu",
      sprintf( "With a pop, %s notices that the disc is rebooting, and "
         "runs away.\n", aggressor->the_short() ) );
      return;
   }

   if( !(int)victim->query_basil_stare_shad() )
      victim->add_effect( "/std/effects/magic/basilisk_stare", 10 );
} /* do_deadly_stare() */

void stare( int damage, object him, object me, string atype, string aname ) {
   do_deadly_stare( him, me );
} /* stare() */
