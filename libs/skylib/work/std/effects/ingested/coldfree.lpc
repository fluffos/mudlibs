#include <effect.h>

string query_classification() { return "misc.breath-clean"; }

int beginning( object player, int time ) {
  player->submit_ee( 0, 2, EE_REMOVE );
} 
 
void end( object player, int time ) {
  int *effnum, succeed;
  effnum = (int *)this_player()->effects_matching("disease.infection.respiratory.cold");
  if(effnum == ({ }))
    return;
  if(!random(4))
   this_player()->delete_effect(effnum[0]);
  else
   write("You feel a little better, but not much.\n");
}

