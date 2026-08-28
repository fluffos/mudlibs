inherit "/std/Object";

int picks_left;

void create() {
  ::create();
  set_name("daggers");
  set_id( ({ "daggers", "dagger belt", "belt" }) );
  set_short("A belt of 5 daggers");
  picks_left = 5;
  set_long(
"This is a cheap leather belt used for holding up to 5 daggers.  You can "
"'take' one in order to wield or throw it.");
  set_weight(50);
  set_float_value(2.15);
  return;
}

void init() {
  ::init();
  add_action("get_pick", "take");
  add_action("get_pick", "get");
  return;
}

int get_pick(string str) {
  string tmp1, tmp2;
  object ob;

  if(sscanf(str, "%s from %s", tmp1, tmp2) != 2) return 0;
  if(present(tmp2, this_player()) != this_object()) return 0;
  seteuid(getuid());
  ob = new("/d/damned/virtual/dagger_3.weapon");
  if(!ob->id(tmp1)) {
    ob->remove();
    write("There is no '"+str+"' on the belt.");
    return 1;
  }
  picks_left--;
  write("Ok.");
  ob->move(this_player());
  if(picks_left > 1)
    set_short(sprintf("A belt of %d daggers", picks_left));
  else if(picks_left == 1)
    set_short("A belt with 1 dagger on it");
  else {
    write("Having taken the last dagger, you discard the belt.");
    remove();
  }
  set_float_value(query_float_value() - 0.35);
  return 1;
}
