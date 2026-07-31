// liufudayuan.c
#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "刘府大院");
	set("long", @LONG
刘府大院里现在挤着很多江湖豪客，原来今天是刘正风金盆洗手的
好日子。刘老爷子在衡阳人缘很好，来捧场的自然不少，大院里已摆了
很多张桌子，杯筷往来，很是热闹。
LONG);
	set("exits", ([
	    "north"  : __DIR__"liufudating",
	    "south"    : __DIR__"liufugate",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
		"/d/huashan/npc/haoke" : 1,
	]));
	setup();
}
