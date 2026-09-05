// 望远镜

inherit ITEM;
#include "/d/city/obj/telescope.h"

void create()
{
	set_name("千里镜", ({"qianli jing","jing","telescope"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一支可以看到远处的望远镜。\n");
		set("unit", "支");
		set("value", 3000000);
		}
}
