//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "蜜纳甸");
	set("long", @LONG
这里是乌夷分支乌蒙族阔部聚居的镇子，阔部领蜜纳甸和阔州。
附近有溪流汇入泸水，灌溉颇便利，因而农业相对谷中其他地区较发
达。镇中尽是些简陋的民居，也无甚客商过往。
LONG
        );

	set("exits", ([
		"southwest" : __DIR__"minov42",
		"west" : __DIR__"minov47",
		]));

	set("objects", ([
		__DIR__"npc/wygirl.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
