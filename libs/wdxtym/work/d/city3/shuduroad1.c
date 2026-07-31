// Room: shuduroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "蜀都道");
	set("long", @LONG
这里是蜀都大道，向西就可以到提督府了。过往的车马卷起阵阵
尘土，来去的官差阵步如飞，有一些官兵在路上巡哨。你感到一点点
害怕，真后悔拐进这里来。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
	    "east"  : __DIR__"eastroad2",
	    "west"  : __DIR__"guangchang",
	]));

	set("objects", ([
	    "/d/city/npc/bing" : 2,
	]));

	setup();
}
