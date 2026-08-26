/*
* Spinning top toy by Sandoz, 20th June 2001.
*/

inherit OBJECT_OBJ;

int spinning;

void setup() {
    set_name("spinner");
    set_short("spinning top");
    add_alias( ({"top", "toy"}) );
    add_plural( ({"tops", "toys"}) );
    add_adjective("spinning");

    set_long("This gadget is one of the favourite toys of children in all "
        "realms.  It consists of an elliptical ball that is pierced by a "
        "stick that can be used to speed up the gadget.\n");

    set_weight(12);
    set_value(80);

} /* setup() */

void init() {
    add_command("spin", "<direct:object:me>");
} /* init() */

int do_spin() {
    if( !TP->query_property("spinning") ) {
        TP->add_property("spinning", 1, 1 );
        tell_object( TP, "You hold the stick piercing "+the_short()+" and "
            "set it on the ground after making it spin.\n" );
        tell_room( ENV(TP), TP->one_short()+" holds the stick piercing "+
            the_short()+" and sets it on the ground after making it "
            "spin.\n", TP );
        TO->move(ENV(TP));
        spinning = 1;
        call_out("do_spin1", 4 + random( 4 ), TP );
        add_succeeded_mess("");
        return 1;
    }
    else {
        add_failed_mess("You cannot spin more than one spinning top at a "
            "time!\n");
        return 0;
    }
} /* do_spin() */

void do_spin1( object spinner ) {
    if( !spinning )
        return;
    tell_room( ENV(TO), one_short()+ " $V$0=spins,spin$V$ in bigger and "
        "bigger circles.\n");
    call_out("do_spin2", 2 + random( 4 ), spinner );
} /* do_spin1() */

void do_spin2( object spinner ) {
    if( !spinning )
        return;
    tell_room( ENV(TO), one_short()+ " $V$0=spins,spin$V$ about and "
        "$V$0=starts,start$V$ to flutter slightly.\n");
    call_out("stop_spin", 2 + random( 4 ), spinner );
} /* do_spin2() */

void stop_spin( object spinner ) {
    if( !spinning )
        return;
    tell_room( ENV(TO), one_short()+" $V$0=stops,stop$V$ spinning and "
        "$V$0=falls,fall$V$ over.\n");
    spinning = 0;
} /* stop_spin() */

int do_get( object *obs, string dir_match, string indir_match, mixed *args, string pattern ) {

    if( !move( TP ) ) {
        if( spinning ) {
            spinning = 0;
            tell_object( TP, "You stop "+one_short()+" from spinning to pick "
                "$V$0=it,them$V$ up.\n");
            tell_room( ENV(TO), TP->the_short()+" stops "+one_short()+" from "
                "spinning and picks $V$0=it,them$V$ up.\n", TP );
        }
        return 1;
    }

    return 0;

} /* do_get() */
