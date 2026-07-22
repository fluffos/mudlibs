// jinshe-beixin.c 金蛇背心

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name("金蛇背心", ({ "jin shebeixin","jin","shebeixin","jinshebeixin" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件金光闪闪的背心，通体用金丝编织，胸口处
绣着卷曲盘绕的数条紫蛇，碧眼吐信，狰狞狠恶，散发出一股邪气。\n");
		set("material", "steel");
		set("unit", "件");
		set("value", 600000);
		set("wear_msg", HIY "只听「沙沙」声响，$N抖开一件金闪闪的背心套在身上。
瞬间金光逼人，那几条紫蛇仿佛摇摆扭曲着动起来。\n" NOR);
		set("remove_msg", HIY "$N将金蛇背心从身上脱了下来，折叠成小小的一团。\n" NOR);
		set("armor_prop/armor", 100);
	}
	setup();
}
