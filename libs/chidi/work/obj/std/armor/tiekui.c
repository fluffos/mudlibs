// huyao.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("铁盔" , ({"tie kui","tiekui","kui"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "这是一顶精铁制成的头盔，用以保护头部。\n");
		set("value",2000);
		set("material", "tie");
		set("oldsix/max_damage",30);
		set("oldsix/protect",4);
		set("armor_prop/armor", 10);
	}
	setup();
}
