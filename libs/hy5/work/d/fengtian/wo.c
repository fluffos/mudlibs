// Room: /d/fengtian/wo.c

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG
皇帝休息的地方，也是皇帝元配夫人皇后的卧房，皇后嫁给
皇帝多年，夫妻也相敬如宾。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jjf5",
  "west" : __DIR__ "er",
]));
        set("objects",([
        	__DIR__"npc/hh" :1,        	
        	__DIR__"npc/gongnv" :1,        		
        ]));
	setup();
	replace_program(ROOM);
}
