/**
 * This is the effect for braided flowers.
 * @author Sandoz, 31. Dec. 2001.
 */

#include "path.h"
#include <effect.h>

#define CLASSIFICATION "flowers.braided"

/** @ignore yes */
string query_classification() { return CLASSIFICATION; }
/** @ignore yes */
string query_shadow_ob() { return SHADOWS+"braided_flower"; }
/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
object make_store( object player ) {
    object store;

    store = clone_object("/std/container");
    store->set_player( player );
    store->set_name("flower store");
    store->add_property("don't break contents", 1 );

    return store;

} /* make_store() */

/** @ignore yes */
void init_unbraid( object player ) {
    if( objectp(player) )
        player->init();
} /* init_unbraid() */

/** @ignore yes */
mixed beginning( object player, object flower ) {
   object store;

   store = make_store( player );
   flower->move( store );
   player->add_extra_look( TO );
   call_out("init_unbraid", 0, player );

   return ({ store, 0 });

} /* beginning() */

/** @ignore yes */
mixed merge_effect( object player, mixed args, object flower ) {
   if( !objectp( args[0] ) )
       args[0] = make_store( player );

   flower->move( args[0] );

   return args;

} /* merge_effect() */

/** @ignore yes */
void restart( object player, mapping args, int enum ) {
   object store;

   store = make_store( player );
   store->init_dynamic_arg( args[1] );
   call_out("init_unbraid", 0, player );
   player->add_extra_look( TO );
   player->set_arg_of( enum, ({ store, 0 }) );

} /* restart() */

/** @ignore yes */
void clean_arg( object player, object store ) {
   int *enums;

   if( !player )
       return;

   enums = (int *)player->effects_matching(CLASSIFICATION);
   player->set_arg_of( enums[ 0 ], ({ store, 0 }) );

   if( !sizeof( INV(store) ) )
       player->submit_ee( 0, 0, EE_REMOVE );

} /* clean_arg() */

/** @ignore yes */
void saving( object player, mixed args, int enum ) {
   if( !objectp( args[0] ) )
       return;

   player->set_arg_of( enum,
       ({ args[0], (mapping)args[0]->query_dynamic_auto_load() }) );
   call_out("clean_arg", 10, player, args[0] );

} /* saving() */

void quiting( object player, mixed args, int enum ) {
    if( objectp(args[0]) )
        args[0]->dest_me();
} /* quiting() */

/** @ignore yes */
void end( object player, mixed args ) {
   object *flowers;

   player->remove_unbraid_cmd();
   player->remove_extra_look( TO );

   if( !objectp( args[0] ) )
       return;

   if( sizeof( flowers = INV( args[0] ) ) ) {
       tell_room( ENV( player ), query_multiple_short( flowers )+
           " $V$0=falls,fall$V$ to the ground from "+player->poss_short()+
           " hair.\n");
       flowers->move( ENV( player ) );
   }

   args[0]->dest_me();

} /* end() */

/** @ignore yes */
string extra_look( object player ) {
   object store, *flowers;
   int *enums;

   if( !sizeof( enums = (int *)player->effects_matching(CLASSIFICATION) ) ||
       !objectp( store = (object)player->arg_of( enums[ 0 ] )[0] ) ||
       !sizeof( flowers = INV( store ) ) )
       return "";

   return CAP( (string)player->HE ) +" has "+query_multiple_short( flowers )+
        " neatly braided into "+(string)player->HIS+" hair.\n";

} /* extra_look() */
