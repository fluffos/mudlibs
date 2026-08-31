inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  this_object()->set_name("pig");
  this_object()->set_short("A dirty pig");
  this_object()->set_long("A dirty pig snuffles around for truffles.\n");
  this_object()->set_level(4);
  this_object()->set_al(100);
  this_object()->set_aggressive(0);
  return 1;
}

query_moncreator() { return "herp"; }

query_monmaker() { return 1; }
