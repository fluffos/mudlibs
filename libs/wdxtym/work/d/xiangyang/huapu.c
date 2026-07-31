// Room: /d/xiangyang/huapu.c  花圃
// Date: Jan. 28 2002 by Pound

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "花圃");
	set("long", @LONG
这是大路边数十丈处的大花圃，花圃之后有几间茅舍，放眼远望，四
下别无人烟。一个身穿青布衫子的村女弯着腰在整理花草，圃中的蓝花香
气馥郁，每逢夕阳落到山坳，金光反照， 射在一大片蓝花（lan hua）之
上，辉煌灿烂，甚是华美。
LONG );
	set("outdoors", "xiangyang");

	set("exits", ([
	    "west"  : __DIR__"caodi4",
	    "east"  : __DIR__"maoshe",
	    "north" : __DIR__"xibian",
	    "south" : __DIR__"huapu2",
	]));
	set("item_desc", ([
	    "lan hua" : "此花幽香淡淡，花朵色作深蓝，形状奇特，每朵花便像是一只鞋子。\n",   
	]));
	set("objects", ([
	    CLASS_D("hu") + "/cheng" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	inv = all_inventory(me);

	if (dir == "east") 
	{
	    for (i = 0; i < sizeof(inv); i++)
	    {
		if (inv[i]->is_character())
		    return notify_fail("请你先把扛着的东西放下再进去。\n");
	    }
	}

	if (! wizardp(me) && me->query("family/family_name") != "关外胡家" &&
	    objectp(present("cheng lingsu", environment(me))) && dir == "east")
	    return notify_fail("村女皱了皱眉头挡住了你的去路。\n");

	return ::valid_leave(me, dir);
}