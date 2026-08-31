#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("locket");
   set_short("%^BOLD%^%^BLACK%^a s%^WHITE%^ilv%^RESET%^e%^BOLD%^r "
	"locket%^RESET%^");
   set_long("A classy silver locket. It has a chain around it, so it "
	"can be worn around the neck, though it couldn't possibly "
	"give any protection. The locket opens in the middle.");
    set_curr_value("silver", 5);
   set_weight(3);
   set_id(({ "locket", "silver locket" }));
   set_limbs(({ "head", "torso" }));
   set_type("necklace");
   set_ac(0);
}

int query_auto_load() { return 1; }

int open(string str) {
   if(str != "locket" && str != "silver locket") return 0;
   write("You try to open the locket, but there is some trick to doing "
	"it that you can't figure out. Only the owner of this thing "
	"could possibly open the locket!");
   return 1;
}

void init() {
 ::init();
   add_action("open", "open");
}
