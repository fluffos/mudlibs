#include <std.h>
#include <lodos.h>
inherit MOUNT;

void create() {
    ::create();
    set_name("horse");
    set_id( ({ "monster" , "horse" }) );
    set_short("%^RESET%^%^ORANGE%^H%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^rs%^BOLD%^%^WHITE%^e%^RESET%^");
    set_level(15);
    set_long("%^RESET%^%^ORANGE%^The horse i%^BOLD%^%^WHITE%^s s%^RESET%^%^ORANGE%^tanding looki%^BOLD%^%^WHITE%^ng a%^RESET%^%^ORANGE%^t the other %^BOLD%^%^WHITE%^ani%^RESET%^%^ORANGE%^mals.%^RESET%^");
    set_race("horse");
    set_body_type("horse");
    if(random(2) == 0)
	set_gender("male");
    else
	set_gender("female");
    set("aggressive", 5);
    this_object()->add_money("gold", random(20));
}
