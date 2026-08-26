#include <effect.h>
#define SHADOW_PATH "/w/macchirton/to_be_checked/frog_repellent_shadow"
/*This creates a bad smell on the player so frogs will leave 
  Their environment after a brief spam-preventing time.*/
string query_classification() { return "repellent.frog"; }

string query_shadow_ob() { return SHADOW_PATH; }

int is_frog(object ob){
  return ob->id("frog");
}

int beginning( object player, int time ) {
  object ob;
  tell_object(player,"You notice a slight smell around yourself, "
         "but soon adjust.\n");
  tell_room(environment(player),player->the_short()+
          " smells a little funny, but not too bad.\n", ({player}));
  player->submit_ee( "end", time, EE_REMOVE );
  /* this gets rid of frogs that are already there.*/
  filter(all_inventory(environment(player)), (:is_frog:) )->
       do_command("'Ew!  What smells so bad?");
  filter(all_inventory(environment(player)), (:is_frog:) )->
       run_away();
  return time;
}

int merge_effect( object player, int time1, int time2 ) {
   int duration;
   duration = time2 + player->expected_tt();
   player->submit_ee( 0, duration, EE_REMOVE );
   return duration;
} /* merge_effect() */
 
/*give a comment for restart*/
int restart( object player, int time ) {
  object ob;
  tell_room(environment(player),player->the_short()+
          " smells a little funny, but not too bad.\n", ({player}));
  player->submit_ee( "end", time, EE_REMOVE );
  /*get rid of the frogs again.*/
  filter(all_inventory(environment(player)), (:is_frog:) )->
       do_command("'Ew!  What smells so bad?");
  filter(all_inventory(environment(player)), (:is_frog:) )->
       run_away();
  return time;
}

int end( object player, int time ) {
  tell_room(environment(player),"Your nose indicates a slight "
       "clearing of the air.\n");
}