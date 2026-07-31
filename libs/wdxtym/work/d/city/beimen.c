// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "北门");
	set("long", @LONG
这是北城门，因为曾经失火，到现在城墙还是黑乎乎的，因此白纸
黑字的官府告示就显得特别现眼。北方是一片崇山峻岭，一条
黄土小径在山里蜿蜒而上。
LONG );
	set("item_desc", ([
		"【告示】" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beidajie2",
		"north" : "/d/shaolin/yidao",
		"west"  : "/d/huanghe/caodi1",
	    "east" : "/d/city/postofficer",
	]));
	set("objects", ([
		"/kungfu/class/yunlong/ma" : 1,
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "city");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

