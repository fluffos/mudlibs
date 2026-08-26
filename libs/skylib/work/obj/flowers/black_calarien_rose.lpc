/**
 * The black Calarien rose - this costs more than other Calarien roses
 * due to the difficulty to grow these, hence a much higher price, yet
 * it has a snob value to it.
 *
 * Liceas - 13/07/03
 */

inherit FLOWER_OBJ;

void setup() {
    set_name("rose");
    set_short("black Calarien rose");

    add_adjective("calarien Calarien black");

    set_value( 800 );
    set_decay( 100 + random(20) );
    set_weight( 1 );

    set_long("Surrounding a beautiful centre are many curved petals, each one "
        "huddling tightly to the other.  It is a black Calarien rose, as "
        "suggested by its contained shape which hints it did not grow in the "
        "wild.  Each petal is jet black, with a strange silvery highlight "
        "across their very tips.\n");

    set_withered_long("Once jet black, the grey petals surrounding the centre "
        "of this flower have started to wither inwards on themselves.  It can "
        "only be barely identified as a rose grown in Calarien due to its "
        "nurtured shape.\n");

    set_smell_message( ({
        "You inhale the sweet scent of $D and the pollen makes your nostrils "
        "tingle.\n", "$N raise$s $D to $p nose and inhale$s.\n"}) );

} /* setup() */
