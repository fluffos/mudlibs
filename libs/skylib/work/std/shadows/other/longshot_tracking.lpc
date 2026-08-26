inherit "/std/effect_shadow";
#include <move_failures.h>
#include <ranged_response.h>


#define BP tell_object( find_player("gerbil"), "BP.\n");
#define TG tell_object( find_player("gerbil"), 
#define ERROR "/w/gerbil/TOYS/error_handler"

object *trackers = ({ });
object last;
int run;

void add_tracker( object ob ) {
    if( member_array( ob, trackers ) == -1 )
        trackers += ({ ob });
}

varargs int move( mixed dest, string inmess, string outmess ) {
    int i;
    i = player->move( dest, inmess, outmess );
    if( !player ) return i;
    if( i == MOVE_OK ) 
        trackers->target_moved( player, dest );
    return i;
}

void remove_tracker( object ob ) {
    if( member_array( ob, trackers ) != -1 ) {
        trackers -= ({ ob });
    }
    if( !sizeof( trackers ) )
        remove_this_effect();
}

object *query_trackers() { return trackers; }

void diag() {
    TG query_multiple_short( trackers->query_short() ) + " : tracker check...\n");
}

object do_death( object ob ) {
    trackers->target_died( player );
    if( last ) {
        ERROR->log_kills( last, player );
        return player->do_death( ob );
    }
    return player->do_death( ob );
}

void set_last_person_who_shot_me( object ob ) {
    last = ob;
}

void run_from_firer( object firer, object launcher ) {
    string *str, *exits, dir;
    int i;
    exits = environment( player )->query_dest_dirs();
    if( !sizeof( exits ) ) {
        return;
    }
    for( i=0;i<sizeof( exits );i+=2) {
        str += ({ exits[i] });
    }
    exits = launcher->query_return_path();
    str -= ({ exits[sizeof(exits) - 1] });
    if( !sizeof( str ) ) {
        dir = exits[sizeof(exits) - 1];
    } else {
        dir = str[random( sizeof( str ) )];
    }
    player->do_command( dir );
    call_out( "run_from_firer", 2, firer, launcher );
}

varargs void run_to_firer( object firer, object launcher, string path ) {
    if( !path ) {
        path = launcher->query_return_path();
    }
    player->do_command( path[0] );
    if( sizeof( path ) > 2 ) {
        path = path[1..];
        call_out( "run_to_firer", 1, firer, launcher, path );
    } else {
        run = 0;
    }
}




void npc_fired_upon( object firer, object bullet, object launcher ) {
    int i, j;
    mixed res;
    if( !player->query_ranged_response() ) {
        i = player->query_level();
        j = firer->query_level();
        if( i > j ) {
            player->attack_firer();
        } else {
            player->run_from_firer();
        }
    } else {
        res = player->query_ranged_response();
        if( functionp( res ) ) {
            // call function
            return;
        }
        switch( res ) {
        case FIGHT : if( !run ) {
                run = 1;
                run_from_firer( firer, launcher ); 
            }
            break;
        case RUN : run_to_firer( firer, launcher );
            break;
        case STAND : break;
        default : break;
        }
    }      
}

