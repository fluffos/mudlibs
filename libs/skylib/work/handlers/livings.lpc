/**
 * This is the livings handler.
 * @author Someone at DW, most likely.
 * @change Rewritten to be a fair bit faster - Sandoz, 2002.
 */

#define CLEANUP_INTERVAL 600

#include <runtime_config.h>

private nosave mapping livings, lnames;
private nosave int max_size, cur_size;

private void remove_garbage();

/** @ignore yes */
private void create() {
    livings = ([ ]);
    lnames = ([ ]);

    max_size = get_config( __MAX_MAPPING_SIZE__ );

    call_out( (: remove_garbage :), CLEANUP_INTERVAL );

} /* create() */

/**
 * This method cleans up the livings and living names
 * array of dested objects.
 */
private void remove_garbage() {
    string name;

    call_out( (: remove_garbage :), CLEANUP_INTERVAL );

    livings = allocate_mapping( keys(livings) - ({ 0 }), 1 );
    cur_size = sizeof(livings);

    foreach( name in keys(lnames) )
        if( !sizeof( lnames[name] -= ({ 0 }) ) )
            map_delete( lnames, name );

} /* remove_garbage() */

/** @ignore yes */
void enable_commands( object ob ) {
    if( ++cur_size > max_size ) {
        if( ( cur_size = sizeof(livings) ) >= max_size - 1 )
            error("Maximum mapping size reached in enable_commands().\n");
        else
            cur_size++;
    }

    livings[ob] = 1;

} /* enable_commands() */

/** @ignore yes */
void set_living_name( string name, object ob ) {
    if( !lnames[name] ) {
        lnames[name] = ({ ob });
    } else {
        lnames[name] += ({ ob });
    }
} /* set_living_name() */

/** @ignore yes */
int living( object ob ) { return livings[ob]; }

/** @ignore yes */
object *named_livings() {
    string name;
    object *ret;

    ret = ({ });

    foreach( name in keys(lnames) ) {
        if( !sizeof( lnames[name] -= ({ 0 }) ) )
            map_delete( lnames, name );
        else
            ret += lnames[name];
    }

    return ret;

} /* named_livings() */

/** @ignore yes */
object find_living( string it ) {
    object ob;

    if( !undefinedp( lnames[it] ) ) {
        if( !sizeof( lnames[it] -= ({ 0 }) ) ) {
            map_delete( lnames, it );
            return 0;
        }

        if( sizeof( lnames[it] ) == 1 )
            return lnames[it][0];

        foreach( ob in lnames[it] )
            if( clonep(ob) )
                return ob;

        return lnames[it][0];

    }

    return 0;

} /* find_living() */

/** @ignore yes */
object find_player( string it ) {
    object *people;

    if( !undefinedp( lnames[it] ) ) {
        if( !sizeof( lnames[it] -= ({ 0 }) ) ) {
            map_delete( lnames, it );
        } else {
            people = filter( lnames[it], (: userp($1) &&
                inherits("/std/container", $1 ) :) );
            if( sizeof(people) )
                return people[0];
        }
    }

    people = filter( users(), (: $1->query_name() == $2 &&
        inherits("/std/container", $1 ) :), it );

    if( sizeof(people) )
        return people[0];

    return 0;

} /* find_player() */

/** @ignore yes */
void living_dested() {
    if( PO ) {
        string name;

        if( !undefinedp( livings[PO] ) )
            map_delete( livings, PO );

        name = PO->query_name();

        if( !undefinedp( lnames[name] ) &&
            !sizeof( lnames[name] -= ({ PO }) ) )
            map_delete( lnames, name );
    }
} /* living_dested() */

/** @ignore yes */
mapping *query_dynamic_auto_load() { return ({ lnames, livings }); }

/** @ignore yes */
void init_dynamic_arg( mapping *map ) {
    if( !pointerp( map ) || sizeof(map) != 2 )
        return;

    if( mapp(map[0]) )
        lnames = map[0];
    if( mapp(map[1]) )
        livings = map[1];

} /* init_dynamic_arg() */
