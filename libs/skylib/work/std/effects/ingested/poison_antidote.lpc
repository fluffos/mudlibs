#include <effect.h>

string query_classification() { return "cure.poison.strong"; }

int beginning( object player, int time ) {
  player->submit_ee( 0, 2, EE_REMOVE );
} 

void end( object player, int time ) {
  int *effnum, i;
  if(time>65){
    effnum = (int *)player->effects_matching("body.poison") +
    (int *)player->effects_matching("poison.constitution");
    if(effnum == ({ }))
      return;
    foreach(i in effnum){
      player->delete_effect(i);
    }
    tell_object(player,"You feel cured!\n");
    return;
  }
  effnum = (int *)player->effects_matching("body.poison") +
   (int *)player->effects_matching("poison.constitution");
  if(effnum == ({ }))
    return;
  tell_object(player,"You feel a little better, but not well enough "
           "to believe the poison is gone.\n");
}


