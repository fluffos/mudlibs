// changge.c 长歌
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIR"长歌"NOR, ({ "changge sword", "sword" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("icon", "10024");
		set("long", "这把剑外观十分平凡，剑鞘古拙无光，只有剑锋口处隐冷地闪着一种
似波光似水纹,但又如毒蛇蓝牙般的寒芒。\n");
		set("value", 1000000);
		set("material", "steel");
		set("unique", 1);
		set("wield_msg", HIB "只听「铮」的一声清响，长歌脱鞘飞出，自行跃入$N掌中。
只觉得乱红飞舞,剑气纵横。\n" NOR);
		set("unwield_msg", HIY "长歌剑自$N掌中飞起，在半空中一转，「唰」地跃入剑鞘。\n" NOR);
	}
	init_sword(150);
	setup();
}
