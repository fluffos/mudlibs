// Room: /d/emei/leidongping.c 峨嵋派 雷洞坪


inherit ROOM;


void create()
{
	set("short", "雷洞坪");
	set("long", @LONG
这是一座用天然石洞修砌而成的小寺庙，在西首的墙上挂了一些山水
画轴,庙中放了一张红木香案，香案上供品齐备，上插檀香数枝，香烟缭
绕。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"lingyunti",
                "east": __DIR__"basipan1",
	]));

	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));

	setup();
     }
