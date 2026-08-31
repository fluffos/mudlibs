inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  this_object()->set_name("spider");
  this_object()->set_short("A tiny red spider");
  this_object()->set_long("A tiny red spider crawls over your shoes, eeeks |||\n");
  this_object()->set_race("spider");
  this_object()->set_level(3);
  this_object()->set_al(-100);
  this_object()->set_aggressive(1);
  this_object()->set_whimpy();
  this_object()->set_move_at_reset();
  return 1;
}

query_moncreator() { return "herp"; }

query_monmaker() { return 1; }
