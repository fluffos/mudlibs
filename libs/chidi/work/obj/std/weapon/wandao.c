// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("弯刀", ({ "wan dao" ,"wandao","dao","blade"}) );
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 200);
		set("material", "tie");
		set("long", "这是一寻常的弯刀，份量大约三、四斤重。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(15);
	setup();
}
