/**
 * This is the rubbish room.  Anything coming here will be either
 * recycled in five seconds, or destructed if not suitable for recycling.
 * Simplified from the old rubbish room.
 * @author Sandoz, Sept. 2002.
 */

inherit ROOM_OBJ;

private void recycle_object( object ob );

/** @ignore yes */
int query_keep_room_loaded() { return 1; }

/** @ignore yes */
int no_event_enter() { return 1; }

/** @ignore yes */
int no_init() { return 1; }

void setup() {
    set_light(40);
    set_short("rubbish room");
    set_long("This is the rubbish room.  Everything (no, not you) coming "
        "here will be recycled, or destroyed in five seconds.\n");
} /* setup() */

/** @ignore yes */
private void recycle_object( object ob ) {
    object *obs, tmp, worn;

    if( !ob || userp(ob) || ENV(ob) != TO )
        return;

    if( obs = query_shadows(ob) )
        foreach( tmp in obs )
            SHADOW_H->recycle_shadow(tmp);

    foreach( tmp in filter( deep_inventory(ob), (: !userp($1) :) ) ) {
        if( worn = tmp->query_worn_by() )
            worn->remove_armour(tmp);
        tmp->move(TO);
    }

    if( !ARMOURY_H->recycle_object( ob ) ) {
        ob->dest_me();
        if( ob )
            destruct(ob);
    }

} /* recycle_object() */

/** @ignore yes */
int test_add( object ob, int flag ) {
    if( !interactive(ob) ) {
        mixed from;

        from = ENV(ob);
        from = ( !from ? "null-space" : file_name(from) );

        event( filter( INV(TO), (: interactive($1) :) ), "inform",
            sprintf("%O arriving from %O", ob->short(), from ), "debug");

        call_out( (: recycle_object :), 5, ob );

    }

    return ::test_add( ob, flag );

} /* test_add() */

/**
 * @ignore yes
 * This just cleans up anything that got left behind. If a callout got lost
 * or went wrong or something this'll make sure our rubbish room is clean.
 */
void reset() {
    object ob;
    int i;

    i = 1;

    foreach( ob in filter( INV(TO), (: !interactive( $1 ) :) ) )
        call_out( (: recycle_object :), ++i, ob );

} /* reset() */

/** @ignore yes */
string long( string word, int dark ) {
    if( query_verb() == "scry")
        return "Empty space\n.";
    return ::long( word, dark );
} /* long() */
