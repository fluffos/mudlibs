// jinzhuan.c ½ð×©

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "½ð×©" NOR, ({ "jin zhuan", "jin", "zhuan" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "Ò»¶§»Æ³Î³ÎµÄ½ð×©¡£\n");
                set("value", 2000000);
                set("suit_point",50);
		  set("unit", "¶§");
	}
}

