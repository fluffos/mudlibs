// Room: /d/mingjiao/banshanmen.c

inherit ROOM;

void create()
{
	set("short", "半山门");
	set("long", @LONG
      这是明教总舵的第一道关卡，一边是峭壁，一边是悬崖，
     真是一夫当关，万夫莫开，地势十分险恶。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"liaowang",
  "southdown" : __DIR__"shijie2",
  "northup" : __DIR__"shanlu1",
]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");

	setup();
	replace_program(ROOM);
}
