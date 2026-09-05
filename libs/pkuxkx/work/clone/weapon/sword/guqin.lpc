// guqin  古琴

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("古琴", ({ "gu qin", "qin" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张瑶琴，颜色暗旧，当是数百年甚至是千年以上的古物。\n");
		set("value", 500);
		set("material", "wood");
		set("music", "qin");
		set("wield_msg", "$N拿出一张$n，双手抱住，微微一笑。\n");
		set("unwield_msg", "$N将手中的$n轻轻地放下。\n");
	}
	init_sword(15);
	setup();
}
