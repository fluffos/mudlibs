// qipan 玄铁棋秤

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("玄铁棋秤", ({ "qi cheng", "cheng" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块铁铸的棋枰，上刻着十九道棋路，听说是件宝物，能收诸种兵刃暗器\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", "$N拿出一块$n，抓住$n之角，作为武器。\n");
		set("unwield_msg", "$N将手中的$n放回行囊。\n");
	}
	init_sword(15);
	setup();
}
