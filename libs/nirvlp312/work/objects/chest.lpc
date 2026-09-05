inherit "inherit/conatiner";

void reset(status arg) {
  if (arg) return;
  set_name("chest");
  set_short("Chest");
  set_long("A chest that seems to be of a high value.\n" +
           "It has a small catch at the top of the chest.\n");
  set_value(200);
  set_weight(8);
  set_lock_id("catch");
  set_lock_desc("The catch is surrounded by an ornate design.\n");
  set_key_id("round key");
  set_locked(0);
  set_closed(1);
  set_trap_id("needle");
  set_trap_desc("The needle trap has been set off already.\n");
  set_trapped(0);
}

status search_ob(string str) {
  if (str == query_name()) {
    write("You spy a small needle trap!\n");
    return 1;
  }
  return 0;
}

