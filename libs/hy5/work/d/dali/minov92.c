//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "河上");
	set("long", @LONG
你正身处波涛滚滚的泸水之上百多尺的空中。这是一座乌夷族特
有之藤桥，三根粗大的藤条呈一个倒“品”字形，脚踩下面一条，手
扶左右两条，攀援而过看来惊险，实际上倒也不十分困难。一阵山风
挟着脚下激流飞溅的水花吹过，你感到一阵寒意。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov93",
		"east" : __DIR__"minov91",
		]));

	set("outdoors","dali");
	set("cost", 50);
	setup();
}
