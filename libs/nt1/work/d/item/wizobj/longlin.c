// longlin.c  北海龙麟  防具原料，只能被 wizard 使用
// Written by Doing Lu 1998/11/3

inherit ITEM;

#include <ansi.h>

// 打造防具粗坯时需要的一种原料
// 根据 material_ attrib = y 为判断标志，其有效点数为:power_point
// 北海龙鳞的有效点数是 1000

void create()
{
	set_name(HIC "北海龙鳞" NOR, ({"beihai longlin", "longlin", "lin"}));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是哪吒闹海时从北海神龙身上剥下的一片鳞甲，传说拖塔天王曾经用它练成过" HIC "龙鳞宝甲。\n" NOR);
		set("unit", "片");
		set("material_attrib", "y");
		set("power_point", 1000);
		set("value", 10000000);
	}
}
