// Room: /city/dongmen.c
// YZC 1995/12/04

inherit ROOM;
#include "dating.h"
string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
这是东城门，城门正上方刻着「东门」两个楷书大字，城墙上贴着几张官府
告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小心为妙。北面有一片茂
盛的青竹林。南面就是誉满武林的正气山庄了。
LONG);
	set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
	//	"east" : "/d/taishan/yidao",
		"north" : __DIR__"ml1",
		"west" : __DIR__"dongdajie3",
		"south": __DIR__"damen",
	]));
    set("gate","东");
	set("objects", ([
		__DIR__"npc/wujiang1"+random(2) : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

void init()
{
    add_action("do_dating","dating");
    add_action("do_answer","answer");
}