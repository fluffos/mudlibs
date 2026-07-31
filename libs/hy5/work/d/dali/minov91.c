//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "苍山山路");
	set("long", @LONG
此处正当河边，两侧山壁几乎是直上直下，面前是一条大河自北
滔滔而来，在此折向东咆哮而去，河水奔腾汹涌，拍击河岸，发出一
阵阵骇人的轰响。这里恰缝河湾，河床较窄，河谷上并无桥梁，只有
三根粗藤条横跨两岸，这端绑在一棵大树上，似可攀援而过。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov92",
		"northeast" : __DIR__"minov90",
		]));

	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
