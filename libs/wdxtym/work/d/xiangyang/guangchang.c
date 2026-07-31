// Room: /d/xiangyang/guangchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "中央广场");
	set("long", @LONG
这里是襄阳的中央广场，铺着青石地面。东面通向青龙门，
西面通向白虎门，南面直达朱雀门，远远地你可看到北面是襄
阳安抚使衙门。
LONG );
	set("outdoors", "xiangyang");
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"east"  : __DIR__"eastjie1",
		"west"  : __DIR__"westjie1",
		"south" : __DIR__"southjie1",
		"north" : __DIR__"anfupailou",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/bing" : 1,
	]));
	setup();
}

