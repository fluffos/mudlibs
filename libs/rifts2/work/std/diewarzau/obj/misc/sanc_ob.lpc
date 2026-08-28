#include <move.h>

inherit "/std/Object";

string caster;
object shadow_ob;

void create() {
  ::create();
  set_short("A sanctuary spell surrounding this room");
  set_long("This magical aura prohibits entry into this room.  "
"The caster may get rid of it by typing 'remove sanctuary'.");
  set_id(({ "sanctuary", "spell", "aura", "sanctuary spell" }));
  set_name("sanctuary");
  return;
}

void set_shadow(object ob) { shadow_ob = ob; }

void set_dur(int dur) { call_out("remove", dur); }

void set_caster(string who) { caster = who; }

void init() {
 ::init();
 add_action("remove_me", "remove");
 return;
}

int remove_me(string str) {
  if(caster != (string)this_player()->query_name()) return 0;
  if(lower_case(str) != "sanctuary") return notify_fail("Remove what?");
  write("You remove the sanctuary from this room.");
  if(objectp(shadow_ob)) shadow_ob->expire_sanc(shadow_ob);
  remove();
}

int move(object dest) {
  if(living(dest)) return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

