#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("皮鞭", ({ "pi bian", "bian", "whip" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是一条牦牛皮制的皮鞭，粗糙然而坚韧。\n");
		set("value", 600);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出$n，甩了甩。\n");
		set("unwield_msg", "$N将手中的$n盘回腰间。\n");
	}
	init_whip(50);
	setup();
}