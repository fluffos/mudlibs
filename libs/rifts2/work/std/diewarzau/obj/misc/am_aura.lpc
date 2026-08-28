#include <move.h>

inherit "/std/Object";

int filter_casting(object item) {
  if(living(item) && item->query_casting()) return 1;
  return 0;
}

int move(mixed dest) {
  if(objectp(dest) && living(dest)) return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

void create() {
  set_name("aura");
  set_id(({ "aura", "anti-magic aura", "anti magic aura" }));
  set_short("An anti magic aura surrounding this room");
  set_long(
"This aura can prevent the casting of spells.");
  set_property("level", 1);
  return;
}

void set_level(int lev) {
  set_property("level", lev);
  return;
}

void set_duration(int dur) {
  call_out("expire_aura", dur);
  set_heart_beat(1);
  return;
}

void expire_aura() {
  message("info", "%^CYAN%^An anti-magic aura disappears.",
          environment());
  remove();
  return;
}

int casting_filter(object who) {
  if(!living(who)) return 0;
  if(who->query_casting()) return 1;
  return 0;
}

void heart_beat() {
  object spell, *inv;
  int i, spell_lev;
  
  inv = filter_array(all_inventory(environment()), "casting_filter",
                     this_object());
  i = sizeof(inv);
  while(i--) {
    if(!objectp(spell = (object)inv[i]->query_casting())) continue;
    spell_lev = (int)spell->query_property("spell level");
    if(((random(7)+1) * (int)query_property("level")) >= spell_lev &&
        random(10) < (int)query_property("level")) {
      message("info", "%^CYAN%^Your spell is interrupted by the "
              "anti-magic aura about this room!", inv[i]);
      message("info", "%^CYAN%^"+(string)inv[i]->query_cap_name()+
              "'s spell is dampened by the anti-magic aura.",
              environment(inv[i]), ({ inv[i] }));
      spell->remove();
      inv[i]->set_casting(0);
    }
  }
  return;
}
