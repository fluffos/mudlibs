
inherit ROOM_OBJ;

object floor, sign;
string log_bing, chair;

string reform_message(string str);

void setup() {
    set_short("meeting room");
    set_long("A large oak table dominates this room.  There are some heavy "
        "ornate looking candle sticks in the center of the table.  The table "
        "is surrounded by large expensive looking teak chairs, at one end of "
        "the table are some larger more expensive looking ones.  There is a "
        "small hammer sitting in the middle of the room.  There is a small "
        "sign on the wall.\n");

    set_light(70);

    add_item("oak table", "A large heavy looking oak table.  It was built to "
        "last and looks very old - you can tell by all the worn marks at the "
        "places around the table where people sit.");
    add_item("teak chair", "The chairs are overly ornate and obviously in a "
        "very good condition for their age.  The large chairs at the end are "
        "obviously not well used (you can tell, all the dust).");
    add_item("candle stick", "The candle sticks are made of silver, however "
        "if you try and take them, you notice they are attached to the table "
        "somehow.  The candles seemed to have been carved into the shape of "
        "a small chicken holding a torch.");
    add_item( ({"hammer", "gavel"}), "The gavel looks like ones fo those "
        "things so common in meeting rooms.  You could bang it around a "
        "little maybe, it might help if you had it though.");

    log_bing = 0;

    sign = add_sign("A small sign with not much written on it.\n",
                    "There is no current chair of the meeting.\n");

    add_exit("common", "/d/admin/common", "path" );

} /* setup() */

void reset() {
    if( !floor ) {
        floor = clone_object(OBJECT_OBJ);
        floor->set_name("floor");
        floor->set_short("floor");
        floor->set_determinate("the ");
        floor->set_long("This is the floor of the meeting.  It gives you the "
            "right to speak during the meeting.  Please give this to the "
            "next person to speak after you have finished.\n");
        floor->move(TO);
    }
} /* reset() */

int do_appoint( object ob ) {
    if( chair && (string)TP->query_name() != chair ) {
        add_failed_mess("The chair has already been appointed.\n");
        return 0;
    }

    chair = ob->query_name();

    if( ob == TP ) {
        tell_room( TO, TP->the_short()+" has just appointed "+TP->HIM+"self "
            "as the chair of the meeting.\n", ob );
        tell_object( TP, "You have just appointed yourself as the chair of "
            "the meeting.\n");
    } else {
        tell_room( TO, TP->the_short()+" has just appointed "+
            ob->the_short()+" as the chair of the meeting.\n", ob );
        tell_object( TP, "You have just appointed "+
            ob->the_short()+" as the chair of the meeting.\n");
        tell_object( ob, TP->the_short()+" has just appointed you as the "
            "chair of the meeting.\n");
    }

    sign->set_read_mess("The chair of the meeting is "+CAP(chair)+".");
    return 1;

} /* do_appoint() */

int do_bang() {
    if( TP->query_name() != chair ) {
        add_failed_mess("Only the chair can bang the gavel.\n");
        return 0;
    }

    add_succeeded_mess("$N bang$s the gavel loudly and yell$s: STOP! STOP!\n");
    return 1;

} /* do_bang() */

int do_recover() {
    reset();

    floor->move(TP);

    add_succeeded_mess( ({"You have recovered the floor.\n", "$N has "
        "recovered the floor.\n"}) );
    return 1;

} /* do_recover() */

int do_log(string str) {
    if( log_bing && !str ) {
        tell_object( TP, "Stopped logging.\n");
        log_bing = str;
        return 1;
    }

    if( !str ) {
        add_failed_mess("Syntax: 'log <file_name>'\n"+
                        "        'log' by itself to stop logging.\n");
        return 0;
    }

    if( log_bing )
        write("Stopped logging to "+log_bing+" and started logging to "+
            str+".\n");
    else
        write("Started logging to "+str+".\n");

    log_bing = str;
    return 1;

} /* do_log() */

void init() {
    ::init();

    if( interactive(TP) && ( lordp(TP) || TP->query_name() == chair ) ) {
        add_command("appoint", "<indirect:living'chair'>",
            (: do_appoint($1[0]) :) );
        add_command("bang", "gavel");
        add_command("recover", "floor"); // recovers the floor.
        add_command("log", "", (: do_log(0) :) );
        add_command("log", "[to] <string'file_name'>", (: do_log($4[0]) :) );
    }

} /* init() */

void event_person_say( object ob, string start, string rest ) {
    if( log_bing )
        log_file( log_bing, reform_message(start+rest)+"\n");
} /* event_person_say() */

void event_say( object ob, string rest ) {
    if( log_bing )
        log_file( log_bing, reform_message(rest)+"\n");
} /* event_say() */

void event_soul( object ob, string rest ) {
    if( log_bing )
        log_file( log_bing, reform_message(rest)+"\n");
} /* event_soul() */

void dest_me() {
    if( floor )
        floor->dest_me();
    ::dest_me();
} /* dest_me() */

string reform_message( string str ) {
    return PLAYER_OBJ->convert_message(str);
} /* reform_message() */
