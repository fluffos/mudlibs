// jinkuai.c ½ð¿é

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "½ð¿é" NOR, ({ "jin kuai", "jin", "kuai" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¶§»Æ³Î³ÎµÄ½ð¿é¡£\n");
		set("value", 20000);
		set("suit_point",30);
		set("unit", "¶§");
		set("zhuanshu",20000);
	}
}

