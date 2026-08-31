weak(str) {
  object obj,weaker;
  int cost,percentage,duration;
 
  if(!str) {
    write("Whom do want to suggest anything ?\n");
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
  if(!present("weakerobj",obj)) {
    if(TP->query_spell_points()<cost) {
      write("You are not strong enough.\n");
    return 1;
    }
    duration=TP->query_chr()*2-obj->query_chr();
    percentage=TPL/30*25;
    weaker=clone_object("players/kelly/guild/weaker");
    move_object(weaker,obj);
    weaker->start(duration,percentage);
    write(obj->NAME+" looks less strong than before.\n");
    spell_cost(cost);
  }
  else {
    write(obj->NAME+" doesn't check anything you do.\n");
    spell_cost(cost/3);
  }
 
  return 1;
}
