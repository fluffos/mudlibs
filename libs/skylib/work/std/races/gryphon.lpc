// Tremaine 9th September, 2000

inherit "/std/races/carnivore";

void setup() {

    set_name( "gryphon" );
    set_long( "The gryphon has the head and chest of"
      " an eagle, and the rear of a lion.\n");

    set_height( 350 );
    set_weight( 4000 );
    set_sight( ({ 5, 20, 200, 300 }) );
    set_stats( ({ 8, 10, -4, 14, -4 }) );
    bits= ({
      "head", "head", ({ 0, 120, 0,
        "left eye", "right eye", "skull" }),
      "left eye", "eye", ({ "head", 2, 0 }),
      "right eye", "eye", ({ "head", 2, 0 }),
      "skull", "cranium", ({ "head", 50, 0 }),
      "neck", "neck", ({ 0, 120, 0 }),
      "torso", "body", ({ 0, 400, 0,
        "heart", "left wing", "right wing" }),
      "heart", "heart", ({ "torso", 35, 0 }),
      "left wing", "left wing", ({ "torso", 45, 0}),
      "right wing", "right wing", ({ "torso", 45, 0 }),
      "left front leg", "leg", ({ 0, 140, 0, "left front claw" }),
      "left front claw", "claw", ({ "left front leg", 20, 0 }),
      "right front leg", "leg", ({ 0, 140, 0, "right front claw" }),
      "right front claw", "claw", ({ "right front leg", 20, 0 }),
      "left rear leg", "leg", ({ 0, 160, 0, "left rear paw" }),
      "left rear paw", "paw", ({ "left rear leg", 20, 0 }),
      "right rear paw", "paw", ({ "right rear leg", 20, 0 }),
      "tail", "tail", ({ 0, 15, 0 })
    });


} /* setup */


string query_desc( object thing ) {
    if ( (int)thing->query_gender() == 1 )
        return "He is a powerful young male gryphon.\n";
    if ( (int)thing->query_gender() == 2 )
        return "She is a powerful young female gryphon.\n";
    return "It is a powerful young gryphon.\n";
} /* query_desc() */

void new_set_level( mixed *args ) {
    int level;
    object thing;

    if( sizeof(args) < 2 || !args[1] )
        return;

    level = args[ 0 ];
    thing = args[ 1 ];

    thing->add_skill_level( "general.health", level * 1.5 );
    thing->add_ac( "blunt", "blunt", level );
    thing->add_ac( "sharp", "sharp", 2 + level );
    thing->add_ac( "pierce", "pierce", 2 * level );
    thing->add_ac( "magic", "magic", level / 4);
} /* new_set_level() */

void set_unarmed_attacks( object thing ) {
    int number;

    number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
    number = 2 + sqrt( number );

    thing->remove_attack( "hands" );
    thing->remove_attack( "feet" );

    thing->remove_attack( "claws" );
    thing->remove_attack( "special" );

    if( number < 10 )
        number = 10;

    thing->add_attack( "claws", 100, ({ number, 10, number }),
      "sharp", "unarmed", 0 );
    thing->add_attack( "special", 75, ({ 3 * number, number / 2, number }),
      "pierce", "unarmed", 0 );

    thing->add_attack_message( "special", "pierce", ({
        50, ({
          "You scratch $hcname$ with your beak.\n",
          "$mcname$ scratches you with $mposs$ beak.\n",
          "$mcname$ scratches $hcname$ with $mposs$ beak.\n"}),
        100, ({
          "You jab your beak into $hcname$.\n",
          "$mcname$ jabs $mposs$ beak into you.\n",
          "$mcname$ jabs $mposs$ beak into $hcname$.\n"}),
        140, ({
          "You tear into $hcname$.\n",
          "$mcname$ tears into you.\n",
          "$mcname$ tears $hcname$.\n"}),
        180, ({
          "You rip into $hcname$'s body with your beak.\n",
          "$mcname$ rips into your body with $mposs$ beak.\n",
          "$mcname$ rips into $hcname$'s body with $mposs$ beak.\n"}),
        230, ({
          "You dismember $hcname$.\n",
          "$mcname$ dismembers you.\n",
          "$mcname$ dismembers $hcname$.\n"}),
        0, ({
          "You disembowel $hcname$.\n",
          "$mcname$ disembowels you.\n",
          "$mcname$ disembowels $hcname$.n" })
      }) );


    thing->set_combat_response("dodge");

} /* set_unarmed_attacks() */

void eat_bit( mixed main_bits, object corpse, object race_obj,
  object eater ) {
    int which_bit;
    mixed *sub_bits;
    object new_bit;

    if( !eater ) return;

    which_bit = 3 * random( sizeof( main_bits ) / 3 );
    sub_bits = main_bits[ which_bit + 2 ];
    if( sizeof( sub_bits ) > 3 ) {
        call_out( "eat_bit", 0,

          race_obj->query_bit(
            sub_bits[ random( sizeof(sub_bits ) - 3 ) + 3 ] ),
          corpse, race_obj, eater );
        return;
    }

    if( member_array( main_bits[ which_bit ],

        (mixed *)corpse->query_bits_left() ) == -1 ) {
        eater->remove_property( "busy" );
        return;
    }

    new_bit = corpse->make_bit( main_bits[which_bit] );
    corpse->add_bit_gone( main_bits[ which_bit ] );

    if( !( race_obj->query_eat( main_bits[ which_bit ] ) ) ) {
        tell_room( environment( eater ), "The " + (string)eater->short() +
          " rips " + add_a( main_bits[ which_bit ] ) + " from " +
          (string)corpse->short() + " and drops it.\n" );
        new_bit->move( environment(eater) );
        eater->remove_property( "busy" );
        return;
    }


    tell_room( environment( eater ), "The " + (string)eater->short() +
      " tears " + add_a( main_bits[ which_bit ] ) + " from " +
      (string)corpse->short() + " and begins eating.\n" );
    new_bit->dest_me();
    call_out( "finish_eating", 30 * sub_bits[ 1 ] +
      random( 60 * sub_bits[ 1 ] ) + random( 30 ), eater );
} /* eat_bit() */

void finish_eating( object eater ) {
    if( !eater )
        return;

    eater->remove_property( "busy", 1 );
} /* finish_eating() */

void player_heart_beat( string word, object eater ) {
    int i;
    object race_obj, *stuff;

    if( !environment( eater ) ) return;
    if( eater->query_property( "busy" ) ) return;
    stuff = all_inventory( environment( eater ) ) - ({ eater });
    if( !sizeof( stuff ) ) return;

    for( i = 0; i < sizeof( stuff ); i++ )
        if( !( stuff[ i ]->id( "corpse" ) ) ) {
            stuff -= ({ stuff[ i ] });
            i--;
        }

    if( !sizeof( stuff ) ) return;
    eater->add_property( "busy", 1 );
    i = random( sizeof( stuff ) );
    race_obj = stuff[ i ]->query_race_ob();
    call_out( "eat_bit", 0, race_obj->query_bits(), stuff[ i ], race_obj,
      eater );
} /* player_heart_beat() */

