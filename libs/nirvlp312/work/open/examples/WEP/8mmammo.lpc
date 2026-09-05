inherit "obj/treasure";

int bullets;


void reset(int arg) {
  set_id("clip");
  set_alias("8mm ammo");
  set_short("8mm clip");
  set_long(
"An 8mm ammo clip.\n"
  );
  set_weight(1);
  set_value(50);
  bullets=12;
}
int reload() {
  destruct(this_object());
  this_player()->recalc_carry();
  return bullets;
}
