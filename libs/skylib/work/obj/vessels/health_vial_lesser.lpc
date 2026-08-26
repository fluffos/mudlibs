inherit BOTTLE_OBJ;

void setup() {
  set_name("vial");
  set_short("pale green vial");
  set_adjectives(({"pale", "green"}));
  set_long("A slender cylinder of palest green, the "
           "crystal comprising this vial captures "
           "light delicately within it's slightly "
           "translucent surface.  Attached to the "
           "open end on a delicate filigree chain is "
           "a small, perfectly fitting crystal stopper.\n");
  set_max_volume(120);
}

int query_value() {
  if(!clonep(TO)) return 3400;
  if(sizeof(INV(TO)) == 0) return 10;
  if(!sizeof(filter(INV(TO),
              (: $1->query_property("healing_potion") :)))) {
    return 10;
  }
  return 3400;
}
