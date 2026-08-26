/**
 * The wonderous joys of pan pipes :)
 * Based on the toy fanfare: /obj/toys/fanfare.c
 * By Liceas - 17/07/02
 */

inherit HELD_OBJ;

void setup() {
    set_name("pipes");
    set_short("set of wooden pan pipes");
    add_adjective("set of wooden pan");
    add_plural("pipes");

    set_long("This is a rather compact set of wooden tubes bundled together "
        "to a set of pan-pipes.  The pipes decrease in length and breadth "
        "from one side of the instrument to the other, and have been bound "
        "together with a white string.\n");

    set_weight(12);
    set_value(450);

} /* setup() */

/** @ignore yes */
int do_blow() {
    string str;

    if( !query_holder() ) {
        add_failed_mess("You have to hold $D before you can play "
            "$V$0=it,them$V$.\n");
        return 0;
    }

    str = ({"giving a short and quiet trill",
            "giving a long trill",
            "playing a brief melodic tune",
            "playing a calming, but short tune",
            "playing a soothing melody",
            "giving a loud beep out",
            "producing a short and sharp tune.",
            "producing a controlled little melody",
            "producing a soothing, yet short, tune",
            "producing a short and sharp tune",
            "producing a long, ballad",
            "producing a short but romantic tune",
            "making a loud beep",
            })[random(13)];

    add_succeeded_mess("$N take$s a hefty lungful of breath, raise$s "
        "$D to just under $p lips and blow$s the air out, "+str+".\n");

    return 1;

} /* do_blow() */

/** @ignore yes */
int do_play() { return do_blow(); }

/** @ignore yes */
void init() {
    add_command("blow");
    add_command("play");
} /* init() */
