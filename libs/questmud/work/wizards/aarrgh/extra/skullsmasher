inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("hammer");
    set_short("The Mighty hammer called 'Skullsmasher'");
    set_long("Steel made hammer, forged obviously by dwarves. It has some\n"+
		"strange runes on it's handle: 'lighter' and 'heavier'\n");
    set_value(50000);
    set_weight(10);
    set_type(1);
    set_hit_func(1);
}

init() {
  ::init();
  add_action("paina", "heavier");
  add_action("kevene", "lighter");
}

paina() {
  set_weight(query_weight()+2);
  write("The hammer feels heavier.\n");
  return 1;
}

kevene() {
  set_weight(query_weight()-2);
  write("The hammer feels lighter.\n");
  return 1;
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(5) != 0) return;
  tell_room(environment(wielded_by), "The Skullsmasher glows brightly and gives "+
	"a real shock to "+wielded_by->query_attack()->query_name()+"!\n");
  wielded_by->query_attack()->hit_with_spell(random(100)+50,5);
  return 1;
}

