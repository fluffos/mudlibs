/**
 * Coded By Rhaje@Phoenix/Nameless Sorrows from scratch.
 * New Shutdown Object. Some ideas were taken from RoD/Suvangi,
 * but no code was nicked in the process. Basic format was
 * ripped from Discworld.
 * Cleaned & tidied up by Donky.
 * Cleaned up by Galileo; 1-4-99
 * Reworked for Divided Sky - Shaydz 12-03-01
 */

#include <network.h>
#include <config.h>

#define REBOOT_TIME   (60*24*30) // Every 30 days.
#define INIT_MESSAGE  "%^GREEN%^The ground begins to tremble beneath "  \
                      "your feet, and suddenly hot burning ash shoots " \
                      "forth from the ground, filling the air around "  \
                      "you!\n%^RESET%^"
#define FINAL_MESSAGE "%^RED%^All around you, fiery red lava begins to "\
                      "shoot forth from the ground, filling the air, "  \
                      "bringing the heat in the room to unbelievable "  \
                      "levels...\n%^BOLD%^%^BLACK%^You attempt to let " \
                      "out a scream, but it is too late!\n%^BOLD%^"     \
                      "%^RED%^Your body is incinerated in the extreme " \
                      "heat!\n%^RESET%^"
#define ABORT_MESSAGE "%^BOLD%^%^BLUE%^Shutdown aborted!\n%^RESET%^"

private void warning_shutdown();
private void do_shutdown();

private nosave int time;

protected void create() {
    time = REBOOT_TIME;
    call_out("dec_shutdown", 60 );
} /* setup() */

int query_shutdown() { return time; }

private int shout( string str ) {
    map( efun::users(), (: tell_object( $1, $(str) ) :) );
    return 1;
} /* shout() */

int init_shutdown( int minutes, int flag ) {
    if( minutes < 0 )
        return 0;

    if( !minutes )
        return do_shutdown();

    remove_call_out("dec_shutdown");
    call_out("dec_shutdown", 60 );
    log_file("REBOOT", "Shutdown request ("+minutes+")\n");

    time = minutes;

    if( flag ) {
        shout(INIT_MESSAGE);
        warning_shutdown();
    }

    time--;
    return 1;

} /* shut() */

int abort_shutdown() {
    log_file("REBOOT", "Shutdown aborted at "+ctime(time())+"\n");
    init_shutdown(REBOOT_TIME, 0 );
    shout(ABORT_MESSAGE);
} /* abort_shutdown() */

private void warning_shutdown() {
    shout("%^RED%^Mud shutdown in "+time+" minute"+( time == 1 ? "" : "s")+
        ".\n%^RESET%^");
} /* warning_shutdown() */

private void do_shutdown() {
    shout(FINAL_MESSAGE);

    foreach( object ob in efun::users() )
        catch( ob->quit() );

    WEATHER_H->dest_me();

    log_file("REBOOT", "Mud shutdown at "+ctime(time())+"\n");
    call_out( (: shutdown(0) :), 2 );

} /* do_shutdown() */

void dec_shutdown() {
    switch( time ) {
      case 0:
        INTERMUD_H->shutdown();
        do_shutdown();
        return;
      case 1:
      case 2:
      case 3:
      case 5:
      case 10:
      case 20:
      case 30:
      case 45:
      case 60:
        warning_shutdown();
    }

    time--;
    call_out("dec_shutdown", 60 );

} /* dec_shutdown() */

void dest_me() {
    if( time )
        abort_shutdown();

    destruct(TO);
} /* dest_me() */
