// keting.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "迎客亭"); 
	set("long", @LONG
通过四雅清风，你来到了梅庄的迎客亭，这里虽然只有一张石桌
(table) 和几个石凳，但却是一尘不染，石凳和石桌之间的空隙很大，
显是方便来客与主人相互寒暄。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "south" : __DIR__"dating",
	    "north" : __DIR__"senlin1",
	]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shi.c" : 1,
	]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"table": "一张很平常的石桌，但是看上去总觉得有些古怪，要是没有"
			 "人在，倒可以钻下去查看一番。\n"
	]));

	setup();
}
void init()
{
	add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
	object ob;
	string dir;
	object me = this_player();

	if (arg != "table")
	{
		write("你要往哪儿钻？\n");
		return 1;
	}

	if (objectp(ob = present("shi lingwei", this_object())) &&
	    living(ob))
	{
		write("你偷偷的看了看" + ob->name() + "，不敢乱来。\n");
		return 1;
	}

	write("你蹑手蹑脚的绕到石桌的后面，钻进了下面的一个小洞。\n");
	if((int)me->query_skill("dodge",1) >= 30)
	{
	      write("你费尽九牛二虎之力，发现自己到了一个很神秘的地道里。\n");
	      me->move(__DIR__"didao1");
	      return 1;
	}
	write("你试着钻了一下后面的一个小洞，发现钻不进去。\n");
	me->add("jing", -10);
	me->add("qi", -10);

	return 1;
}
