// Room: /d/huashan/jinshe/obj/xinjian1.c
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
"\n“盒中之物，留赠有缘。惟得盒者，务须先葬我骸骨，方可启盒，
\n要紧要紧。
\n葬我骸骨之法
\n君如诚心葬我骸骨，请在坑中再向下挖掘三尺，然后埋葬，使我
\n深居地下，不受虫蚁之害。 
\n启盒之法
\n移动夹层(move ancheng)可以开启铁合上层，得我武学秘籍。”\n"
"\n"NOR);

		set("value", 1000);
		set("material", "paper");
		set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
	}
}
