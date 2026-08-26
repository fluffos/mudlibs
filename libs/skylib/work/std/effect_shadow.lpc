/**
 * This is the effect shadow inherit.
 * @changed Changed to use the shadow handler to recycle shadow.
 * - Sandoz, 3rd September 2002.
 */

object player;
int id;

/** @ignore yes */
object attach_to_player( object p, int i ) {
    player = p;
    id = i;
    return shadow( player, 1 );
} /* attach_to_player() */

/** @ignore yes */
void remove_effect_shadow( int i ) {
    if( i == id ) {
        if( !SHADOW_H->recycle_shadow(TO) )
            destruct(TO);
    } else {
        player->remove_effect_shadow(i);
    }
} /* remove_effect_shadow() */

/** @ignore yes */
protected mixed arg() {
    int enum;

    if( ( enum = (int)player->sid_to_enum( id ) ) == -1 ) {
#ifdef DEBUG
        log_file("EFFECTS", "%s: no effect for %s on %s\n",
            time(), file_name(TO), file_name(player) );
#endif
        destruct(TO);
        return 0;
    }

    return (mixed)player->arg_of( enum );

} /* arg() */

/** @ignore yes */
protected void set_arg( mixed newarg ) {
    player->set_arg_of( player->sid_to_enum(id), newarg );
} /* set_arg() */

/** @ignore yes */
protected void remove_this_effect() {
    player->delete_effect( (int)player->sid_to_enum( id ) );
} /* remove_this_effect() */
