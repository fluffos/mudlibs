// Room: /d/huashan/jinshe/obj/xinjian.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ITEM;
void setup()
{}
void create()
{
	set_name( "信笺", ({ "xin jian", "jian" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",RED
"\n“君是忠厚仁者，葬我骸骨，当酬以重宝秘术。大铁盒开启时
\n毒箭射出，愈中书谱地图均假，上有剧毒，以惩贪欲恶徒。真者
\n在此小铁盒内。” \n""\n"NOR);
		set("value", 10000000);
		set("material", "paper");
		set("no_drop", "这样东西不能离开你。\n");
              set("no_get", "这样东西不能离开那儿。\n");
	}
}
