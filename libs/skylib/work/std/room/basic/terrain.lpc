/**
 * This contains all the terrain specific code of rooms.
 * @author Sandoz, 2002
 */

#include <dirs.h>
#include <terrain.h>

private nosave string terrain_name;

/** @ignore yes */
void set_terrain( string name ) {
    TERRAIN_MAP->setup_location( TO, name );
    terrain_name = name;
} /* set_terrain() */

/**
 * This method returns the name of the terrain this room is part of.
 * @return the name of the terrain we are in
 */
string query_terrain() { return terrain_name; }

/** @ignore yes */
void dest_me() {
    TERRAIN_MAP->delete_cloned_location( terrain_name, file_name(TO) );
} /* dest_me() */

/** @ignore yes */
void event_exit( object thing, string message, object to ) {
    if( clonep() && !sizeof(INV(TO)) && find_call_out("real_clean") == -1 )
        call_out("real_clean", 5 + random( 5 ) );
} /* event_exit() */

/** @ignore yes */
void set_destination( string direc ) {
    int i, j, delta, *co_ords, *new_co_ords = allocate(3);
    string dest_name;
    object destination;

    if( ( i = member_array( direc, STD_ORDERS ) ) == -1 )
        return;

    dest_name = TO->query_destination(direc);
    delta = TO->query_room_size() + TERRAIN_MAP->get_room_size(dest_name);
    co_ords = TO->query_co_ord();

    for( j = 0; j < 3; j++ )
        new_co_ords[j] = co_ords[j] - delta * STD_ORDERS[i+1][j];

    destination = TERRAIN_MAP->find_location( terrain_name, new_co_ords );

    if( destination )
        TO->modify_exit( direc, ({"dest", file_name(destination) }) );

} /* set_destination() */

/** @ignore yes */
string query_quit_handler() { return TERRAIN_LOG; }

/** @ignore yes */
mixed *query_cloning_info() {
    return ({ TERRAIN_MAP, "find_location",
              terrain_name, TO->query_co_ord() });
} /* query_cloning_info() */

/** @ignore yes */
mixed stats() { return ({ ({"terrain name", terrain_name }) }); }
