inherit "/std/Object";

int power;

void set_up(int x) { power = x; }

void create() {
  ::create();
  set_name("figurine");
  set_id(({ "figurine", "familiar figurine" }));
  set_short("A figurine of a familiar");
  set_long(
  "This ornate figurine resembles a mythical animal.");
  set_weight(40);
  set_value(57483);
  return;
}

void init() {
  ::init();
  add_action("stabilize", "stabilize");
  return;
}

int stabilize(string str) {
  object ob;

  ob = present(lower_case(str), environment(this_player()));
  if(!ob)
    return notify_fail("There is no '"+str+"' here.\n");
  if(!ob->id("familiar")) {
    write("This only works on familiars.");
    return 1;
  }
  ob->stabilize();
  write("The familiar is stabilized, and may have gained new commands.  "+
        "Say help to it.");
  remove();
  return 1;
}

