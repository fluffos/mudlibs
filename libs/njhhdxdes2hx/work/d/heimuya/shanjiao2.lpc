// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","羊肠小道");
	set("long", @LONG
你现在正走在一条崎岖的山路上，凹凹凸凸的山石刺得你的脚底隐
隐生疼，东边跟西边都是陡峭的山壁，山路往北通往层层叠叠的群山之中
LONG
	);

	set("exits", ([
		"northup" :__DIR__"shanjiao3",
                "southdown" :__DIR__"shanjiao1",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

