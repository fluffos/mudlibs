#pragma save_binary
// Room: /d/goathill/mroad1.c

inherit ROOM;

void create()
{
	set("coor",({20,4900,10}));
	set("short", "山路");
	set("long",
"你现在正走在一条崎岖的山路上，凹凹凸凸的山石刺得你的脚底\n"
"隐隐生疼，山路往南不远处通往一个山腰的台地，这一带最大的\n"
"镇甸就位在台地上，东边跟西边都是陡峭的山壁，山路往北通往\n"
"层层叠叠的群山之中。\n"
);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
"south" : "/d/green/path6",
		"north" : __DIR__"mroad2",
]));

	setup();
	replace_program(ROOM);
}
