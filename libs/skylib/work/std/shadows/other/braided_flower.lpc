/**
 * This is the effect shadow for braided flowers.
 * @author Sandoz, 31. Dec. 2001.
 */

#define BRAID_MAX 5

inherit "/std/effect_shadow";

int do_unbraid( string remove );

/** @ignore yes */
void init() {
    object store;

    if( objectp( store = arg()[0] ) && sizeof(INV(store)) ) {
        player->add_command("unbraid", TO, "<string'flower(s)'> from my hair",
             (: do_unbraid($4[0]) :) );
        player->add_command("remove", TO, "<string'flower(s)'> from my hair",
             (: do_unbraid($4[0]) :) );
    }

    return player->init();

} /* init() */

/** @ignore yes */
void remove_unbraid_cmd() {
    player->remove_object2( TO, 1 );
} /* remove_unbraid_cmd() */

/**
 * This method will query whether or not it is ok to braid more
 * flowers into our hair.
 * @return 1 if we've reached our limit, 0 if it's ok to braid more
 */
int query_cannot_braid() {
    object store;

    if( !objectp( store = arg()[0] ) )
        return 0;

    return sizeof(INV(store)) >= BRAID_MAX;

} /* query_cannot_braid() */

/** @ignore yes */
int do_unbraid( string remove ) {
    object store, *flowers;

    if( !objectp( store = arg()[0] ) ) {
        add_failed_mess("There doesn't appear to be anything braided into "
            "your hair.\n");
        return 0;
    }

    if( !sizeof( flowers = match_objects_for_existence( remove, store ) ) ) {
        add_failed_mess("There doesn't appear to be any '"+remove+"' braided "
            "into your hair.\n");
        return 0;
    }

    flowers->move(TP);
    add_succeeded_mess("$N $V $I from $p hair.\n", flowers );

    if( !sizeof(INV(store)) )
        remove_this_effect();

    return 1;

} /* do_unbraid() */
