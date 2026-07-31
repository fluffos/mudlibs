#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("鱼肠剑", ({ "yuchang-sword","sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "短小的剑身精茫四射,把手后雕刻了一条飞龙.\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_sword(860);


      set("wield_msg",
"鱼---肠----剑----------$N仰天长啸,一把短小的剑出现在手中!\n");
	set("unwield_msg","$N把短剑小心地收好.\n");
       setup();
}
