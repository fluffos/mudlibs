/**
 * This is the effect shadow for flowers attached to clothes.
 * @author Sandoz, July 2003.
 */

#define QMS(x) query_multiple_short(x)

inherit "/std/effect_shadow";

int remove_flower( string remove, object *obs );

/** @ignore yes */
void init_remove_cmd( object who ) {
    object store;

    if( arg() && objectp( store = arg()[0] ) && sizeof( INV(store) ) ) {
        who->add_command("remove", TO,
            "<string'flower(s)'> from <indirect:object:me-here>",
            (: remove_flower( $4[0], $1 ) :) );
        who->add_command("unattach", TO,
            "<string'flower(s)'> from <indirect:object:me-here>",
            (: remove_flower( $4[0], $1 ) :) );
    }

} /* init_remove_cmd() */

/** @ignore yes */
void init() {
    init_remove_cmd(TP);
    return player->init();
} /* init() */

/** @ignore yes */
void remove_remove_cmd() {
    object env;

    if( player && ( env = ENV(player) ) ) {
        env->remove_object2( TO, 1 );
        if( env = ENV(env) ) {
            foreach( object user in filter( INV(env), (: userp($1) :) ) )
                user->remove_object2( TO, 1 );
        }
    }

} /* remove_remove_cmd() */

/** @ignore yes */
void dest_me() {
    remove_remove_cmd();

    if( player ) {
        object store;

        if( arg() && objectp( store = arg()[0] ) )
            store->dest_me();

        player->dest_me();
    }
} /* dest_me() */

/**
 * This method will query whether or not it is ok to attach more
 * flowers into the clothing object.
 * @return 1 if we've reached our limit, 0 if it's ok to attach more
 */
int query_cannot_attach_flowers() {
    string *areas;
    object store;
    mixed tmp;
    int max;

    if( !arg() || !objectp( store = arg()[0] ) )
        return 0;

    areas = ({ });

    if( pointerp( tmp = TO->query_type() ) ) {
        foreach( tmp in tmp )
            areas += CLOTHING_H->query_zone_names(tmp);
        areas = uniq_array( areas );
    } else {
        areas = CLOTHING_H->query_zone_names(tmp);
    }

    max = sizeof( areas ) + 2;

    return sizeof( INV(store) ) >= max;

} /* query_cannot_attach_flowers() */

/** @ignore yes */
int remove_flower( string remove, object *obs ) {
    object store, *flowers;

    if( member_array( player, obs ) == -1 ) {
        add_failed_mess("You cannot remove any flowers from $I.\n", obs );
        return 0;
    }

    if( !arg() || !objectp( store = arg()[0] ) ) {
        add_failed_mess("There doesn't appear to be anything attached "
            "to $I.\n", ({ player }) );
        return 0;
    }

    if( !sizeof( flowers = match_objects_for_existence( remove, store ) ) ) {
        add_failed_mess("There doesn't appear to be any '"+
            remove+"' attached to $I.\n", ({ player }) );
        return 0;
    }

    flowers->move(TP);

    add_succeeded_mess("$N gently remove$s $I from "+player->the_short()+".\n",
        flowers );

    if( !sizeof( INV(store) ) )
        remove_this_effect();

    return 1;

} /* remove_flower() */

/** @ignore yes */
int query_complete_weight() {
    object store;

    if( objectp( store = arg()[0] ) )
        return player->query_complete_weight() + store->query_loc_weight();

    return player->query_complete_weight();

} /* query_complete_weight() */

/** @ignore yes */
void break_me() {
    object ob, *flowers;

    if( sizeof( arg() ) && objectp( ob = arg()[0] ) )
        flowers = INV(ob);

    ob = player;

    if( sizeof(flowers) ) {
        object env;

        env = ENV(ob);

        if( living(env) ) {
            if( ENV(env) ) {
                flowers->move( ENV(env) );
                tell_room( ENV(env), QMS(flowers)+" "
                    "$V$0=becomes,become$V$ detached from "+
                    env->poss_short()+" "+ob->short()+" and "
                    "$V$0=falls,fall$V$ "+
                    ( ENV(env)->query_property("here") || "off")+".\n");
            } else {
                flowers->move(env);
                tell_object( env, QMS(flowers)+" $V$0=becomes,become$V$ "
                    "detached from your "+ob->short()+" and "
                    "$V$0=falls,fall$V$ off.\n");
            }
        } else {
            flowers->move(env);
            tell_room( env, QMS(flowers)+" $V$0=becomes,become$V$ "
                "detached from "+ob->the_short()+" and $V$0=falls,fall$V$ "+
                ( env->query_property("here") || "off")+".\n");
        }
    }

    remove_remove_cmd();
    player->break_me();
    remove_this_effect();

} /* break_me() */

/** @ignore yes */
private object *short_filter() {
    object store;

    if( !player->query_property("NOF") && sizeof( arg() ) &&
        objectp( store = arg()[0] ) && sizeof( INV(store) ) )
        return filter( INV(store), (: !$1->query_property("ignore_short") :) );

} /* short_filter() */

/** @ignore yes */
string long( string str, int dark ) {
    player->add_property("NOF", 1 );

    str = player->long( str, dark );

    player->remove_property("NOF");

    return str;

} /* long() */

/** @ignore yes */
string short( int dark ) {
    object *flowers;

    if( !player )
        return "attached flower shadow";

    if( sizeof( flowers = short_filter() ) )
        return player->short( dark )+" adorned with "+
            PLAYER_OBJ->convert_message( QMS( flowers ) );

    return player->short( dark );

} /* short() */

/** @ignore yes */
string query_plural( int dark ) {
    object *flowers;

    if( !player )
        return "attached flower shadow";

    if( sizeof( flowers = short_filter() ) )
        return player->query_plural( dark )+" adorned with "+
            PLAYER_OBJ->convert_message( QMS( uniq_array( map(
            flowers, (: $1->query_plural() :) ) ) ) );

    return player->query_plural( dark );

} /* query_plural() */
