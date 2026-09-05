//dating.c
// for xiakedao
// by aiai 98/10/29
// Modified by iszt@pkuxkx, 2007-04-02

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
一条猩红的地毯，自门口笔直地铺向远处，其长竟不止十丈。尽头处又是十
数级石阶，阶上又是一重门户。原来小阁楼里连接山腹，外观虽小，里面却是宽
容博大。两壁间灯光辉煌，照着当中。
LONG);
	set("exits", ([
		"south" : __DIR__"backyard",
		"northup" : __DIR__"dadian",
	]));
	create_door("south", "黄金门", "north", DOOR_CLOSED);

	setup();
}

void init()
{
	object me = this_player();
	if(interactive(me))
		me->set_temp("intime", time());
}
/*
int valid_leave(object me, string dir)
{
	int in_time;
	
	if (dir == "south")
	{
		in_time = me->query_temp("intime");
		me->set_temp("wait_time", time()-in_time);	
	}
	return 1;
}
*/
