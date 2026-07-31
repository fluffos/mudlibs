// Room: /d/fuzhou/dongjiekou.c
inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条繁忙的街道上，心里不由得起一丝感伤。
LONG );

	set("exits", ([
		"south"   : __DIR__"nandajie",
		"north"   : __DIR__"beidajie",
	
	]));
	set("objects", ([
		//"/d/city/npc/liumangtou" : 1,
		//"/d/city/npc/liumang" : 3,
	]));
set("outdoors", "by");
	setup();
}

