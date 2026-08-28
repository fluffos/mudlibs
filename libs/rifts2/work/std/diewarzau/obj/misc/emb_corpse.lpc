//   an embalmed corpse for summoning undead

inherit "/std/Object";

int level;

void create() {
  ::create();
  set_name("corpse");
  set_id(({ "corpse", "embalmed corpse" }));
  set_short("an embalmed corpse");
  set_long("This corpse has been prepared for use in summoning spells.");
  set_weight(40);
  set_value(2);
  return;
}

void set_level(int x) {
  if(x <= 0) return;
  level = x;
  set_short(sprintf("a level %d embalmed corpse", x));
  set_id(({ "corpse", "embalmed corpse",
      sprintf("level %d embalmed corpse", x),
      sprintf("level %d corpse", x) }));
  set_property("level", x);
  return;
}

int query_level() { return query_property("level"); }

