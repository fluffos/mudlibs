/**
 * A wooden lute!
 * By Liceas - 18/07/02
 */

inherit HELD_OBJ;

void setup() {
    set_name("lute");
    set_short("wooden lute");
    add_adjective("wooden");

    set_long("This is a relatively small wooden lute, about the length of a "
        "young man's arm.  On the lower part of the instrument's body, or "
        "'belly', a soundhole has been cut out of the wood, exposing the "
        "resonance-box inside.  Tight gut strings pass from the neck of the "
        "lute all the way to a fastening on the rounded body.  Around the "
        "cut out circle in the belly is a checkered pattern of red and "
        "white.\n");

    set_weight(25);
    set_value(1000);

} /* setup() */

/** @ignore yes */
int do_play() {
    string str;

    if( !TO->query_holder() ) {
        add_failed_mess("You have to hold $D before you can play "
            "$V$0=it,them$V$.\n");
        return 0;
    }

    str = ({"simply, playing a few chords",
            "quickly, playing a fast tempoed tune",
            "slowly, playing a soothing tune",
            "carefully, playing a strange tune",
            "quickly, creating a fast, but short tune",
            "very quickly, playing a fast-paced piece of music",
            "calmly, playing a short tune",
            "skillfully, playing a few chords",
            "carelessly, making a loud twang noise",
            })[random(9)];

    add_succeeded_mess("$N raise$s $D to reach an arm under it for support "
        "and strum$s the strings "+str+".\n");
    return 1;

} /* do_play() */

/** @ignore yes */
int do_strum() { return do_play(); }

/** @ignore yes */
void init() {
    add_command("play");
    add_command("strum");
} /* init() */
