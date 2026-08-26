
#define EFFECT "/std/effects/object/identity_hold"

inherit COMMAND_BASE;

int cmd( object *obs ) {
   object thing, *success;

   success = ({ });
   foreach (thing in obs)  {
      if (thing->query_keep())  {
         thing->add_effect(EFFECT, ([ "keep" : 0 ]));
         success += ({ thing });
      }
   }
   if (!sizeof(success))  {
      write("You are not attempting to keep anything.\n");
   }
   else  {
      write("You will no longer attempt to keep " +
            query_multiple_short(success) + ".\n");
   }
   return 1;
} /* cmd() */

mixed *query_patterns() {
   return ({ "<indirect:object:me>", (: cmd( $1 ) :) });
} /* query_patterns() */
