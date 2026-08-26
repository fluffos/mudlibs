inherit "/std/effect_shadow";
#include <move_failures.h>

string query_tester() { return arg(); }

int move( mixed dest, string mess1, string mess2 ) {
    object tester;
    int i;
    if( this_player() ) {
        tester = this_player();
    } else {
        if( dest->query_property( "player" ) ) {
            tester = dest;
        }
    }
    if( ( i = player->move( dest, mess1, mess2 ) ) == MOVE_OK ) {
        if( tester )
            if( playtesterp( tester ) ) {
                set_arg( tester->query_name() );
            }
    }
    return i;
}
