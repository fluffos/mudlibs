
inherit "/std/races/base";

void setup() {
    set_name("horse");
    set_long("A large hoofed mammal.  Surprise.\n");
    set_height(350);
    set_weight(7000);

    bits= ({
      "head", "head", ({ 0, 120, 0,
         "left eye", "right eye", "skull", "brain", "left ear",
         "right ear", "tongue" }),
      "left eye", "eye", ({ "head", 2, 0 }),
      "right eye", "eye", ({ "head", 2, 0 }),
      "skull", "cranium", ({ "head", 45, 0, "teeth" }),
      "brain", "brain", ({ "head", 20, 0 }),
      "left ear", "ear", ({"head", 4, 0 }),
      "right ear", "ear", ({"head", 4, 0 }),
      "teeth", "teeth", ({ "skull", 5, ({"/std/bit_set", 1}) }),
      "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 18}) }),
      "tongue", "tongue", ({ "head", 9, 0 }),
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

    inedible = ({"skull", "left front hoof", "right front hoof",
        "left rear hoof", "right rear hoof", "tail", "teeth", "tooth"});
    unrottable = ({"skull", "left front hoof", "right front hoof",
        "left rear hoof", "right rear hoof", "teeth", "tooth"});

    set_desc("a large, hairy quadruped.  It looks like a horse");

    add_ac("blunt", "blunt", 50 );
    add_ac("sharp", "sharp", 20 );
    add_ac("pierce", "pierce", 20 );
    set_skin("skin");

    set_stats( ({ 4, 4, -2, 6, -2 }) );

    add_attackable_area("head", "head");
    add_attackable_area("neck", "neck");
    add_attackable_area("back", "back");
    add_attackable_area("chest", ({"left side", "right side"}) );
    add_attackable_area("abdomen", "stomach");
    add_attackable_area("arms", ({"left front leg", "right front leg"}) );
    add_attackable_area("hands", ({"left front hoof", "right front hoof"}) );
    add_attackable_area("legs", ({"left rear leg", "right rear leg"}) );
    add_attackable_area("feet", ({"left rear hoof", "right rear hoof"}) );

} /* setup() */

void set_unarmed_attacks( object thing ) {
    int number;

    number = (int)thing->query_skill_bonus("fighting.combat.melee.unarmed");
    number = sqrt( number );

    thing->remove_attack("hands");
    thing->remove_attack("feet");

    thing->remove_attack("chew");
    thing->remove_attack("hoof");

    thing->add_attack("chew", 50, ({ number, 2, number }),
        "sharp", "unarmed", 0 );
    thing->add_attack("hoof", 70, ({ number / 2, 5, number }),
        "blunt", "unarmed", 0 );

    thing->set_combat_response("dodge");

} /* set_unarmed_attacks() */
