// Room: /d/shaolin/bagua5.c
// Date: YZC 96/01/19

inherit ROOM;


#include "bagua.h"


void create()
{
	set("short", "青竹林");
	set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边密
密的竹林，似乎按照某种阵型排列。这里人迹罕至，惟闻
足底叩击路面。微风吹拂竹叶，又如簌簌禅唱。你仔细辨
认，惟恐迷失方向。
LONG
	);

	set("exits", ([
		"乾" : __DIR__"bagua7",
		"巽" : __DIR__"bagua6",
		"离" : __DIR__"bagua5",
		"艮" : __DIR__"bagua4",
		"兑" : __DIR__"bagua3",
		"坎" : __DIR__"bagua2",
		"震" : __DIR__"bagua1",
		"坤" : __DIR__"bagua0",
	]));

	setup();
}


int valid_leave(object me, string dir)
{
	if (check_dirs(me, dir))
		return notify_fail("你转了一圈，发现自己好象迷路了。\n");
	return ::valid_leave(me, dir);
}

