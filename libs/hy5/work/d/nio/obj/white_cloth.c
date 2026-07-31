// white_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("纯白绸衫", ({ "white cloth", "cloth" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件雪白色的绸衫是用极珍贵的冰蚕丝所织成，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 10000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

