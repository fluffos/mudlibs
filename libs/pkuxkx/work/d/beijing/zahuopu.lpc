// Room: /d/beijing/zahuopu.c
#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", HIC"杂货铺"NOR);
	set("long", @LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。
摊上立着一块招牌(zhaopai)。
LONG);

	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"northeast" : __DIR__"tianqiao",
	]));
	set("objects", ([
		__DIR__"npc/liu": 1,
	]));

	setup();
	replace_program(ROOM);
}