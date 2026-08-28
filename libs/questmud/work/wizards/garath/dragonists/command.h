int cmd_newowner(string str) {
  if(this_player()->query_real_name() != owner) return 0;
  str = lower_case(str);
  if(!find_player(str)) {
    write("No such player.\n");
    return 1;
  }
  owner = str;
  return 1;
}

int cmd_dkill(string str) {
  object ob;
  if(this_player()->query_real_name() != owner) return 0;
  if(!str) {
    write("Kill what ?\n");
    return 1;
  }
  if(environment()->query_property("no_kill")) {
    write("A mysterious force stops you.\n");
    return 1;
  }
  ob = present(lower_case(str),environment(this_player()));
  if(!ob) {
    write("No "+str+" here!\n");
    return 1;
  }
  if(!living(ob)) {
    write(capitalize(str)+" is not a living thing!\n");
    return 1;
  }
  if(ob == this_object()) {
    write("Dragon can't comply with that.\n");
    return 1;
  }
  say("Dragon attacks "+ob->query_name()+"!\n");
  attack_object(ob);
  return 1;
}

int cmd_dscore() {
  if(this_player()->query_real_name() != owner) return 0;
  write("Level: "+dlvl+" Owner: "+capitalize(owner)+" Souls: "+dsoul+"\n");
  write("HP:("+hit_point+"/"+max_hp+")\n");
  return 1;
}

int cmd_ddrain(string str) {
  object ob;
  if(!str) {
    write("Drain what?\n");
    return 1;
  }
  str = lower_case(str);
  if(!ob = present(str,environment(this_object()))) {
    write("Drain what?\n");
    return 1;
  }
  if(!ob->query_corpse()) {
    write("Dragon can't drain a soul from that!\n");
    return 1;
  }
  if(ob->query_level() < dlvl*2) {

    write("The soul is too weak for your dragon!\n");
    return 1;
  }
  say("Dragon drains the soul from the corpse, and the corpse shatters into pieces.\n");
  dsoul += ob->query_level()/10;
  dsoul += this_player()->query_skill("knowledge of souls")/5;
  destruct(ob);
  return 1;
}
