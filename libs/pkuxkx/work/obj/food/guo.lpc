#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
string *names=({HIM+"浆果"+NOR,YEL+"坚果"+NOR,YEL+"榛子"+NOR,HIW+"松子"+NOR});
string *ids=({"jiang guo","jian guo","zhen zi","song zi"});
void create()
{
    int i=random(sizeof(names));
	set_name(names[i], ({ ids[i], "guo" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枚"+this_object()->query("name")+"。\n");
		set("unit", "枚");
        set("value", 0);
		set("food_remaining", 3+random(2));
		set("food_supply", 15+random(10));
		set("material", "wood");
	}
	setup();
}

