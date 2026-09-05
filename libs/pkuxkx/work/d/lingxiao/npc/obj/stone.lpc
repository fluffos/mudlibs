// stone.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
	set_name(CYN"飞蝗石"NOR, ({ "feihuang shi", "shi", "stone"}));
  set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","些");
		set("base_unit","枚");
		set("long", "这是一枚飞蝗石，是最普通的暗器。\n");
		set("material", "stone");
		set("base_weight", 5);
		set("wield_msg", "$N取出一把飞蝗石捏在手中。\n");
		set("unwield_msg", "$N将飞蝗石放回袋中。\n");
	}
	set_amount(1);
	init_throwing(30); 
	setup();
}