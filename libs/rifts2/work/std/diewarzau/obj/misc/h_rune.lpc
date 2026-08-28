inherit "/std/diewarzau/obj/misc/rune";

nosave int hb_on;
nosave int heal_status;

int living_filter(object who) { return living(who); }

void create() {
  ::create();
  set_property("non-combat", 1);
  heal_status = 6;
  set_id(({ "enchanter rune", "rune", "heal rune", "healing rune" }));
  set_short("%^RESET%^%^CYAN%^%^BOLD%^a healing rune%^RESET%^%^MAGENTA%^%^BOLD%^");
  set_long("This rune is inscribed on the floor in an ancient magical language.");
  set("function", (: call_other, this_object(), "do_heal" :));
 hb_on = 1;
set_heart_beat(1);
  return;
}

void do_heal(object who, int flag) {
    hb_on = 1;
    set_heart_beat(1);
  return;
}

void heart_beat() {
  object *inv;
  int i;

  heal_status--;
  if(heal_status > 0)
    return;
    heal_status = 6;
  inv = filter_array(all_inventory(environment()), "living_filter",
      this_object());
  if(!inv || !sizeof(inv)) {
    hb_on = 0;
      set_heart_beat(1);
    return;
  }
  i = sizeof(inv);
  while(i--) {
    message("info", "%^CYAN%^%^BOLD%^The rune heals you.", inv[i]);
    inv[i]->do_healing((int)inv[i]->calculate_healing());
  }
  return;
}
