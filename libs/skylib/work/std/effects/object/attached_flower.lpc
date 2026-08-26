/**
 * This is the effect for flowers attached to clothes.
 * @author Sandoz, July 2003.
 */

#include "path.h"
#include <effect.h>

#define CLASSIFICATION "flowers.attached"

#define QMS(x) query_multiple_short(x)

private mapping call_ids = ([ ]);

/** @ignore yes */
string query_classification() { return CLASSIFICATION; }
/** @ignore yes */
string query_shadow_ob() { return SHADOWS+"attached_flower"; }
/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
object make_store() {
    object store;

    store = clone_object("/std/container");
    store->set_name("attached flower store");
    store->add_property("don't break contents", 1 );

    return store;

} /* make_store() */

/** @ignore yes */
void init_remove_cmd( object ob ) {
    object env;

    if( objectp(ob) ) {
        if( env = ENV(ob) ) {
            // We're in someone's inventory.
            if( userp( env ) ) {
                ob->init_remove_cmd( env );
            } else {
                foreach( object user in filter( INV(env), (: userp($1) :) ) )
                    ob->init_remove_cmd( user );
            }
        }
    }

} /* init_remove_cmd() */

/** @ignore yes */
mixed beginning( object ob, object flower ) {
    object store;

    store = make_store();
    flower->move(store);
    ob->add_extra_look( base_name(TO) );
    call_out("init_remove_cmd", 0, ob );

    return ({ store, 0 });

} /* beginning() */

/** @ignore yes */
mixed merge_effect( object ob, mixed args, object flower ) {
    if( !objectp( args[0] ) )
        args[0] = make_store();

    flower->move( args[0] );

    return args;

} /* merge_effect() */

/** @ignore yes */
void restart( object ob, mixed args, int enum ) {
    object store;

    if( !args[1] ) {
        ob->submit_ee( 0, 0, EE_REMOVE );
        return;
    }

    store = make_store();

    ob->set_arg_of( enum, ({ store, 0 }) );

    store->init_dynamic_arg( args[1] );

    call_out("init_remove_cmd", 0, ob );

    ob->add_extra_look( base_name(TO) );

} /* restart() */

/** @ignore yes */
void clean_arg( object ob, object store ) {
    int *enums;

    if( !ob || !call_ids[ob] )
        return;

    if( sizeof( enums = ob->effects_matching(CLASSIFICATION) ) )
        ob->set_arg_of( enums[ 0 ], ({ store, 0 }) );

    map_delete( call_ids, ob );

} /* clean_arg() */

/** @ignore yes */
void saving( object ob, mixed args, int enum ) {
    if( !objectp( args[0] ) )
        return;

    if( !sizeof( INV(args[0]) ) ) {
        ob->submit_ee( 0, 0, EE_REMOVE );
        return;
    }

    ob->set_arg_of( enum, ({ args[0], args[0]->query_dynamic_auto_load() }) );

    if( call_ids[ob] )
        remove_call_out(call_ids[ob]);

    call_ids[ob] = call_out( (: clean_arg :), 10, ob, args[0] );

} /* saving() */

/** @ignore yes */
void quiting( object ob, mixed args, int enum ) {
    if( ob && call_ids[ob] )
        map_delete( call_ids, ob );

    if( objectp( args[0] ) )
        args[0]->dest_me();

} /* quiting() */

/** @ignore yes */
void end( object ob, mixed args ) {
    object *flowers, env;

    ob->remove_remove_cmd();
    ob->remove_extra_look(TO);

    if( ob )
        map_delete( call_ids, ob );

    if( !objectp( args[0] ) )
        return;

    if( sizeof( flowers = INV( args[0] ) ) ) {
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

    args[0]->dest_me();

} /* end() */

/** @ignore yes */
string extra_look( object ob ) {
    object store, *flowers;
    int *enums, group;

    if( !sizeof( enums = ob->effects_matching(CLASSIFICATION) ) ||
        !objectp( store = ob->arg_of( enums[ 0 ] )[0] ) ||
        !sizeof( flowers = INV( store ) ) )
        return "";

    group = query_group(ob);

    return ( group ? "They have" : "It has")+" been adorned with "+
             QMS(flowers)+".\n";

} /* extra_look() */
