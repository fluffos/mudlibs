#include <effect.h>

string query_classification() { return "misc.breath-clean"; }

int beginning( object player, int time ) {
  player->submit_ee( 0, 2, EE_REMOVE );
} 
 
void end( object player, int time ) {
  int *effnum, succeed;
  effnum = (int *)this_player()->effects_matching("mouth.smell.garlic");
  if(effnum == ({ }))
    return;
  this_player()->delete_effect(effnum[0]);
}

