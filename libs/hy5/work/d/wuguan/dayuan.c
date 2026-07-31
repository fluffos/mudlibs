//cool 98.4.18
inherit ROOM;

void create()
{
	set("short", "武馆大院");
	set("long", @LONG
这是个大院子，东西两边都是练武场，不少人在这里习武强身，这里
很吵，乱哄哄的，你看见不时有扛着东西的，挑着水的匆匆而过。
LONG);
	set("exits", ([
	        "south" : __DIR__"guanmen",
		"north" : __DIR__"dayuan2",
                "east" : __DIR__"lang2",
		"west" : __DIR__"lang1",
	]));
        set("no_fight",1);
        set("no_sleep_room", 1);  
        set("valid_startroom", 1);
	setup();
//        "/clone/board/wuguan_b.c"->foo();
        replace_program(ROOM);
}


