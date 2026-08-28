/* Basic ressi. update by Celtron to match major ress. */

resolve(int bonus, string target) {
  status minor;
  minor = 1;
  return "/guilds/spells/channel/_chl_eth_mar"->resolve(bonus,target, minor);
}

/*
resolve(bonus, target, god) {
   object ob;
   int effect, exp, skills;

   if (!target) { write("Resurrect whom?\n"); return; }
   ob = find_player(lower_case(target));
   if (!ob) { write("No such a player.\n"); return 1; }
   if (!ob->query_dead()) {
	write(capitalize(target) + " is not dead.\n");
	return 1;
   }

   write("You resurrect " + capitalize(target) + ".\n");
   tell_object(ob, this_player()->query_name()+" resurrected you.\n");

   skills = this_player()->query_skills("cast soul")/10;
   skills += this_player()->query_skills("cast minor")/10;

   effect = 20 + bonus / 30 + skills;
   if (effect < 20) {
        effect = 20;
   }
   if (effect > 50) {
	effect = 50;
   }
   exp = ob->query_train_exp() / 300 * effect;
   if (exp > 3000000) {
	exp = 3000000;
   }
   log_file("RESS_LOG", this_player()->query_name()+" got "+
	exp+" exp from ressing "+capitalize(target)+".\n");
   ob->remove_ghost(effect, environment(this_player()));
   this_player()->add_party_exp(exp);
}

*/
