//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "步雄部");
	set("long", @LONG
这里属江川路，是摆夷的一支--些么徒蛮聚居的地方。此地较偏
远，镇子也不大，南面一片汪洋叫做星云湖，四面山清水秀，桑林密
布。镇北是一片小平原，有些农田。此间桑树多，产丝，乡间民妇多
擅纺丝织麻。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov28",
		"east" : __DIR__"minov32",
		"north" : __DIR__"minov33",
		"south" : __DIR__"minov36",
		]));

	set("objects", ([
		__DIR__"npc/byshang" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
