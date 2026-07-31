//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "剑川镇");
	set("long", @LONG
这里是剑川的镇中心，镇子不大，居民绝大部分是乌夷族，几乎
全都以狩猎为生。由于山高地寒，附近山林的野兽大多皮粗毛厚，有
不少皮货商在这里和当地猎人交易。北出山口则属大理北疆，也是入
蜀之途，南穿苍山则可抵大理内陆。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov88",
		"south" : __DIR__"minov90",
		]));

	set("objects", ([
		__DIR__"npc/wylieren1.c" : 1,
		__DIR__"npc/phshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
