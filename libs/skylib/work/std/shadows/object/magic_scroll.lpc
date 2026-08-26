/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: magic_scroll.c,v 1.8 1999/11/08 23:10:48 pinkfish Exp $
 * $Log: magic_scroll.c,v $
 * Revision 1.8  1999/11/08 23:10:48  pinkfish
 * Fix up the reaction to ue the correct environment.
 *
 * Revision 1.7  1999/11/04 01:56:46  pinkfish
 * Fix up the scroll code to work with the new inheritable.
 *
 * Revision 1.6  1999/11/04 01:52:01  pinkfish
 * Stuff!
 *
 * Revision 1.5  1999/10/28 02:09:21  ceres
 * Can't remember
 *
 * Revision 1.4  1999/04/05 03:02:24  ceres
 * Modified to use store_Ritual
 *
 * Revision 1.3  1999/03/19 17:43:40  ceres
 * Fixed power of exploding scrolls
 *
 * Revision 1.2  1999/03/05 09:43:05  ceres
 * Tweaked
 *
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 * 
*/
#include <tasks.h>

inherit "/std/effect_shadow";
inherit "/std/basic/scroll_base";

string long( string word, int dark ) {
    return player->long(word, dark) + "$C$" +
          player->the_short() +
          " appears to be a magic scroll containing the spell "+
          scroll_base::long(word, dark) + ".\n";
} /* long() */

void clear_spell( int award ) {
   ::clear_spell(award);
   remove_this_effect();
} /* clear_spell() */

varargs int move( mixed dest, string messin, string messout ) {
   // prevent pks killing non-pks by handing them a dangerous scroll
   if(query_verb() != "give" && query_verb() != "slip" &&
      query_verb() != "plant") {
      call_out("check_react", random(5), player);
   }
  
   return player->move(dest, messin, messout);
} /* move() */

void destroy_this_scroll() {
   player->dest_me();
} /* destroy_this_scroll() */
