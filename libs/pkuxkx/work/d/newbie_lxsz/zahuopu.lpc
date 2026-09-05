//D:\xkx\d\liuxiu-shanzhuang\zahuopu.c杂货铺
// labaz 2012/10/22
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。杨掌柜
懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵重的东西。
摊上立着一块招牌(zhaopai)。
LONG
	);

	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"west" : __DIR__"jizhen-xiaodao2",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));

	setup();
}

void init()
{
	add_action("show_quest","quest");
}
