//    Poison Rune
inherit "/std/diewarzau/obj/misc/rune";

void create() {
  ::create();
  set_id(({ "rune", "transport rune" }));
  set_property("non-combat", 1);
  set_short("%^RESET%^%^YELLOW%^%^BOLD%^A transport rune%^RESET%^%^MAGENTA%^%^BOLD%^");
  set_long("This rune is inscribed on the floor in an ancient magical language.");
  set("function", (: call_other, this_object(), "do_gate" :));
  return;
}

void do_gate(object who) {
  string room;
  
  if(!(room=(string)query_property("room"))) return;
  if(random(100) <= (int)who->query_level() * 3 / query_level()) {
    message("info", "%^CYAN%^You resist the effects of a transport rune.",
      who);
    return;
  }
  message("info", "%^GREEN%^%^BOLD%^You are magically transported somewhere.",
    who);
  who->move_player(room, 0);
  return;
}

