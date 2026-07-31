#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIY"夜魔弧刀"NOR, ({"blade","dao"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 200000);
                set("no_put",1);
                set("no_zm",1);
		set("material", "iron");
		set("weapon_prop/intelligence", 2);
		set("long", "据说可以增加使用者的智慧。这是一件上古宝物。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(140);
	setup();
}
