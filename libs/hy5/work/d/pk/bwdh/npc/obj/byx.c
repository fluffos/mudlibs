///u/jpei/thd/obj/biyuxiao.c 碧玉箫
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIG"碧玉箫"NOR,({"biyu xiao","xiao"}));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","支");
		set("value",20000);
                set("treasure",1);
		set("material","steel");
		set("long","这是一支通体晶莹的用碧玉做的箫，看起来年代十分久远。\n");
		set("wield_msg",HIM"$N伸手轻轻一招，一支$n已出现在$N手中。\n"NOR);
		set("unwield_msg",HIM"$N一声清啸，将$n插回腰间。\n"NOR);
	}
	init_sword(100);
	setup();
}
