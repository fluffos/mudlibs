
#include <armor.h>

inherit "/clone/weapon/bow";

void create()
{
	set_name(HIY "点金盘龙弓" NOR, ({ "panlong gong", "gong", "bow" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "张");
		set("icon","05054");
		set("value", 200000);
		set("no_sell", "这东西怎么看上去花花绿绿的？");
		set("power", 250000);   // 攻击威力
		set("accuracy", 180);   // 准确度150%
	}
	setup();
}

