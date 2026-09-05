//听香剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIM"听香剑"NOR, ({ "tingxiang sword", "sword","tingxiang" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是姑苏慕容的收藏的宝剑，锋利无比。\n");
                 set("value", 150000);
		set("material", "steel");
           set("wield_msg", GRN"$N从剑鞘中拔出一柄红光四射的" + HIM "听香剑" NOR + GRN"，握在手中，轻轻一弹，发出「嗡嗡」的声音。\n"NOR);
		set("unwield_msg", GRN"$N舞了个剑花，将" + HIM "听香剑" NOR + "插回鞘中。\n"NOR);
	}
           init_sword(135);
	setup();
}
