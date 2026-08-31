#include <std.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("sword");
   set_short("%^BOLD%^%^BLACK%^Da%^WHITE%^rk %^RESET%^%^WHITE%^S%^BOLD%^wo%^BLACK%^rd%^RESET%^");
   set_long("This is the weapon of a true Anti-Paladin.  It was forged "
     "in the fires of hell and was stained with the blood of Satan "
     "himself.  The numbers '666' are hastily scratched all over the "
     "blade, while the hilt is made of an upside-down cross that was "
     "charred black with the devil's fire and wrapped tightly in "
     "demon-flesh.");
   set_weight(18);
   set_id(({"sword", "dark sword"}));
   set_value(0);
   set_type("blade");
   set_wc(15);
}

int query_auto_load() { return 1; }

void make_death(object tp) {
   if (tp != environment(this_object())) return;
   write("%^RED%^The evil overcomes your body!");
   tp->die();
   this_object()->remove();
}

int check_anti(string str)  {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_subclass() == "antipaladin") return 0;
   write("%^BOLD%^%^BLACK%^Pure evil embraces your soul.");
   call_out("make_death", 10, this_player());
   return 1;
}

void init() {
 ::init();
   add_action("check_anti", "wield");
}
