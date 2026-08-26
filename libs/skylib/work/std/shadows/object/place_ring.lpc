/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: place_ring.c,v 1.2 1998/01/15 17:08:22 ranma Exp $
 * $Log: place_ring.c,v $
 * Revision 1.2  1998/01/15 17:08:22  ranma
 * a version that works properly with /d/am/broad_way/wedding_store
 *
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 * 
*/
#include "path.h"
#include <move_failures.h>

inherit "/std/effect_shadow";

void init() {
  add_command("place", "<direct:object> on <indirect:living>");
} /* init() */

void remove_me(object from,object dest){
  environment(from)->do_place_ring(from, dest);
  remove_this_effect();
 
} /* remove_me() */

int do_place(object *indir) {
  int i;
  if (!environment(this_player())->query_property("chapel")) {
    return 0;
  }
  if (environment(player) != this_player()) {
    return 0;
  }
  for (i=0;i<sizeof(indir);i++) {
    if (living(indir[i])) {
             
      if ( (int)player->move(indir[i]) == MOVE_OK) {
        indir[i]->wear_armour(player);
        this_player()->add_succeeded(indir[i]);
        call_out("remove_me",2,this_player(),indir[i]);
        return 1;
      }
      write("You can not place the ring on "+
             indir[i]->the_short()+".  Perhaps "+
             indir[i]->query_pronoun()+" is too burdened.\n");
      this_player()->add_succeeded_mess(player,"",({ }));
      return 1;
    } 
  } 
  return 0;
} /* do_place() */

