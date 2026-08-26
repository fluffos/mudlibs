inherit "/std/effect_shadow";
/*is it a froggie?*/
int is_frog(object ob){
  return ob->id("frog");
}

/*check for those evil frogs*/
void event_enter(object who, string mess, object from){
  call_out("say_summfink", 1);
  call_out("run_him_outta_town", 3);
  player->event_enter(who,mess,from);
}

/* have the frog say somethng- but only if they're
   still in the environment of player*/
void say_summfink(){
 filter(all_inventory(environment(player)), (:is_frog:) )->
     do_command("'Hey, what smells so bad?",1);
}
/*still here? then lets run you out of town!*/
void run_him_outta_town(){
  filter(all_inventory(environment(player)), (:is_frog:) )->
     do_command("'I'm out of here!");
  filter(all_inventory(environment(player)), (:is_frog:) )->
     run_away();
}