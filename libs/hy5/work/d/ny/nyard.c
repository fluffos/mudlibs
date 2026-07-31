
// Room: /d/snow/nyard.c

inherit ROOM;

void create()
{
	set("coor",({-20,-45,0}));
	set("short", "书房");
	set("long",
"这里是一间整理得相当乾净的书房，红木桌椅上铺著蓝绸巾，显得十分考究，西面的立著一\n"
"个书架，上面放著一排排的古书，往南走出房门可以看到天井。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"inneryard",
]));

	set("objects", ([
		__DIR__"npc/girl":1 ]) );

	setup();
	replace_program(ROOM);
}
