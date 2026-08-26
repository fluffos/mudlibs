/*  Giant Spider  *
 *     Gototh     *
 *    20/10/97    */

#define POISON_EFFECT "/std/effects/poisons/spider_venom"

inherit "/std/races/arachnid";
 
void setup() {
   set_name( "spider" );
   set_long( "A large, poisonous, hairy spider.\n" );
   set_desc( "a giant arachnid" );
   set_height( 150 );
   set_weight( 2000 );

   add_bit( "silk gland", "gland", ({ "abdomen", 10,
      ({"/std/bit", 1, 400}) }) );
   add_bit( "poison gland", "gland", ({ "cephalothorax", 5,
      ({"/std/bit", 1, 400}) }) );

   set_stats( ({ 10, -4, -6, 12, -4 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->remove_attack( "standard" );

   thing->remove_attack( "bite" );
   thing->remove_attack( "chew" );

   thing->add_attack( "bite", 80, ({70, 5, 10}),
      "pierce", "unarmed", ({ "poison", this_object() }) );
   thing->add_attack( "chew", 100, ({2, 2, 150}),
      "sharp", "unarmed", 0 );

   thing->set_combat_response("dodge");
   thing->set_combat_attitude("offensive");
} /* set_unarmed_attacks() */

void poison( int damage, object him, object me, string a_type,
             string a_name ) {
   tell_object( me, "You sink your fangs into " + him->one_short() +
      ", injecting " + him->query_objective() + " with venom.\n" );
   tell_object( him, me->one_short() + " sinks " + me->query_possessive() +
      " fangs into you!  You seethe in agony.\n" );
   tell_room( environment( me ), me->one_short() + " viciously sinks " +
      me->query_possessive() +  " fangs into " + him->one_short() + ", who "
      "seethes in agony!\n", ({ me, him }) );

   him->add_effect( POISON_EFFECT, 100 );
} /* poison() */
