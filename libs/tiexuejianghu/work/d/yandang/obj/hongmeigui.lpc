#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIR"红玫瑰"NOR, ({ "meigui","flower"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枝");
		set("long", "一枝"+HIR"红玫瑰"+NOR+",送给情人的最佳礼物。\n");
		set("value", 1000);
		set("material", "wood");
	}
	init_sword(30);


      set("wield_msg",
"$N轻笑一声,手腕转了几下,手中出现一朵灿烂的"+HIR+"红玫瑰.\n"NOR);
	set("unwield_msg","$N手腕一振,手中的"+HIR+"红玫瑰"+NOR+"化为一蓬红雨洒下.\n");
       setup();
}
