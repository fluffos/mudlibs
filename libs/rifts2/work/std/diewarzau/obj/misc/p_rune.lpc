//    Poison Rune

inherit "/std/diewarzau/obj/misc/rune";

void create() {
  ::create();
  set_id(({ "poison rune", "poisonous rune", "rune" }));
  set_short("%^RESET%^%^GREEN%^A poison rune%^RESET%^%^MAGENTA%^%^BOLD%^");
  set_long("This rune is inscribed on the floor in an ancient magical language.");
  set("function", (: call_other, this_object(), "do_poison" :));
  return;
}

void do_poison(object who) {
  int pois, i;

  pois = 0;
  for(i = 1; i <= 7; i++) pois += random(6)+1;
  pois *= query_level();
  message("info", "%^GREEN%^You are POISONED by a rune!",
    who);
  who->add_poisoning(pois);
  return;
}

