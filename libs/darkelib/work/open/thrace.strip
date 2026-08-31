inherit "/std/skills/skill";
 
void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(20);
    set_fast_dev_cost(63);
    set_property("target type", "living");
    set_property("must be present",1);
}
 
void info() {
message("help",
"This skill may be used against enemies in combat. "+
" You may only use this skill once every two combat rounds."
" It lets the user smash his or her opponent with a surprise"
"backhand smash with their hand or the hilt of their weapon.",
this_player());
}
 
 
void skill_func(object from, object at, string arg) {
  int flag, i, diff;
  string *limbs;
 
  if((time() - (int)from->query_last_use("backhand smash")) < 4)
    {
    message("info", "You are too tired to use this skill yet."
        , from);
    return;
  }
  if(environment(from) &&
    environment(from)->query_property("no attack")) {
    message("info", "Mystic forces prevent your action.", from);
    remove();
    return ;
  }
  if(at->shadow_form() || at->query_ghost()) {
    message("info", "You may not backhand smash a target which is immaterial.",
            from);
    remove();
 
    return;
  }
  flag = 0;
  from->set_last_use("backhand smash");
  at->kill_ob(from, 0);
  diff = props["skill level"] - at->query_skill("dodge");
  if ((random(100) + diff) < 35) {
        message("my_combat", "You attempt to smash your opponent but "+
            (string)at->query_cap_name()+ " moves quickly out of the way.",
            from);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to hit you with a backhand, but you move quickly out of the way.",
at);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to hit "+
            (string)at->query_cap_name()+", with a backhand smash but " +
            (string)at->query_cap_name()+" dodges.",
            all_inventory(environment(from)),
            ({ from, at }) );
    remove();
    return;
 
  }
  props["skill level"] -= (random(100) +
                     at->query_current_protection("head","impact")/4 );
  if((int)props["skill level"] < -10) {
    message("my_combat", "You attempt to hit "+
            (string)at->query_cap_name()+ " with a backhand smash, but miss miserably.",
            from);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to hit you with a backhand smash.", at);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to hit "+(string)at->query_cap_name()+ ", with a backhand smash, but misses.",
            all_inventory(environment(from)),
            ({ from, at }) );
    remove();
    return;
  }
  message("my_combat", "You hit "+
          (string)at->query_cap_name()+ " with a backhand smash in the face and "+
          (string)at->query_cap_name()+ " spits out blood.",
          from);
 
  message("other_combat", (string)from->query_cap_name() +
          " backhand smashes you in the face and you double over in pain.", at);
  message("other_combat", (string)from->query_cap_name() +
          " backhand smashes "+
          (string)at->query_cap_name()+ " in the face and "+
          (string)at->query_cap_name()+ " spits out blood.",
          all_inventory(environment(from)),
          ({ from, at }) );
  switch(props["skill level"]) {
  case -10..25:
    at->do_damage((string)at->return_target_limb(), random(8)+1);
    break;
  case 26..40:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "impact A");
    break;
  case 41..53:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "impact B");
    break; 
  case 54..65:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "impact C");
    break;
  case 66..82:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "impact D");
    break;
  case 83..10000:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "impact E");
    break;
  }
  remove();
  return;
}
 
