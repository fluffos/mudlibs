#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "blade", "sabre", "blood sabre" }));
   set_name("sabre");
   set_short("%^BOLD%^%^RED%^the%^RESET%^%^RED%^ blood%^BOLD%^ sabre%^RESET%^");
   set_long("This is a general's sabre. It is the type used during war "
      "in the front of battle. It's blade is a blood red. This is the "
      "legendary blood sabre.");
   set_weight(7);
    set_curr_value("gold", 30);
   set_wc(4);
   set_type("knife");
}

int query_auto_load() { if (this_player()->query_level() > 15) return 1; }
