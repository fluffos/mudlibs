// Room: /d/city/xidajie2.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。这里来来往往的游人你推
我挤，热闹非常。从东面不时地传来笑语莺歌，声声撩人，而从西边则传来一
阵阵的香气。南边是有名的扬州大明寺，北边就是瘦西湖边了。
LONG
	);
        set("outdoors", "扬州");

	set("exits", ([
	        "east" : __DIR__"xidajie3",
	        "west" : __DIR__"xidajie1",
		"north" : __DIR__"hubian",
		"south" : __DIR__"damingsi",
	]));

	set("objects", ([
		__DIR__"npc/liumangtou": 1,
		__DIR__"npc/liumang": 1,
	]) );
	setup();
}
