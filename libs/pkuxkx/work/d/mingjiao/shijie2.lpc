// Room: /d/mingjiao/shijie2.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
      你走在一条坚实的石阶上。一边是峭壁，一边是悬崖，
     抬头隐约可见笼罩在云雾中的明教总舵光明顶，地势十分险恶。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"shijie1",
  "northup" : __DIR__"banshanmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");

	setup();
	replace_program(ROOM);
}
