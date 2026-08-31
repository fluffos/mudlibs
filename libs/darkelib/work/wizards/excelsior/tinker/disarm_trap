inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(28);
    set_fast_dev_cost(87);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This can be used to disarm traps on chests, lock boxes, and the "
"like.  Note that you run a substantial risk of springing the trap "
"accidentally if you do not succeed.",
this_player());
}

void skill_func(object from, object at, string arg) {
  int roll;
  
  if(living(at)) {
    message("info", "Uh, I doubt that "+nominative(at)+
            " has a trap on "+objective(at)+".", from);
    remove();
    return;
  }
  if(!at->query_trap_level()) {
    message("info", "There appears to be no sign of a trap on "+
            lower_case((string)at->query_short())+".", from);
    message("info", (string)from->query_cap_name() +
            " inspects "+lower_case((string)at->query_short())+
            " for traps.", environment(from), ({ from }));
    remove();
    return;
  }
  roll = (int)at->query_trap_level();
  if((object)from->query("trap bonus") == at)
    roll -= 1+random(6);
  message("info", "%^CYAN%^You fiddle with the trap on "+
          lower_case((string)at->query_short()) + ".", from);
  message("info", (string)from->query_cap_name() +
          " tinkers with "+
          lower_case((string)at->query_short()) + ".",
          environment(from), ({ from }));
  call_out("do_disarm", 5, at, roll, from);
}

void do_disarm(object at, int lvl, object from) {
  if(random(100) < (props["skill level"] - (lvl-3)* 4)) {
    message("info", "%^CYAN%^%^BOLD%^You disarm the trap!",
            from);
    at->disarm_trap();
    remove();
    return;
  } else if(random(100) < 50) {
    message("info", "You are unable to do any good with the trap.",
            from);
    from->set("trap bonus", 0);
    remove();
    return;
  } else {
    message("info", "%^RED%^%^BOLD%^OOPS!!!  You spring the trap!",
            from);
    message("info", "%^RED%^"+(string)from->query_cap_name() +
            " accidently springs the trap!", environment(from),
            ({ from }));
    from->set("trap bonus", 0);
    at->spring_trap();
    remove();
    return;
  }
}
