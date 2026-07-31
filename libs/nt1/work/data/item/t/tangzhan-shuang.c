// SN:QYfleO6F8j2n01T^
// ITEM Made by player(唐斩:tangzhan) /data/item/t/tangzhan-shuang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 27 14:26:40 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m秋阴不散霜飞晚[2;37;0m", ({ "shuang" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;31m一件刻满了离愁的手套，炽炎般的火红色，仿佛烛天之火，把离别的泪水蒸发干净。[2;37;0m
铁掌缘上刻着一行小字：唐斩(tangzhan)
");
	set("value", 2100000);
	set("point", 462);
	set("material", "magic stone");
	set("wear_msg", "[1;32m$N长叹一声：[1;31m秋阴不散霜飞晚[1;32m。多少烦闷的愁苦都在这一声叹息里面，滚滚而出，仿佛时间所有的忧愁都凝聚在这一刻，在这一刹那。\n周围的人听到之后，一个个摇头太息，泪水纵横在脸上，都是一些无声的泪。[2;37;0m\n");
	set("remove_msg", "[1;32m$N收回了手上装备着的$n[1;32m，顿时大地一片火红，这无穷尽的火红好像来自于地底，摧毁一切。\n刚才大家不小心淌下的泪水，在瞬间便被蒸发的干干净净，仿佛什么也没有发生似的。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
