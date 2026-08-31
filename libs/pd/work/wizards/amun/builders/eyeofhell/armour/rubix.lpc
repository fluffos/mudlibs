#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                         
void create() {
    ::create();                                                         
    set_name("Rubix Cube Earrings");
    set("id", ({ "rubix earrings", "earrings", "cube earrings", "rubix cube earrings", "rubix cube", "rubix", "cube" }) );
    set("short", "%^BOLD%^%^RED%^R%^WHITE%^u%^RESET%^%^ORANGE%^b%^BOLD%^%^YELLOW%^i%^BLUE%^x %^RESET%^%^GREEN%^C%^BOLD%^%^RED%^u%^WHITE%^b%^RESET%^%^ORANGE%^e %^BOLD%^%^YELLOW%^E%^BLUE%^a%^RESET%^%^GREEN%^r%^BOLD%^%^RED%^r%^WHITE%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^YELLOW%^g%^BLUE%^s%^RESET%^");
    set("long", "%^BOLD%^%^RED%^These %^WHITE%^earrings %^RESET%^%^ORANGE%^were %^BOLD%^%^YELLOW%^made %^BLUE%^especially %^RESET%^%^GREEN%^for %^BOLD%^%^RED%^those %^WHITE%^easily %^RESET%^%^ORANGE%^amused. %^BOLD%^%^YELLOW%^They %^BLUE%^offer %^RESET%^%^GREEN%^not %^BOLD%^%^RED%^only %^WHITE%^protection, %^RESET%^%^ORANGE%^but %^BOLD%^%^YELLOW%^also %^BLUE%^hours %^RESET%^%^GREEN%^and %^BOLD%^%^RED%^hours %^WHITE%^of %^RESET%^%^ORANGE%^fun %^BOLD%^%^YELLOW%^for %^BLUE%^those %^RESET%^%^GREEN%^who %^BOLD%^%^RED%^wish %^WHITE%^to %^RESET%^%^ORANGE%^solve %^BOLD%^%^YELLOW%^rubix.%^RESET%^");
    set_type("earrings");
    set_ac(1);
    set_limbs( ({ "head"}) );
    set_weight(3);
    set_curr_value("gold", 150);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 1)
	return 1;
}
void init() {
    ::init();
    add_action("do_solve", "solve");
    add_action("do_fail", "fail");
}
int do_solve(string str) {
    if (!str || str != "rubix") return notify_fail("What is it you wish to play?\n");
    write("%^BOLD%^%^RED%^You %^WHITE%^have %^RESET%^%^ORANGE%^completed %^BOLD%^%^YELLOW%^the %^BLUE%^rubix! %^RESET%^%^GREEN%^You %^BOLD%^%^RED%^are %^WHITE%^the %^RESET%^%^ORANGE%^cube %^BOLD%^%^YELLOW%^master!%^RESET%^");
    if (random(50000) == 25000) do_solve();   
    else do_fail();
    return 1;
}
int do_fail(string str) {
    if (!str || str != "rubix") return notify_fail("What is it you wish to play?\n");
    write("%^BOLD%^%^RED%^You %^WHITE%^attempt %^RESET%^%^ORANGE%^to %^BOLD%^%^YELLOW%^align %^BLUE%^the %^RESET%^%^GREEN%^colors %^BOLD%^%^RED%^on %^WHITE%^the %^RESET%^%^ORANGE%^rubix %^BOLD%^%^YELLOW%^cube %^BLUE%^together, %^RESET%^%^GREEN%^instead %^BOLD%^%^RED%^you %^WHITE%^confuse %^RESET%^%^ORANGE%^yourself %^BOLD%^%^YELLOW%^more.%^RESET%^");
    return 1;
}
