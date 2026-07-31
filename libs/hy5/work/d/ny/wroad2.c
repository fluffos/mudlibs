
// Room: /d/snow/wroad2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long",
"这里是一条黄土路，地面坑坑洼洼，一遇阴天下雨，路面湿滑难行。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"wroad1",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/farmer":1,]));
	setup();
	replace_program(ROOM);
}
