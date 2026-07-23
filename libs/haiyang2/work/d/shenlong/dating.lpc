// dating.c 
#include <ansi.h>;
inherit ROOM;
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
});

void create()
{
	set("short", "神龙教大厅");
	set("long", @LONG
过了一条长廊,眼前突然现出一座大厅.此厅硕大无朋,足可容千人
之众.只见一群群少年男女衣分五色,分站五个方位.青、白、黑、黄
四色的都是少年,穿红的却是少女,背上各负短剑,每一队约有百人.
LONG );

	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"houting",
		"west"  : __DIR__"zhulin",
		"east"  : __DIR__"zoulang",
	]));
	set("valid_startroom","1");

	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		__DIR__"npc/yunsumei": 1,
		"quest/menpaijob/shenlong/hong":  1,
		CLASS_D("shenlong")+"/wugen": 1,
		CLASS_D("shenlong")+"/su": 1,
		"/d/biwu/champion_slj":1
	]));
	setup();
	"/clone/board/shenlong_b"->foo();
//	replace_program(ROOM);
}

 
int valid_leave(object me, string dir)
{
	if (dir != "south" )
	{
		if(me->query("party/party_name") !=HIY "神龙教" NOR)
		{
			if(present("wugen daozhang", environment(me)) && living(present("wugen daozhang", environment(me))))
			{
				return notify_fail(
"无根道长喝道：后面是本教重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
			}
			else
				return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}
