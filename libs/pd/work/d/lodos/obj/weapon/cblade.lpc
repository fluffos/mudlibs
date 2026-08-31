#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "blade", "copper blade" }));
   set_name("blade");
   set_short("a thin copper blade");
   set_long("A very thin blade that has been made out of copper. "
     "Although it is very thin, it is increadibly durable and made "
     "for speed. The major down side of this weapon is the only handle "
     "it possesses is a rectangular copper handle, which is very "
     "uncomfortable.");
   set_weight(6);
    set_curr_value("gold", 29);
   set_wc(5);
   set_type("blade");
}

int query_auto_load() { if (this_player()->query_skill("blade") >= 20) return 1; }
