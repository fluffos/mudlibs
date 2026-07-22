// Room: niupidazhang.c

inherit ROOM;

void create()
{
	set("short", "牛皮大帐");
	set("long", @LONG
这是座以数十张牛皮缝就的蒙古帐篷，大约方圆四五十丈，比平常的帐篷
大了几逾一倍。帐内陈设甚为简朴，正中一张矮几，后面坐着个青年，拿着本
书正向旁边站着的一个僧人和一个天竺人请教着什么。
LONG
	);

	set("exits", ([
		"south" : __DIR__"shenfeng",
	]));
	set("objects", ([
		__DIR__"../npc/hubilie" : 1,
		CLASS_D("xueshan") + "/fawang" : 1,
		__DIR__"../npc/daerba" : 1,
		__DIR__"../npc/nimoxing" : 1,
	]));
	setup();
}
