//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "罗伽甸");
	set("long", @LONG
这里是滇池的东南，是么些蛮的罗伽部落聚居的地方。么些蛮族
属摆夷。摆夷喜居平原沿水，（沿水的平原坝子，即为“甸”）。这
里土壤肥沃，灌溉便易。罗伽是一个大部落，罗伽甸是个相当大的镇
子，大理国在这里设有治府。
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"dianchi",
		"southwest" : __DIR__"minov12",
		"east" : __DIR__"minov13",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
