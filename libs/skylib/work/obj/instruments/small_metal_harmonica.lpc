/**
 * A small metal harmonica.
 * By Liceas - 17/07/02
 */

inherit HELD_OBJ;

/** @ignore yes */
void setup() {
    set_name("harmonica");
    set_short("small metal harmonica");
    add_adjective("small metal");

    set_long("Consisting of a grid of two by fifteen square holes in a metal "
        "casing, this small harmonica has been designed for bards on the "
        "move.  The metal casing has been painted black, while the "
        "occasional blue splodge dotting its surface gives the instrument "
        "character.\n");

    set_weight(5);
    set_value(600);

} /* setup() */

/** @ignore yes */
int do_blow() {
    if( !query_holder() ) {
        add_failed_mess("You have to hold $D before you can play "
            "$V$0=it,them$V$.\n");
        return 0;
    }

    switch( random(12) ) {
      case 0:
        add_succeeded_mess("$N take$s a deep breath of air and raise$s $D to "
            "$p lips, then blow$s out while moving $D from left to right, "
            "giving a short run up the scales.\n");
        return 1;
      case 1:
        add_succeeded_mess("$N snort$s in some air and raise$s $D to $p "
            "lips and blow$s the air out while moving $D from right to "
            "left, giving a run down the musical scale.\n");
        return 1;
      case 2:
        add_succeeded_mess("$N take$s a hefty lungful of air, raise$s $D to "
            "$p lips and blow$s the air out, playing a brief and shaky "
            "tune.\n");
        return 1;
      case 3:
        add_succeeded_mess("$N suck$s in a shallow lungful of air, raise$s "
            "$D to $p lips and blow$s the air out while moving $D from left "
            "to right, playing a short but snappy tune.\n");
        return 1;
      case 4:
        add_succeeded_mess("$N inhale$s deeply, then raise$s $D to just "
            "under $p lips and blow$s the air out while moving $D quickly, "
            "playing a fast paced tune.\n");
        return 1;
      case 5:
        add_succeeded_mess("$N blow$s $D without taking in any air, playing "
            "a mixture of notes that produce a horrible sound.\n");
        return 1;
      case 6:
        add_succeeded_mess("$N take$s a deep breath, raise$s $D to $p lips "
            "and blows the air out while moving $D from side to side, "
            "producing a long serenade with a slow tempo.\n");
        return 1;
      case 7:
        add_succeeded_mess("$N suck$s in some air, raise$s $D to $p lips "
            "and moves $D with style, producing a well-played melody with a "
            "fast beat.\n");
        return 1;
      case 8:
        add_succeeded_mess("$N take$s a deep breath and raise$s $D to $p "
            "lips, then move$s it from side to side while blowing out the "
            "air and produce$s a soft but short piece of music.\n");
        return 1;
      case 9:
        add_succeeded_mess("$N snort$s some air in, raise$s $D to $p lips "
            "and produce$s a long and boring tune while moving $D from side "
            "to side.\n");
        return 1;
      case 10:
        add_succeeded_mess("$N sniff$s in a shallow lungful of air, raise$s "
            "$D to $p lips and produce$s a calming ballad while moving $D "
            "slowly.\n");
        return 1;
      default:
        add_succeeded_mess("$N take$s a hefty lungful of air, raise$s $D "
            "to just under $p lips and make$s a loud beep.\n");
        return 1;
    }

} /* do_blow() */

/** @ignore yes */
int do_play() { return do_blow(); }

/** @ignore yes */
void init() {
    add_command("blow");
    add_command("play");
} /* init() */
