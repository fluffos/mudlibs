inherit "/std/races/reptile_base";

void setup() {
    set_name( "dragon" );
    set_long( "The dragon is an immense and powerful creature.  They "
      "were created by the gods thousands of years ago.  This dragon looks "
      "particularly majestic and beautiful.  It towers over you and "
      "humbles you by its very existance.\n" );
    set_height( 700 );
    set_weight( 100000 );
    set_desc( "a powerful and majestic winged creature that has long "
      "seperated itself from the race of reptiles" );

    remove_bit( "left front foot" );
    remove_bit( "right front foot" );
    remove_bit( "left rear foot" );
    remove_bit( "right rear foot" );
    remove_bit( "left front leg" );
    remove_bit( "right front leg" );
    remove_bit( "left rear leg" );
    remove_bit( "right rear leg" );

    add_bit( "left front leg", "leg", ({ 0, 100, 0, "left front claw" }) );
    add_bit( "left front claw", "claw", ({ "left front leg", 17, 0 }) );
    add_bit( "right front leg", "leg", ({ 0, 100, 0, "right front claw" }) );
    add_bit( "rigth front claw", "claw", ({ "right front leg", 17, 0 }) );
    add_bit( "left rear leg", "leg", ({ 0, 100, 0, "left rear claw" }) );
    add_bit( "left rear claw", "claw", ({ "left rear leg", 17, 0 }) );
    add_bit( "right rear leg", "leg", ({ 0, 100, 0, "right rear claw" }) );
    add_bit( "right rear claw", "claw", ({ "right rear leg", 17, 0 }) );
    add_bit( "left wing", "wing", ({ 0, 150, 0, "left wing claw" }) );
    add_bit( "left wing claw", "claw", ({ "left wing", 10, 0 }) );
    add_bit( "right wing", "wing", ({ 0, 150, 0, "right wing claw" }) );
    add_bit( "right wing claw", "claw", ({ "right wing", 10, 0 }) );

    inedible += ({ "left front claw", "right front claw", "left wing claw",
      "right wing claw" });
    unrottable += ({ "left front claw", "right front claw", "left rear claw",
      "right rear claw", "left wing claw", "right wing claw" });

    set_stats( ({ 12, 6, 4, 16, 4 }) );
} /* setup() */

void new_set_level( mixed *args ) {
    int level;
    object thing;

    if( sizeof(args) < 2 || !args[1] )
        return;

    level = args[ 0 ];
    thing = args[ 1 ];

    thing->add_ac( "blunt", "blunt", level );
    thing->add_ac( "pierce", "pierce", level );
    thing->add_ac( "sharp", "sharp", level );
} /* new_set_level() */

void set_unarmed_attacks( object thing ) {
    int number;

    number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
    number /= 10;

    thing->remove_attack( "hands" );
    thing->remove_attack( "feet" );

    thing->add_attack( "claws", 80, ({ number * 2, 10, number / 2 }),
      "sharp", "unarmed", 0 );
    thing->add_attack( "tail", 60, ({ number / 2, 10, number / 2 }),
      "blunt", "unarmed", 0 );
    thing->add_attack( "bite", 60, ({ number, 10, number / 2 }),
      "pierce", "unarmed", 0 );
    thing->add_attack( "fire", 70, ({ number * 2, 10, number / 2 }),
      "fire", "unarmed", 0 );

    thing->add_attack( "wings", 45, ({ number, 10, number / 2 }),
      "blunt", "unarmed", 0 );

    thing->add_attack_message( "wings", "blunt", ({
       0, "$N buffet$s $I with $p powerful wings.\n"
       }) );

    thing->set_combat_response("dodge");
    thing->set_combat_attitude("offensive");

} /* set_unarmed_attacks() */
