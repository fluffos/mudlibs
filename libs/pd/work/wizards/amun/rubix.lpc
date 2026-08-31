#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                         
void create() {
    ::create();                                                         
    set_name("Rubix Cube Earrings");
    set("id", ({ "rubix earrings", "earrings", "cube earrings", "rubix cube earrings", "rubix cube", "rubix", "cube" }) );
    set("short", "%^BOLD%^%^RED%^R%^WHITE%^u%^RESET%^%^ORANGE%^b%^BOLD%^%^YELLOW%^i%^BLUE%^x %^RESET%^%^GREEN%^C%^BOLD%^%^RED%^u%^WHITE%^b%^RESET%^%^ORANGE%^e %^BOLD%^%^YELLOW%^E%^BLUE%^a%^RESET%^%^GREEN%^r%^BOLD%^%^RED%^r%^WHITE%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^YELLOW%^g%^BLUE%^s%^RESET%^");
    set("long", "%^BOLD%^%^RED%^These %^WHITE%^earrings %^RESET%^%^ORANGE%^were %^BOLD%^%^YELLOW%^made %^BLUE%^especially %^RESET%^%^GREEN%^for %^BOLD%^%^RED%^those %^WHITE%^easily %^RESET%^%^ORANGE%^amused. %^BOLD%^%^YELLOW%^They %^BLUE%^offer %^RESET%^%^GREEN%^not %^BOLD%^%^RED%^only %^WHITE%^protection, %^RESET%^%^ORANGE%^but %^BOLD%^%^YELLOW%^also %^BLUE%^hours %^RESET%^%^GREEN%^and %^BOLD%^%^RED%^hours %^WHITE%^of %^RESET%^%^ORANGE%^fun %^BOLD%^%^YELLOW%^for %^BLUE%^those %^RESET%^%^GREEN%^who %^BOLD%^%^RED%^wish %^WHITE%^to %^RESET%^%^ORANGE%^play %^BOLD%^%^YELLOW%^rubix.%^RESET%^");
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
    add_action("play_rubix", "play");
}
int play_rubix(int max, object tp ) {
    int x = random(100) +1;
    string str;
    object obj;
    if (!str || str != "rubix") return notify_fail("What is it you wish to play?\n");
    if( x >= 100 ) {
	write("%^BOLD%^%^RED%^You %^WHITE%^have %^RESET%^%^ORANGE%^completed %^BOLD%^%^YELLOW%^the %^BLUE%^rubix! %^RESET%^%^GREEN%^You %^BOLD%^%^RED%^are %^WHITE%^the %^RESET%^%^ORANGE%^cube %^BOLD%^%^YELLOW%^master!%^RESET%^", tp);
	return 0;
    }
    else if( x >= 95 ) {
	write("%^BOLD%^%^RED%^You %^WHITE%^attempt %^RESET%^%^ORANGE%^to %^BOLD%^%^YELLOW%^align %^BLUE%^the %^RESET%^%^GREEN%^colors %^BOLD%^%^RED%^on %^WHITE%^the %^RESET%^%^ORANGE%^rubix %^BOLD%^%^YELLOW%^cube %^BLUE%^together, %^RESET%^%^GREEN%^instead %^BOLD%^%^RED%^you %^WHITE%^confuse %^RESET%^%^ORANGE%^yourself %^BOLD%^%^YELLOW%^more.%^RESET%^", tp);
    }
    return 0;
}
