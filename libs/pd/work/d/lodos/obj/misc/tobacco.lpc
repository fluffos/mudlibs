#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("tobacco");
   set_short("tobacco");
   set_long("A dull green crispy leaf. It can be packed into a pipe and "
     "smoked.");
    set_curr_value("copper", 52);
   set_value(0);
}

void smoke_me(object o) {
   if (!o) return;
   message("smoke", "You cough noisily.", o);
   message("smoking", o->query_cap_name()+" coughs noisily.", environment(o), o);
   o->add_mp(random(15));
}

int can_smoke() { return 1; }
