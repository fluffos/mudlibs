
inherit "/std/races/base";

void create() {
    do_setup++;
    ::create();
    do_setup--;

    set_desc("a humanoid-type being.  This should not be used since it is a "
        "base race");

    bits = ({
        "head", "head", ({ 0, 40, 0,
           "left ear", "right ear", "left eye", "right eye", "nose", "scalp",
           "tongue", "skull" }),
        "left ear", "ear", ({ "head", 1, 0 }),
        "right ear", "ear", ({ "head", 1, 0 }),
        "left eye", "eye", ({ "head", 1, 0 }),
        "right eye", "eye", ({ "head", 1, 0 }),
        "nose", "nose", ({ "head", 1, 0 }),
        "scalp", "scalp", ({ "head", 3, 0 }),
        "tongue", "tongue", ({ "head", 2, 0 }),
        "skull", "skull", ({ "head", 20, 0, "teeth", "brain" }),
        "brain", "brain", ({ "skull", 40, 0 }),
        "teeth", "teeth", ({ "skull", 2, ({"/std/bit_set", 1}), "tooth" }),
        "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 32}) }),
        "left arm", "arm", ({ 0, 80, 0, "left hand" }),
        "right arm", "arm", ({ 0, 80, 0, "right hand" }),
        "torso", "torso", ({ 0, 400, 0,
           "heart", "liver", "left kidney", "right kidney", "left lung",
           "right lung", "spleen" }),
        "left hand", "hand", ({ "left arm", 15, 0,
           "left little finger", "left third finger", "left index finger",
           "left ring finger", "left thumb" }),
        "right hand", "hand", ({ "right arm", 15, 0,
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
        "heart", "heart", ({ "torso", 10, 0 }),
        "liver", "liver", ({ "torso", 5, 0 }),
        "left kidney", "kidney", ({ "torso", 5, 0 }),
        "right kidney", "kidney", ({ "torso", 5, 0 }),
        "left lung", "lung", ({ "torso", 5, 0 }),
        "right lung", "lung", ({ "torso", 5, 0 }),
        "spleen", "spleen", ({ "torso", 5, 0 }),
        "genitals", "genitals", ({ 0, 5, 0 }),
        "left leg", "leg", ({ 0, 300, 0, "left foot" }),
        "right leg", "leg", ({ 0, 300, 0, "right foot" }),
        "left foot", "foot", ({ "left leg", 50, 0,
           "left big toe", "left second toe", "left third toe",
           "left fourth toe", "left little toe" }),
        "right foot", "foot", ({ "right leg", 50, 0,
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

    inedible = ({"skull", "teeth", "tooth"});
    unrottable = ({"skull", "teeth", "tooth"});
    set_skin("skin");

    add_attackable_area("head", "head");
    add_attackable_area("neck", "neck");
    add_attackable_area("back", "back");
    add_attackable_area("chest", "chest");
    add_attackable_area("abdomen", "stomach");
    add_attackable_area("arms", ({"left arm", "right arm"}) );
    add_attackable_area("hands", ({"left hand", "right hand"}) );
    add_attackable_area("legs", ({"left leg", "right leg"}) );
    add_attackable_area("feet", ({"left foot", "right foot"}) );

    if( !do_setup )
        TO->setup();

} /* create() */
