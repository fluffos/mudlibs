#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string e_message;
int light;

void create() {
	seteuid(getuid());
	return;
}

void set_light(int x) { light = x; }

int start_shadow(object ob, int dur, string mesg) {
    if(!objectp(ob)) return 0;
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    e_message = mesg;
    if(dur)
      call_out("expire_lite", dur, this_object());
    return 1;
}

mixed query_property(string what) {
  if(what != "light") return next_shadow()->query_property(what);
  return (int)next_shadow()->query_property("light") + light;
}

void expire_lite(object me) {
  if(me != this_object()) {
    next_shadow()->expire_lite(me);
    return;
  }
  message("info", e_message, who_shadowed);
  remove();
  return;
}


