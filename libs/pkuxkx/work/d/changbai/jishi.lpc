// Room: jishi.c

inherit ROOM;

void create()
{
	set("short", "集市");
	set("long", @LONG
这里是城中一片开阔的广场，乃是来往客商交易毛皮，药材以及其它杂
物的集市。由于附近方圆百里仅有这么一个集市，因此这里的人最多，货物
也最全。不同的服饰，不同的语言都可以在这里看到，听到。杂乱的人群中
传出各种吆喝，叫卖的声音。西面有一座低矮的土房，门口挂着一个写满鲜
文的幌子，还传来阵阵的肉香，看起来象一个小饭馆。
LONG
	);

	set("exits", ([
		"south" : __DIR__"nancheng",
                "east" : __DIR__"dongcheng",
                "north" : __DIR__"beicheng",
                "west" : __DIR__"xrguan",
	]));
        set("objects",([
		__DIR__"npc/phshang" : 1,
                "/clone/npc/camel1": 0,
	]));


        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

