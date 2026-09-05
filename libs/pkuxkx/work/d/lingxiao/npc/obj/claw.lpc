#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(WHT"冰爪"NOR, ({ "bing zhua", "claw", "zhua" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", WHT"这是一套冰爪，便于冰上行动，是雪山上的必备物品。\n"NOR);
		set("unit", "套");
		set("value", 1000);
		set("material", "iron");
		set("armor_prop/armor", 4);
		set("armor_prop/dodge", -1);
		set("armor_prop/claw", 5);
	}
	setup();
}