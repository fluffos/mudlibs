// gangdao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
    	set_name(WHT"村正妖刀"NOR, ({ "cunzheng yaodao", "yaodao", "blade", "cunzheng", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是日本刀中的至宝，出自扶桑名师村正之手。\n");
		set("value", 1000);
		set("rigidity", 5);
                set("sharpness", 5);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 3);
                set("treasure",1);       
		set("material", "steel");
		set("wield_msg", "$N缓缓地出$n来，闪出一道亮丽的光华！\n");
		set("unwield_msg", "$N挽个刀花，将$n插回刀鞘。\n");
	}
	init_blade(120);
	setup();
}
