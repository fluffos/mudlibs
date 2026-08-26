#include <move_failures.h>

#define BASE  50
#define SCALE 3

inherit "/std/effect_shadow";

varargs int query_skill_bonus( string word, int true ) {
   int bonus;

   bonus = (int)player->query_skill_bonus( word, true );

   if( word != "general.perception" || true )
       return bonus;

   return BASE + bonus + bonus / SCALE;

} /* query_skill_bonus() */

varargs int move( mixed dest, string msgin, string msgout ) {
   int flag;

   flag = (int)player->move( dest, msgin, msgout );

   if( flag == MOVE_OK )
       remove_this_effect();

   return flag;

} /* move() */
