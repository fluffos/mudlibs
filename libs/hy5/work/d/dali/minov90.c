//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "苍山中部");
	set("long", @LONG
你行走在苍山中部山颠，此间地形极险，两边山高入云，中间一
条崎岖不平的山路。路西不远一条大河自北略偏西方向南流过，隆隆
水声遥遥可闻，正是南诏名川--泸水。此路是自西川和土番入大理的
必经之途，时有客商过往。由此向南穿越苍山可抵下关城，北面不远
则是出苍山的山口。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov89",
		"southwest" : __DIR__"minov91",
		"southdown" : __DIR__"xiaguan",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
