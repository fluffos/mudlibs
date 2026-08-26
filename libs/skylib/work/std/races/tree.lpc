inherit "/std/races/tree_base";

void setup() {
   set_name( "tree" );
   set_long( "A tree.\n" );
   set_height( 800 );
   set_weight( 40000 );
   set_desc( "a large tree" );

   set_stats( ({ 10, -8, -2, 10, 4 }) );
} /* setup() */

void new_set_level( mixed *args ) {
   int level;
   object thing;

   if( sizeof(args) < 2 || !args[1] )
      return;

   level = args[ 0 ];
   thing = args[ 1 ];

   level = level / 2;

   thing->add_ac( "blunt", "blunt", level );
   thing->add_ac( "pierce", "pierce", level );
   thing->add_ac( "sharp", "sharp", level / 2 );
} /* new_set_level() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 2 + sqrt( number );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "branches" );

   thing->add_attack( "branches", 100, ({ number / 2, 10, number }),
      "blunt", "blunt", 0 );

   thing->add_attack_message( "branches", "blunt", ({
      20, ({
        "You tap $hcname$ with your branches.\n",
        "$mcname$ taps you with $mposs$ branches.\n",
        "$mcname$ taps $hcname$ with $mposs$ branches.\n" }),
      60, ({
        "You hit $hcname$ with your branches.\n",
        "$mcname$ hits you with $mposs$ branches.\n",
        "$mcname$ hits $hcname$ with $mposs$ branches.\n" }),
      100, ({
        "You bruise $hcname$ with your branches.\n",
        "$mcname$ bruises you with $mposs$ branches.\n",
        "$mcname$ bruises $hcname$ with $mposs$ branches.\n" }),
      140, ({
        "You hit $hcname$ hard with your branches.\n",
        "$mcname$ hits you hard with $mposs$ branches.\n",
        "$mcname$ hits $hcname$ hard with $mposs$ branches.\n" }),
      180, ({
        "You smash your branches into $hcname$.\n",
        "$mcname$ smashes $mposs$ branches into you.\n",
        "$mcname$ smashes $mposs$ branches into $hcname$.\n" }),
      220, ({
        "You crush $hcname$ with your branches.\n",
        "$mcname$ crushes you with $mposs$ branches.\n",
        "$mcname$ crushes $hcname$ with $mposs$ branches.\n" }),
      0, ({
        "You mash $hcname$ with your branches.\n",
        "$mcname$ mashes you with $mposs$ branches.\n",
        "$mcname$ mashes $hcname$ with $mposs$ branches.\n" }),
    }) );
} /* set_unarmed_attacks() */
