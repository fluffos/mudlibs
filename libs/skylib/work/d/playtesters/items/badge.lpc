/**
 * This is the badge the PTs use for moving from one place to another.
 */

inherit ARMOUR_OBJ;

/** @ignore yes */
void setup() {
    set_name("badge");
    set_short("blue badge");
    add_adjective("blue");
    add_property("nosteal", 1 );
    add_property("dead usable", 1 );

    set_long( "This is a small blue badge.  It has a drawing of a womble on "
        "the front; it seems to be using a magnifying glass to examine "
        "something.  On the back is engraved a scroll with some words on "
        "it.\n");

    setup_armour(1000);
    set_damage_chance(0);
    set_type("badge");
    reset_drop();

    set_read_mess("This badge allows the bearer to move into certain areas "
        "to be playtested from certain entry locations (near to where the "
        "areas will be eventually connected).  To see the possible "
        "destinations from your current room, use the command "
        "\"destinations\", and to move into one of them, use the command "
        "\"goto <label>\" where <label> will be A, B, C, etc..  You can get "
        "a list of all transit points with \"transits\", although no "
        "guarantee is made that each item on this list will be "
        "recognisable.  Please report any problems with rooms not loading to "
        "the relevant domain Lord or Liaison(s).");

} /* setup() */

/** @ignore yes */
int list_destinations() { return PLAYTESTERS_H->list_destinations(); }
/** @ignore yes */
int list_transits() { return PLAYTESTERS_H->list_transits(); }
/** @ignore yes */
int do_goto( string where ) { return PLAYTESTERS_H->do_goto( where ); }

/** @ignore yes */
void init() {
    if( !TP )
        return;

    if( !playtesterp(TP) ) {
        tell_object( TP, "You are not a playtester.  Your blue playtester's "
            "badge disappears.\n");
        set_drop();
        move("/room/rubbish");
        return;
    }

    add_command("destinations", "", (: list_destinations() :) );
    add_command("transits", "", (: list_transits() :) );
    add_command("goto", "<string>", (: do_goto($4[0]) :) );

} /* init() */
