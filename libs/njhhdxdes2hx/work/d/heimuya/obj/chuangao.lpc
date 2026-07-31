// chuangao.c
// write by dfbb@hero  
// Tue Dec 26 18:10:16 CST 1995


#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("船篙", ({ "chuangao", "gao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","这是一柄普通的船篙,用来撑竹筏的\n");
		set("value", 100);
		set("material", "zhu");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回竹筏。\n");
	}
	init_spear(5);
	setup();
}
