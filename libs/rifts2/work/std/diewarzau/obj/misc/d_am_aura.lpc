#include <move.h>
#include <party.h>
inherit "/std/Object";

object caster;

int not_party(object who, object caster) {
  string party;

  if(!caster || !living(who)) return 0;
  if(who == caster) return 0;
  if(who->is_pet() && (string)who->query_owner() ==
     (string)caster->query_name()) return 0;
  party = PARTY_OB->party_member(caster);
  if(!party || !stringp(party)) return 1;
  if(!who->is_player()) return 1;
  if(party == (string)PARTY_OB->party_member(who)) return 0;
  return 1;
}

int filter_casting(object item) {
  if(item == caster) return 0;
  if(living(item) && item->query_casting() &&
      not_party(item, caster)) return 1;
  return 0;
}

void set_caster(object ob) { caster = ob; }

int move(mixed dest) {
  if(objectp(dest) && living(dest)) return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

void create() {
  set_name("aura");
  set_id(({ "field", "anti-magic aura", "anti magic field", "anti-magic field" }));
  set_short("An anti magic field surrounding this room");
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
