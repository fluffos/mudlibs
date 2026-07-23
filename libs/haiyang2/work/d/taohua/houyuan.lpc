// /d/taohua/houyuan.c
#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "桃花轩");
	set("long", @LONG
这是山庄的后院。院中摆着几个机关人，是给桃花岛弟子练功用的。
院后是桃花岛的唯一一座山峰：弹指峰。整个桃花山庄倚山而立，险势天
成。
LONG );
	set("outdoors", "taohua");
	set("exits", ([
	    "south" :__DIR__"midao",
	    "north" :__DIR__"dating",
	    "west" :__DIR__"xiaowu",
	    "east" :__DIR__"siguoshi" ,
	]));
	set("objects", ([
	      __DIR__"npc/jiguan" : 5,
	]) );
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
