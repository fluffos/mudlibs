#include <effect.h>

string query_classification() { return "cure.poison.weak"; }

int beginning( object player, int time ) {
  player->submit_ee( 0, 2, EE_REMOVE );
} 
 
void end( object player, int time ) {
  int *effnum, succeed;
  effnum = (int *)this_player()->effects_matching("body.poison") +
   (int *)this_player()->effects_matching("poison.constitution");
  if(effnum == ({ }))
    return;
  if(!random(100))
   this_player()->delete_effect(effnum[0]);
  else{
   this_player()->adjust_hp(20);
   write("You feel a little better, but the poison still courses "
     "through your veins.\n");
  }
   
}

