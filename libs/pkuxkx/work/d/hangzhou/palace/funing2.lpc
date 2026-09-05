// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
	set("short", HIY"福宁宫内"NOR);
	set("long", @LONG
这里是福宁宫，皇帝的寝宫。
LONG
	);
       // set("outdoors", "hangzhou");

	set("exits", ([
		//"east" : __DIR__"walla",
		//"south" : __DIR__"kunning",
		//"west" : __DIR__"wall1",
		//"north" : __DIR__"yudao3",
		"out" : __DIR__"funing",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/huangmen_g" : 2,
		"/d/hangzhou/npc/huangmen_f" : 2,
		"/d/hangzhou/npc/huangdi" : 1,
        ])); 
	setup();
}
int valid_leave(object me,string dir)
{
	me->delete_temp("chaoting/see_emperor");
	return ::valid_leave(me,dir);
}