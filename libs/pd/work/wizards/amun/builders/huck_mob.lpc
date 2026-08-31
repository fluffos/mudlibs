#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Rogue");
    set_id( ({ "rogue", "monster" }) );
    set_short("Rogue");
    set("aggressive", 0);
    set_level(7);
    set_long("The rogue has scars all over his body. He looks like he has been through many fights.");
    set_money("gold", 1);
    set_gender("male");
    set("race", "human");
    set_body_type("human");
    set_alignment(0);
}
void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%shelp%s", a, b) == 2) {
	this_object()->force_me("say %^BOLD%^%^WHITE%^If you wish to %^BLUE%^<%^RED%^board boat%^BLUE%^> %^WHITE%^you may do that here. If your boat isn't docked at this pier, you may need to %^BLUE%^<%^RED%^recall boat%^BLUE%^>%^WHITE%^.%^RESET%^");
	return;
    }
}
