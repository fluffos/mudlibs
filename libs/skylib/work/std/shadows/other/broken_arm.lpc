#define CLASS "body.damage.arm.broken"
inherit "/std/effect_shadow";

int *set_hold(object ob, int pos) {
  string *args;                     /* args of effect */

  args = player->arg_of( player->effects_matching( CLASS )[0] );
  if( pos == 0 && member_array( "right", args ) != -1 )
    return ({ });
  if( pos == 1 && member_array( "left", args ) != -1 )
    return ({ });
  return player->set_hold( ob, pos );
}

int query_free_limbs() {
   string *args;
   int free_hands;

   args = player->arg_of( player->effects_matching( CLASS )[0] );
   free_hands = player->query_free_limbs() - sizeof( args );

   return ( free_hands < 0 ? 0 : free_hands );
} /* query_free_limbs() */

