inherit "/std/object";

void setup() {
  set_name("potion");
  set_short("healing potion");
  add_adjective("healing");
  set_long("A potion containing a clear liquid.\n");
  set_weight(2);
  set_value(2000);
  set_main_plural("healing potions");
  add_plural("potions");
}

void init() {
  add_action("do_drink", "drink");
  ::init();
}

int do_drink(string str) 
{
  notify_fail("Drink what ?\n");
  if (!str)
    return 0;
  write("You drink a healin potion.\n");
  say(this_player()->query_cap_name()+" drinks a potion.\n");
  return 1;
}
