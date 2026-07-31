// Room: /open/dt/ruyidufang.c
inherit ROOM;
void create()
{
	set("short", "如意赌坊");
	set("long", @LONG
如意赌坊是方圆数百里最大的赌场，所以有很多外地人也慕
名而来。赌场内十二个时辰都有人赌钱，从不歇业。场内人头涌
动，沸沸扬扬，几十名侍女身着艳装，像穿花蝴蝶一般在场内翩
然来去，不时向街赌徒们抛着媚眼，你不觉也想试试运气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"youfujie2",
]));



        set("objects",([
        __DIR__"npc/judge" : 1,
]));


	setup();
}
