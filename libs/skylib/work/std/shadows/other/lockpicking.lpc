/**
 * This is the effect shadow for the lpick command effect.
 * @author Sandoz, Nov. 2002.
 */

inherit "/std/effect_shadow";

class lockpick_data {
    object door;
    object pick;
    int diff;
    int delay;
    int stage;
}

/** @ignore yes */
int queue_commands() { return 1; }

/**
 * This method returns the lock (door) object we are currently in the
 * middle of picking.
 * @return the door object we are lpicking
 */
object query_lockpicking() { return arg()->door; }

/** @ignore yes */
void interrupt_lockpicking() {
    class lockpick_data data;

    if( classp( data = arg() ) ) {
        data->door->remove_property("lockpicked");
        if( !data->stage ) {
            tell_object( player, "You hastily stop scrutinizing the lock on "+
                data->door->the_short()+".\n");
            tell_room( player, player->the_short()+" hastily stops "
                "scrutinizing the lock on "+data->door->the_short()+".\n",
                player );
        } else {
            tell_object( player, "You hastily pull "+
                data->pick->the_short()+" out of the lock on "+
                data->door->the_short()+".\n");
            tell_room( player, player->the_short()+" hastily pulls "+
                data->pick->poss_short()+" out of the lock on "+
                data->door->the_short()+".\n", player );
        }
    }

    remove_this_effect();

} /* interrupt_lockpicking() */

/** @ignore yes */
void event_move_object( mixed from, mixed to ) {
    class lockpick_data data = arg();
    object who = player;

    if( !data->stage ) {
        tell_object( who, "You stop scrutinizing the lock on "+
            data->door->the_short()+" as you leave.\n");
        tell_room( who, who->the_short()+" stops scrutinizing the lock on "+
            data->door->the_short()+" as "+who->HE+" leaves.\n", who );
    } else {
        tell_object( who, "You pull "+data->pick->the_short()+" out of the "
            "lock on "+data->door->the_short()+" as you leave.\n");
        tell_room( who, who->the_short()+" pulls "+
            data->pick->poss_short()+" out of the lock on "+
            data->door->the_short()+" as "+who->HE+" leaves.\n", who );
    }

    set_arg(0);
    interrupt_lockpicking();

    return who->event_move_object( from, to );

} /* event_move_object() */

/** @ignore yes */
int attack_by( object ob ) {
    int ret;

    if( ret = player->attack_by( ob ) )
        interrupt_lockpicking();

    return ret;

} /* attack_by() */

/** @ignore yes */
int attack_ob( object ob ) {
    int ret;

    if( ret = player->attack_ob( ob ) )
        interrupt_lockpicking();

    return ret;

} /* attack_by() */

/** @ignore yes */
mixed stats() {
    class lockpick_data data;

    data = arg();

    return player->stats() + ({
        ({"lockpicking", data->door }),
        ({"lockpick", data->pick }),
        ({"lockpick difficulty", data->diff }),
        ({"lockpick delay", data->delay }),
        ({"lockpick stage", data->stage }),
    });

} /* stats() */

/** @ignore yes */
void event_door_open( object door, object who ) {
    class lockpick_data data;

    data = arg();

    player->event_door_open( door, who );

    if( door == data->door ) {
        if( who == player )
            return interrupt_lockpicking();

        tell_object( player, "You bump your head against "+
            door->the_short()+" as "+( query_group(door) ?
            "they are" : "it is")+" opened.\n");

        tell_room( ENV(player), player->the_short()+" bumps "+
            player->HIS+" head against "+door->the_short()+" as "+
            ( query_group(door) ? "they are" : "it is")+" opened.\n",
            player );

        return interrupt_lockpicking();
    }

} /* event_door_open() */
