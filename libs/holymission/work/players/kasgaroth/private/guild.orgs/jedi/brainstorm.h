brainstorm(str) {
  object obj;
  int cost;
  if(!str) {
    write("Whom do you want to suggest anything?\n");
    return 1;
  }
  obj=present(str,ENV(TP));
  cost=10+TPL*3-TP->query_wis();
  if(!obj) {
    write("That is not here.\n");
    return 1;
  }
  if(!living(obj)) {
    write("That is not a living thing.\n");
    return 1;
  }
  if(TP->query_spell_points()<cost) {
    write("You are not strong enough.\n");
    return 1;
  }
  if (100*obj->query_hp()/obj->query_maxhp()<10) {
    if(random(100)<TP->query_chr()) {
      write(obj->NAME+" suddenly looks very bad."+obj->PRO+
       " stumbles and falls to the ground.\n");
      obj->hit_player(1000);
    } 
    else
      write("You fail to suggest anything.\n");
  }
  else
    write("You concentrate hard, but you fail to affect "+obj->NAME+"\n");
  spell_cost(cost);
  return 1;
}
