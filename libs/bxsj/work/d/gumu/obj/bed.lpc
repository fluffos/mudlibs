// Modify By River 98/08/29
// bed.c 寒玉床
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIC"寒玉床"NOR, ({"hanyu chuang", "bed", "chuang"}));
 	set_weight(2500000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", HIC"此床看上去普普通通尤如青石，却是江湖中人梦寐以求的武林至宝。\n"+
				"传说中此床可疗任何内外伤病，有回天之效。\n"+
				"更有人言此床可速成武功, 大益于内功修为。\n"NOR);
		set("value", 800000);
		set("no_get", 1); 
		set("material","stone");
	}
	setup();
}
