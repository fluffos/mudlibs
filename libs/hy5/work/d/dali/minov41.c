//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "巴的甸");
	set("long", @LONG
这里就是大理西部要镇巴的甸，是乌夷的重要治府，多个乌夷部
落分布在附近。坐于东泸水谷地正中，巴的甸四周多农田，以此为中
心，道路四通八达连接各方的部落。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov42",
		"south" : __DIR__"minov57",
		"eastup" : __DIR__"minov50",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
