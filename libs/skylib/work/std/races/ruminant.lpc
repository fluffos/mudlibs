
inherit "/std/races/base";

void create() {
    do_setup++;
    ::create();
    do_setup--;

    set_weight( 800 );
    set_height( 50 );
    set_desc("a four-legged ruminant.  It shouldn't be used since this is "
        "just a base race");

    bits = ({
        "head", "head", ({ 0, 100, 0,
           "left eye", "right eye", "nose", "skull", "tongue", "left ear",
           "right ear" }),
        "left eye", "eye", ({ "head", 2, 0 }),
        "right eye", "eye", ({ "head", 2, 0 }),
        "skull", "skull", ({ "head", 40, 0, "brain", "teeth" }),
        "brain", "brain", ({ "skull", 20, 0 }),
        "left ear", "ear", ({"head", 5, 0 }),
        "right ear", "ear", ({"head", 5, 0 }),
        "nose", "nose", ({ "head", 15, 0 }),
        "teeth", "teeth", ({ "skull", 5, ({"/std/bit_set", 1}), "tooth" }),
        "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 18}) }),
        "tongue", "tongue", ({ "head", 10, 0 }),
        "neck", "neck", ({ 0, 100, 0 }),
        "torso", "chest", ({ 0, 300, 0,
           "heart", "liver", "left kidney", "right kidney", "left lung",
           "right lung", "spleen", "first stomach", "second stomach",
           "third stomach", "fourth stomach", "intestine", "pancreas" }),
        "heart", "heart", ({ "torso", 15, 0 }),
        "liver", "liver", ({ "torso", 15, 0 }),
        "left kidney", "kidney", ({ "torso", 10, 0 }),
        "right kidney", "kidney", ({ "torso", 10, 0 }),
        "left lung", "lung", ({ "torso", 15, 0 }),
        "right lung", "lung", ({ "torso", 15, 0 }),
        "spleen", "spleen", ({ "torso", 10, 0 }),
        "intestine", "gut", ({ "torso", 50, 0 }),
        "pancreas", "pancreas", ({ "torso", 10, 0 }),
        "first stomach", "stomach", ({ "torso", 20, 0 }),
        "second stomach", "stomach", ({ "torso", 20, 0 }),
        "third stomach", "stomach", ({ "torso", 20, 0 }),
        "fourth stomach", "stomach", ({ "torso", 20, 0 }),
        "genitals", "genitals", ({ 0, 5, 0 }),
        "left front leg", "leg", ({ 0, 150, 0, "left front hoof" }),
        "left front hoof", "hoof", ({ "left front leg", 30, 0 }),
        "right front leg", "leg", ({ 0, 150, 0, "right front hoof" }),
        "right front hoof", "hoof", ({ "right front leg", 30, 0 }),
        "left rear leg", "leg", ({ 0, 150, 0, "left rear hoof" }),
        "left rear hoof", "hoof", ({ "left rear leg", 30, 0 }),
        "right rear leg", "leg", ({ 0, 150, 0, "right rear hoof" }),
        "right rear hoof", "hoof", ({ "right rear leg", 30, 0 }),
        "skin", "skin", ({ 0, 175, 0 })
    });

    inedible = ({"skull", "neck", "genitals", "teeth", "left front hoof",
                 "right front hoof", "left rear hoof", "right rear hoof",
                 "tooth", "skin"});
    unrottable = ({"skull", "teeth", "tooth"});
    set_skin("hide");

    set_stats( ({ 0, 0, -6, 2, -6 }) );

    add_attackable_area("head", "head");
    add_attackable_area("neck", "neck");
    add_attackable_area("back", "back");
    add_attackable_area("chest", ({"left side", "right side"}) );
    add_attackable_area("abdomen", "stomach");
    add_attackable_area("arms", ({"left front leg", "right front leg"}) );
    add_attackable_area("hands", ({"left front hoof", "right front hoof"}) );
    add_attackable_area("legs", ({"left rear leg", "right rear leg"}) );
    add_attackable_area("feet", ({"left rear hoof", "right rear hoof"}) );

    if( !do_setup )
        TO->setup();

} /* create() */
