// D:\xkx\d\liuxiu-shanzhuang\npc\obj\zhuli.c竹笠
// labaz 2012/10/22

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( HIG"竹笠"NOR , ({ "zhu li", "li" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "这是一顶新扎的竹笠。\n");
		set("value", 150);
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	setup();
}
