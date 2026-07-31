// shijie3.c 石阶
// by yuer

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
      你走在一条坚实的石阶上。一边是峭壁，一边是悬崖，
     抬头隐约可见笼罩在云雾中的明教总舵光明顶，地势十分险恶。
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
		"southdown" : __DIR__"shijie2",
		"northup" : __DIR__"banshanmen",
	]));
	setup();
	replace_program(ROOM);
}


