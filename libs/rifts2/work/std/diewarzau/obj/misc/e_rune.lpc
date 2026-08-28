//    Poison Rune
#define CRITS ([ "1" : ({ "fire A" }), "2" : ({ "fire A","impact A" }), \
  "3" : ({ "fire B" }), "4" : ({ "fire B", "impact B" }), "5" : ({ "fire C" }), \
  "6" : ({ "fire C", "impact C" }) ])
  
inherit "/std/diewarzau/obj/misc/rune";

void create() {
  ::create();
  set_id(({ "exploding rune", "explosive rune", "rune" }));
  set_short("%^RESET%^%^RED%^%^BOLD%^An exploding rune%^RESET%^%^MAGENTA%^%^BOLD%^");
  set_long("This rune is inscribed on the floor in an ancient magical language.");
  set("function", (: call_other, this_object(), "do_explosion" :));
  return;
}

void do_explosion(object who) {
  int dmg, i;
  string targ_limb;

  dmg = 0;
  for(i=1; i<=10; i++) dmg += 1+random(10);
  dmg *= query_level();
   targ_limb = (string)who->return_target_limb();
  dmg -= who->query_current_protection(targ_limb, "fire");
  dmg -= who->query_current_protection(targ_limb, "impact");
  message("info", "%^CYAN%^%^BOLD%^You are hit by an exploding rune!", who);
if(dmg > 0) who->do_damage(targ_limb, dmg);
  do_critical(this_object(), who, CRITS[sprintf("%d", query_level())], 0);
  return;
}

