// pobudai.c 破布袋

#include <weapon.h>
inherit WHIP;
inherit F_UNIQUE;

void create()
{
	set_name("破布袋", ({ "po budai", "budai","bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个脏兮兮的破麻布袋，里面蠕蠕而动。\n");
		set("value", 10);
		set("material", "cloth");
		set("wield_msg", "$N从怀里掏出一团破布，抓在手中当兵器。\n");
		set("unwield_msg", "$N将手中的$n折一折，放进怀里。\n");
        set("treasure",1);
	}
	init_whip(50);
	setup();
}
