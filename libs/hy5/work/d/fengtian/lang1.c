// Room: /d/fengtian/lang1.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是通往后花园的走廊，这里可以远远看见皇帝行宫的后院
，不过一拐弯就可以先到厨房了。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"chufang",
  "north" : __DIR__"jjf3",
]));
        set("objects",([
        	__DIR__"npc/gongnv" :3,        
        	__DIR__"npc/taijian" :1,        	
        ]));
	setup();
	replace_program(ROOM);
}
