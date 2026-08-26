inherit "/std/effect_shadow";
#include <move_failures.h>
/*
* Coded by Gerbil 8/2/1999 for use with longshot type items.
*/

#define BP tell_object( find_player("gerbil"), "BP.\n");
#define TG tell_object( find_player("gerbil"), 

object *holding = ({ });
object active;
mixed * death_reason = ({ });

void holding( object ob ) {
    holding += ({ ob });
}

object * query_longshot_holding() { return holding; }

void stopped_holding( object ob ) {
    holding -= ({ ob });
    holding = filter_array( holding, (: $1 :) );
    if( !sizeof( holding ) ) {
        remove_this_effect();
    }
}

varargs int move( mixed dest, string inmess, string outmess ) {
    int i;
    holding = filter_array( holding, (: $1 :) );
    i = player->move( dest, inmess, outmess );
    if( !player ) return i;
    if( i == MOVE_OK ) 
        holding->reset_vars();
    return i;
}

void set_death_reason( string mess, object ob ) {
    death_reason += ({ ob, mess });
}

void purge_death_reason( object ob ) {
    int i;
    i = member_array( ob, death_reason );
    if( i == -1 ) {
        return;
    }
    death_reason -= ({ death_reason[i + 1] });
    death_reason -= ({ death_reason[i] });
}

void set_active_item( object ob ) {
    active = ob;
}

void reset_active_item() {
    active = 0;
}

object query_active_item() {
    return active;
}

string query_death_reason() {
    int i;
    if( !active ) {
        return 0;
    }
    if( (i = member_array( active, death_reason ) ) == -1 ) {
        return 0;
    }
    return death_reason[i + 1];
}
