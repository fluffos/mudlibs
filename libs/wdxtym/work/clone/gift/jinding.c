// jinkuai.c ½ð¿é

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "½ð¶§" NOR, ({ "jin ding", "jin", "ding" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "Ò»¶§»Æ³Î³ÎµÄ½ð¶§¡£\n");
                set("value", 800000);
		set("unit", "¶§");
	}
}

int query_autoload() { return 1; }
