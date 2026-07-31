//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit ROOM;

void create()
{
	object me;
	me = this_player();

	set("short", "庄府大厅");
	set("long", @LONG
这是一间灵堂。堂上供了七八个牌位，看来一座灵堂上供的是一家死
人。一阵阴风吹过，蜡烛突然灭了。接着一阵凄厉的哭喊声直冲耳梢，让
人毛骨悚然，灵堂上有一块灵牌（pai）剧烈的摇动着。.......
LONG
);

	set("exits", ([
		"west" : "/d/city2/zhuang5",
	]));
	
	set("objects", ([
		"/d/city2/npc/dizi": 1,
	]));
	
	set("item_desc",([
		"pai" :"只见灵牌上写着："+ me->query("name") +"之灵位！一阵不详的预感袭上心头......\n",
	
	]));


	
	set("outdoors", "city2");
	setup();
	replace_program(ROOM); 
}


