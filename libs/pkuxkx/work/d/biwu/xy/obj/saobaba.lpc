// 扫把把 saobaba.c
//create by zine 27 aug 2010

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name("扫把把", ({ "ba" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄大扫把的把子。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插到背后。\n");
	}
	init_staff(1);
	setup();
}
