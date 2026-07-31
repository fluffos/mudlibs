// banshanmen.c 
// by yuer

inherit ROOM;

void create()
{
	set("short", "半山门");
	set("long", @LONG
      这是明教总舵的第一道关卡，一边是峭壁，一边是悬崖，
     真是一夫当关，万夫莫开，地势十分险恶。
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
		"southdown" : __DIR__"shijie3",
		"northup" : __DIR__"shanlu1",
	       "west" : __DIR__"liaowang",
	]));
	setup();
	replace_program(ROOM);
}


