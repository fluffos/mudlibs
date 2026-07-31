#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "世外桃源");
	set("long", @LONG
这里桃花如画，春意盎然。小桥流水，落英缤纷，好一番诗情雅意。河边有一块大石，一女子轻妆素裹，倚石凝眉，说不尽的哀思。旁边一男子英武挺拔，傲然而立。
旁边有一个牌子，你也许应该仔细看看。
LONG );
	set("no_fight", 1);
	set("item_desc", ([
		"【牌子】" : "四个不同方向的出口代表不同的角色发展方向，请四处看一下然后选择你满意的内在品质进入阎罗殿转生。\n",
	]));
	set("objects", ([
		__DIR__"npc/shuisheng" : 1,
		__DIR__"npc/diyun"     : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"roome",
		"south" : __DIR__"rooms",
		"west"  : __DIR__"roomw",
		"north" : __DIR__"roomn",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	if (! objectp(ob = present("shui sheng", this_object())))
	{
		ob = new(__DIR__"npc/shuisheng");
		ob->move(this_object());
	}

	if (! me->query("registered"))
	{
		me->set("registered",1);
	}

	if (! objectp(ob = present("di yun", this_object())))
	{
		ob = new(__DIR__"npc/diyun");
		ob->move(this_object());
	}
	message_vision("狄云对$N一抱拳，道：人生路全靠自己走，朋友走好！\n", me);

	return 1;
}

