//    Bag of holding.

inherit "/std/bag_logic";

int lock_container(string null) { return 0; }

int unlock_container(string null) { return 0; }

void create() {
  ::create();
  set_name("bag");
  set_id(({ "bag", "bag of holding" }));
  set_short("a bag of holding");
  set_long("This bag of holding may be used to store items, adding "
    "no weight to you.");
  set_weight(20);
  set_max_internal_encumbrance(800);
  set_value(140);
  return;
}

mixed query_property(string str) {
  if(str != "no save") return ::query_property(str);
  if(all_inventory(this_object()) &&
    sizeof(all_inventory(this_object()))) return 1;
  return 0;
}

