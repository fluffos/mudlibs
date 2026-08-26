
inherit NPC_OBJ;

object caster;

int do_firewrite( string text );

void setup() {
    set_name("imp");
    set_short("fiery imp");
    add_adjective("ghastly little fiery");

    set_long("This is a ghastly little fiery imp.  It floats just out of "
        "reach, but you wouldn't want to go too close to it because of the "
        "heat and smell of brimstone.\n");

    basic_setup("imp", 15, 0 );

    set_msgin("$N hop$s in from $F.");
    set_msgout("$N hop$s out to $T.");

    set_mmsgout("$N %vanish% in a sudden flash of flame.");
    set_mmsgin("$N appear$s in a sudden flash of flame.");

} /* setup() */

void set_caster( object thing ) { caster = thing; }

object query_caster() { return caster; }

void init() {
    if( TP == caster )
        TP->add_command("firewrite", TO, "<string'text'>",
            (: do_firewrite($4[0]) :) );
} /* init() */

int adjust_hp( int hp, object attacker ) {
    if( hp < 0 )
        tell_object( attacker, "The imp moves quickly out of the way of "
            "your blow.\n" );
    return 0;
} /* adjust_hp() */

int do_firewrite( string text ) {
   if( !caster || TP != caster ) {
       init_command("signore "+(string)TP->query_name(), 2 );
       return notify_fail("");
   }

   FIREWORK_H->random_firework( TP, text );

   do_command("grimace");

   call_out("go_away", 2 );

   caster = 0;

   return 1;

} /* do_firework() */

void go_away() {
    do_command(":seems to implode on itself, leaving behind a small dot of "
        "flame which shoots up into the sky.");
    call_out("dest_me", 2 );
} /* go_away() */

void event_dest_me( object thing ) {
    if( thing == caster ) {
        do_command( "'Free! Free!" );
        do_command( "zip" );
        call_out("go_away", 2 );
        caster = 0;
    }
} /* event_dest_me() */

void event_exit( object thing, string dir, object to ) {
    if( thing == caster && to != environment() ) {
        do_command("'Free! Free!");
        do_command("zip");
        call_out("go_away", 2 );
        caster = 0;
    }
} /* event_exit() */
