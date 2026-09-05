// jinbi.c

#include <ansi.h>

inherit ITEM;

int is_saw() { return 1; }

void create()
{
	set_name("第二届玩家征文活动奖励金币", ({ "jin bi", "bi"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else
        {
        set("value", 100);
		set("unit", "枚");
        set("material", "gold");
		set("long", "一块特殊的金币，你可以拿去当铺换钱。记得不要存或者当，直接卖掉！否则会掉价的。\n");
	}
	setup();
}

