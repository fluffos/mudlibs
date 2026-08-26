#define MAX_EXP 20000

void kill_reward(object killer) {
   int exp, killer_lvl, level;
  level = (int)this_object()->query_level();
  killer_lvl = (int)killer->query_level();
        exp = this_object()->query_exp();
  if (userp(TO)) exp = exp / 50 ;
       if (!exp) exp = 30;
        if (exp > MAX_EXP) exp = MAX_EXP;
        if (userp(killer))
    if (wizardp(killer))
  tell_object(killer,
   "[Wizard] You just received "+exp+" xp from that kill.\n");
        killer->add_exp(exp);
   killer->add_alignment(-1 * (int)this_object()->query_alignment()) ;
  exp = "/cmds/std/_consider"->get_value(this_object()) ;
  killer->new_kill(this_object(), exp) ;
        return;
}

void new_kill(object ob, int level) {
  if (level>(int)this_object()->query("best_val")) {
    this_object()->set("best_kill", ob->query("cap_name")) ;
    this_object()->set("best_val", level) ;
  }
  return ;
}
