
#define FROG_HOME VOID_ROOM

inherit NPC_OBJ;

string from, to;

void setup() {
    set_name("frog");
    basic_setup("imp", 1, 1 + random(2) );

    set_long("A small green frog with a large brightly coloured post office "
        "hat.  "+CAP(HE)+" has a small bag slung over "+HIS+" shoulder in "
        "which are stuffed literally hundreds of letters.  "+CAP(HE)+" has a "
        "broad smile on "+HIS+" face and obviously enjoys "+HIS+" job.\n");

    add_adjective( ({"small", "green", "post", "office"}) );
    add_property("non vinable", the_short()+" quickly dodges out of the "
        "vines' way.");

    add_property("demon", 1 );

} /* setup() */

void adjust_hp( int hp, object at ) {
} /* adjust_hp() */

int attack_by( object thing ) {
    tell_object( thing, "You don't want to attack the frog, surely?\n");
    thing->stop_fight( TO );
    thing->add_effect("/std/effects/ingested/calm", 60 );
    return 0;
} /* attack_by() */

void found_player( object, mixed room, int ok ) {
    // "room" is apparently the player we're trying to find.
    if( !ok || !objectp( room ) ) {
        do_command("'I almost had them!");
        do_command("sigh");
        return;
    }

    if( !room->query_visible( TO ) ) {
        do_command("'That's odd...");
        do_command("puzzle");
        return;
    }

    if( to != from ) {
        do_command("point "+to );
        do_command( "whisper You have been sent some mail by "+
            CAP(from) +"; go to a post office to read it. to "+to );
    } else {
        do_command("smirk "+to );
        do_command("whisper Hey, weirdo, you sent yourself some mail, "
            "just in case you didn't know. to "+to );
    }

    init_command("'Cheerio!", 1 );
    init_command("wave", 1 );

} /* found_player() */

void got_home(object, mixed, int ok) {
    if( !ok )
        move( FROG_HOME, "$N hop$s in.", "$N hop$s away.");
    do_command("'Ah, home again.");
} /* got_home() */

void send_mail( string t, string f ) {
    to = t;
    from = f;

    if( find_player( to ) ) {
        // First try and rush to that gosh darn player.
        add_effect("/std/effects/npc/goto_destination",
          ({ find_player(to), ({ TO, "found_player" }), 10 }) );
    }

    add_effect("/std/effects/npc/goto_destination",
        ({ FROG_HOME, ({ TO, "got_home"}), 10 }));

} /* send_mail() */
