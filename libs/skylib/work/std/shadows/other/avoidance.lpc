inherit "/std/effect_shadow";

/**
 * This method returns an array of names of
 * people this NPC is avoiding.
 * @return array of names we're avoiding
 */
mapping query_avoiding() { return arg(); }

/** @ignore yes */
void event_enter( object thing, string mess, object from ) {
    int time;
    mapping arg;

    player->event_enter( thing, mess, from );

    if( !mess || !thing->query_visible( player ) )
        return;

    if( !mapp( arg = arg() ) ||
        ( time = arg[ (string)thing->query_name() ] ) < 1 )
        return;

    call_out("avoid_them", 1, thing, time );

} /* event_enter() */

/** @ignore yes */
void event_move_object( mixed from, mixed to ) {
    int time;
    object thing, *things;
    mapping arg;

    player->event_move_object( from, to );

    if( !mapp( arg = arg() ) || !sizeof(arg) ||
        !sizeof( things = filter( INV( ENV( player ) ),
        (: living($1) && $1->query_visible(player) :) ) ) )
        return;

    foreach( thing in things ) {
        if( time = arg[ (string)thing->query_name() ] ) {
            call_out("avoid_them", 1, thing, time );
            return;
        }
    }
} /* event_move_object() */

/** @ignore yes */
void avoid_them( object thing, int number ) {
    if( !thing || ENV( thing ) != ENV( player ) )
        return;

    if( random( number ) > 60 )
        player->do_command("unfollow "+(string)thing->query_name() );

    player->run_away();

} /* avoid_them() */
