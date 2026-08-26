#define EFFECT "/std/effects/object/identity_hold"

inherit COMMAND_BASE;

int cmd( object *obs )  {
   object thing;

   foreach(thing in obs) {
      thing->add_effect( EFFECT, ([ "keep" : 1 ]) );
   }
   write( "You will now attempt to keep "+
         (string)query_multiple_short(obs)+".\n" );

   return 1;
} /* cmd() */

mixed *query_patterns() {
   return ({ "<indirect:object:me>", (: cmd( $1 ) :) });
} /* query_patterns() */
