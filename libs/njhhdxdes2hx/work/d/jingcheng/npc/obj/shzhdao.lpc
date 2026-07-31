// shazhu-dao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("杀猪刀", ({ "shazhu dao" , "dao" , "blade" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","这是一柄杀猪用的剔骨尖刀，沾满了猪血。\n");
		set("value", 200);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声从腰带上抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n在袖子上擦了擦，插回在腰带上。\n");
	}
	init_blade(5);
	setup();
}
