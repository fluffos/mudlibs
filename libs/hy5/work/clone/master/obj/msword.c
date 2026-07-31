// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("虞姬剑", ({ "wangsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把剑身只有两指宽的舞器。\n");
		set("value", 4000);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从赤皮剑鞘中抽出一把只有两指宽的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的赤皮剑鞘。\n");
	}
	init_sword(180);
	setup();
}
