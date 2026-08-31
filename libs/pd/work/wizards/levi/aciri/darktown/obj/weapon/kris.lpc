#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("kris");
   set_short("a wavy bladed kris");
   set_long("The kris is a wavy bladed knife. It's blade will tear "
     "any muscle and punture the skin, tearing a huge wound.");
   set_weight(7);
   set_id(({ "kris", "knife" }));
   set_wc(6);
   set_type("knife");
   set_value(250);
}

int query_auto_load() {
   if (this_player()->query_skill("knife") >= 45) return 0;
}
