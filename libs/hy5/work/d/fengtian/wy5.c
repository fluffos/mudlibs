// Room: /d/fengtian/wy5.c

inherit ROOM;

void create()
{
	set("short", "威远路");
	set("long", @LONG
这里是威远路的中段，也是威远路最热闹的地方，因为这里
有红灯区还有赌场啊！路北最大的一家就是怡红院，而路南就是
银钩睹坊了。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wy4",
  "east" : __DIR__"wy6",
  "north" : __DIR__"ji1",
]));

	set("objects",([
		"/d/city/npc/xunbu" : 2,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
