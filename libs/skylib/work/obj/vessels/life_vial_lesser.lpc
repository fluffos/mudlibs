inherit BOTTLE_OBJ;

void setup() {
  set_name("vial");
  set_short("green vial");
  set_adjectives(({"green"}));
  set_long("This slim green vial seems to be made of a green crystal "
           "shard.  It has a stopper chained to one end.\n");
  set_max_volume(150);
  add_property("stealing_is_bad", 1);
}

int query_value() {
  if(!clonep(TO)) {
    return 90000;
  }
  if(sizeof(INV(TO)) != 1) {
    remove_property("stealing_is_bad");
    return 10;
  }
  if(!INV(TO)[0]->query_property("life_potion")) {
    remove_property("stealing_is_bad");
    return 10;
  }
  add_property("stealing_is_bad", 1);
  return 90000;
}
