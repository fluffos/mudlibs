#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("sword");
   set_short("a rusted black steel sword");
   set_long("The quality of the black steel looks extraordinary, under the "
     "rust, that is. For such a strong blade, it has received horrible care, "
     "and the blade is even chipped at the base. The ebony handle has been "
     "covered with an old leather wrapping.");
   set_weight(30);
   set_id(({ "sword", "rusted black steel sword", "rusted sword" }));
   set_type("blade");
   set_value(555);
}

int query_wc() {
   if (!environment(this_object())->is_living()) return 105;
   if (!environment(this_object())->query_current_attacker()) return 105;
   return -1;
}

int query_auto_load() { return 3; }

