/**
 * A small bard's harp.
 * By Liceas - 18/07/02
 */

inherit HELD_OBJ;

void setup() {
    set_name("harp");
    set_short("small golden harp");
    add_adjective("small golden");

    set_long("This harp is a much smaller size than a regular harp and has "
        "been designed to fit in a single hand, making it much more "
        "portable.  Its wooden frame has been painted a gold colour, showing "
        "it is not as valuable as the more elaborate harps.  Strung with "
        "brass wire, the instrument has been designed to be plucked with "
        "finger nails instead of finger pads.\n");

    set_weight(25);
    set_value(650);

} /* setup() */

/** @ignore yes */
int do_pluck() {
    string str;

    if( !query_holder() ) {
        add_failed_mess("You have to hold $D before you can play it.\n");
        return 0;
    }

     str = ({"quickly, playing an short tune with an odd beat",
             "quickly, making a fast and heavy piece of music",
             "badly, making an awful tune",
             "slowly, making a calm piece of music",
             "blandly, playing a short and dull tune",
             "slowly, resulting in a relaxing madrigal",
             "up and down once, making a nice set of musical scales",
             "in a syncopated way, producing a dance beat",
             "carefully, ending in a well-paced piece of music",
             "heavily, making a heavy twang noise",
             })[random(10)];

    add_succeeded_mess("$N raise$s $p spare hand to $D and pluck$s the "
        "strings "+str+".\n");
    return 1;

} /* do_pluck() */

/** @ignore yes */
int do_play() { return do_pluck(); }

/** @ignore yes */
void init() {
    add_command("pluck");
    add_command("play");
} /* init() */
