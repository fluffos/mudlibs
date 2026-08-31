#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Crystalline Blade");
    set("id", ({ "sword", "blade", "crystalline blade" }) );
    set("short", "%^BOLD%^%^WHITE%^Cr%^CYAN%^y%^WHITE%^st%^CYAN%^a%^WHITE%^ll%^CYAN%^i%^WHITE%^n%^CYAN%^e %^WHITE%^Bl%^CYAN%^a%^WHITE%^d%^CYAN%^e%^RESET%^");
    set("long", "%^BOLD%^%^CYAN%^This blade was made by the Father of Heaven for his gods and goddesses.%^RESET%^");
    set_weight(40);
    set_curr_value("gold", 200);
    set_wc(14);
    set_type("blade");
    set("skill level", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 55)
	return 1;
}
int can_wield() {
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("sword") >= 118)
    {
	write("%^BOLD%^%^CYAN%^The blade shimmers as you wield it.");
    }
    return 1;
}

int weapon_hit() {
    int result;
    object atk;
    int num;
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("blade") < 118) {
	write("The blade grows dull and heats up.");
	say((string)this_player()->query_cap_name() + " screams and drops the sword clutching their hot hand!");
	this_player()->force_me("drop crystalline blade");
    }
}
