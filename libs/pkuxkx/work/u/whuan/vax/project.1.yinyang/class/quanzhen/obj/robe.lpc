// yayi_cloth.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("全真道袍", ({ "daopao" , "robe" , "cloth" }));
	set("long", "这是一件全真教的弟子用的道袍，道袍前面画有太极两仪的阴阳鱼图案，\n"
		"后面则是八卦的卦象。\n");
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 150);
		set("armor_prop/armor", 20);
	}
	setup();
}
