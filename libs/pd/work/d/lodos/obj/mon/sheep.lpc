#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("sheep");
    set_id( ({ "monster" , "sheep" }) );
    set_short("%^BOLD%^%^WHITE%^Sheep%^RESET%^");
    set_level(15);
    set_long("%^BOLD%^%^WHITE%^The white and fluffy sheep is grazing on some %^GREEN%^grass%^WHITE%^.%^RESET%^");
    set_race("sheep");
    set_body_type("sheep");
    if(random(2) == 0)
	set_gender("male");
    else
	set_gender("female");
    set("aggressive", 5);
    this_object()->add_money("gold", random(20));
}
