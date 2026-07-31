
// Room: /d/snow/nroad1.c

inherit ROOM;

void create()
{
	set("short", "宁远城街道");
	set("long",
"你现在正走在宁远城的街道上，南边不远处有一间高大的院子，再往南，能看到水烟阁的一\n"
"角，北面是一片树林，树林里面是恶霸镇关西的酒店，东西面都是石板路，向西不远是衙门\n"
"，街上人来人往非常热闹。\n"
);
	set("outdoors", "ny");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad2",
  "south" : __DIR__"txgate",
  "west" : __DIR__"nroad3",
  "east" : __DIR__"nroad0",
]));
	set("no_clean_up", 0);

	set("objects", ([__DIR__"npc/playboy":1,]));
	setup();
	replace_program(ROOM);
}
