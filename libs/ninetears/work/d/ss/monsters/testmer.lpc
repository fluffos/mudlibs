#define HOSPITAL "/d/ss/monsters/hospital"

inherit "/obj/monster";

void setup()
  {
  set_name("bing");
  set_short("bong");
  set_long("a womble\n");
  add_triggered_action("boo", "event_death", this_object(), "death");
} /* setup */

void death() {
  call_out("do_pick_up", 0, previous_object());
}

void do_pick_up(object ob) {
  ob->do_command("'Thank you for the nice booty!\n");
  ob->do_command("get all from corpses");
  ob->run_away();
}
