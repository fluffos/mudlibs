// qilinxue.c  麒麟之血  道具配料，只能被 wizard 使用
// Written by Doing Lu 1998/11/3

inherit ITEM;

#include <ansi.h>

// 打造道具粗坯时需要配料提高道具的有效点数
// 根据 material_ attrib = z 为判断标志，其倍数属性为:scale
// 麒麟之血可以 x10

void create()
{
	set_name(HIG "麒麟之血" NOR, ({"qilin zhixue", "xue"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一滴淡绿色的麒麟血，传说太上老君在炼制" HIG "金刚琢" NOR "时加了一滴而炼成了无坚不摧的宝物。\n");
		set("unit", "滴");
		set("material_attrib", "z");
		set("scale", 20);
		set("value", 10000000);
	}
}
