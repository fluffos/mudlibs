#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("death");
   set_short("");
   set_weight(0);
   set_value(0);
   set_long("Boo.");
   set_id(({ "deathinabox" }));
}

void death_me_up(object ob) {
   ob->die();
}

void trig_death() {
   call_out("death_me_up", 1, environment(this_object()));
}
