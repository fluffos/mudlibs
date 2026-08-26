
#include <config.h>
#include <terrain.h>

#define SAVE_FILE RESTORE_PATH "logroom"

nosave inherit ROOM_OBJ;

private mapping locations;

/** @ignore yes */
private void save_me() {
    unguarded( (: save_object, SAVE_FILE :) );
} /* save_me() */

/** @ignore yes */
int query_keep_room_loaded() { return 1; }

void setup() {
    set_short("limbo");
    set_light(50);
    set_long("You are between worlds, surrounded by raw potentiality and "
        "not a lot else.\n");

    add_item("potentiality", "Well, it's sort of potentially something and "
        "potentially nothing, and it can't quite decide at the moment.  "
        "With any luck, though, you won't be here long enough to find out.\n");

    add_exit("pub", CONFIG_START_LOCATION, "path");

    if( file_exists( SAVE_FILE+".o") )
        unguarded( (: restore_object, SAVE_FILE :) );

    if( mapp(locations) ) {
        int sz = sizeof(locations);

        locations = filter( locations, (: PLAYER_H->test_user($1) :) );

        if( sz != sizeof(locations) )
            save_me();

    } else {
       locations = ([ ]);
    }

} /* setup() */

/** @ignore yes */
void player_quitting( object player, object place ) {
    if( player->query_property("guest") )
        return;

    locations[ player->query_name() ] = ({ place->query_terrain(),
                                           place->query_co_ord() });

    save_me();

    call_out("check_quitted", 5, player->query_name() );

} /* player_quitting() */

/** @ignore yes */
void check_quitted( string who ) {
    if( find_player(who) && locations[who] ) {
        map_delete( locations, who );
        save_me();
    }
} /* check_quitted() */

/** @ignore yes */
void event_enter( object player, string mess, object thing ) {
    mixed location, data;

    if( data = locations[ player->query_name() ] ) {
        if( !location = TERRAIN_MAP->find_location( data[0], data[1] ) )
            location = player->query_start_pos();
        player->move(location);
        map_delete( locations, player->query_name() );
        return save_me();
    }

    tell_object( player, "Moving you to your starting location...\n");
    player->move( player->query_start_pos() );

} /* event_enter() */
