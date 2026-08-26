
inherit "/std/races/base";

void create() {
    do_setup++;
    ::create();
    do_setup--;

    set_weight( 700 );
    set_height( 50 );
    set_desc("your standard carnivore.  This should not be used as it is a "
        "base race" );

    bits = ({
        "head", "head", ({ 0, 40, 0,
           "left eye", "right eye", "nose", "skull", "left ear", "right ear",
           "tongue" }),
        "left eye", "eye", ({ "head", 1, 0 }),
        "right eye", "eye", ({ "head", 1, 0 }),
        "skull", "cranium", ({ "head", 20, 0, "brain", "teeth" }),
        "brain", "brain", ({ "skull", 20, 0 }),
        "left ear", "ear", ({"head", 1, 0 }),
        "right ear", "ear", ({"head", 1, 0 }),
        "nose", "nose", ({ "head", 3, 0 }),
        "teeth", "teeth", ({ "skull", 3, ({"/std/bit_set", 1}), "tooth" }),
        "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 48}) }),
        "tongue", "tongue", ({ "head", 2, 0 }),
        "neck", "neck", ({ 0, 15, 0 }),
        "torso", "body", ({ 0, 350, 0,
           "heart", "liver", "left kidney", "right kidney", "left lung",
           "right lung", "spleen", "intestine", "pancreas" }),
        "heart", "heart", ({ "torso", 10, 0 }),
        "liver", "liver", ({ "torso", 5, 0 }),
        "left kidney", "kidney", ({ "torso", 5, 0 }),
        "right kidney", "kidney", ({ "torso", 5, 0 }),
        "left lung", "lung", ({ "torso", 10, 0 }),
        "right lung", "lung", ({ "torso", 10, 0 }),
        "spleen", "spleen", ({ "torso", 5, 0 }),
        "intestine", "gut", ({ "torso", 15, 0 }),
        "pancreas", "pancreas", ({ "torso", 5, 0 }),
        "genitals", "genitals", ({ 0, 5, 0 }),
        "left front leg", "leg", ({ 0, 130, 0, "left front paw" }),
        "left front paw", "paw", ({ "left front leg", 30, 0, "claw" }),
        "claw", "claw", ({ "left front paw", 1, ({"/std/bit", 4}) }),
        "right front leg", "leg", ({ 0, 130, 0, "right front paw" }),
        "right front paw", "paw", ({ "right front leg", 30, 0, "claw" }),
        "claw", "claw", ({ "right front paw", 1, ({"/std/bit", 4}) }),
        "left rear leg", "leg", ({ 0, 275, 0, "left rear paw" }),
        "left rear paw", "paw", ({ "left rear leg", 30, 0, "claw" }),
        "claw", "claw", ({ "left rear paw", 1, ({"/std/bit", 4}) }),
        "right rear leg", "leg", ({ 0, 275, 0, "right rear paw" }),
        "right rear paw", "paw", ({ "right rear leg", 30, 0, "claw" }),
        "claw", "claw", ({ "right rear paw", 1, ({"/std/bit", 4}) }),
        "tail", "tail", ({ 0, 18, 0 }),
        "skin", "skin", ({ 0, 175, 0 })
    });

    inedible = ({"skull", "claw", "tail", "teeth", "tooth", "skin"});
    unrottable = ({"skull", "claw", "teeth", "tooth"});
    set_skin("pelt");

    set_stats( ({ 6, 10, -2, 6, -4 }) );

    add_attackable_area("head", "head");
    add_attackable_area("neck", "neck");
    add_attackable_area("back", "back");
    add_attackable_area("chest", ({"left side", "right side"}) );
    add_attackable_area("abdomen", "stomach");
    add_attackable_area("arms", ({"left front leg", "right front leg"}) );
    add_attackable_area("hands", ({"left front paw", "right front paw"}) );
    add_attackable_area("legs", ({"left rear leg", "right rear leg"}) );
    add_attackable_area("feet", ({"left rear paw", "right rear paw"}) );

    if( !do_setup )
        TO->setup();

} /* create() */
