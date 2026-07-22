//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long",@LONG
这里是卧云庵前的广场。这里虽然不能算是最大寺庙，但殿廊亭楼具
全，广场两边种植了茂密的冷杉树，浓荫遍地，芳草如茵，幽雅秀美。广
场中间一条青砖铺成的大道直通正殿，转过两边的树林是许多长廊，通往
其他地方。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"north" : __DIR__"miaomen",
                "south" : __DIR__"dadian",
                "east"  : __DIR__"zoulang1",
                "west"  :__DIR__"zoulang2",
	]));

	set("objects",([
	]));
	setup();
}
