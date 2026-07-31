// shanlu2.c 
// by yuer

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
      你走在陡峭的山路上，两边都是悬崖，一不小心，
     就会掉下去，地势十分险恶。
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
		"southdown" : __DIR__"shanlu1",
		"northup" : __DIR__"damen",
	     
	]));
	setup();
	replace_program(ROOM);
}


