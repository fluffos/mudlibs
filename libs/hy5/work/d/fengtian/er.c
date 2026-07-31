// Room: /d/fengtian/er.c

inherit ROOM;

void create()
{
	set("short", "二皇妃居");
	set("long", @LONG
二皇妃居住在这里，皇帝元配夫人一直没有子嗣，所以皇帝
娶了大玉儿，大玉儿人长的到很端庄秀丽，不过也是个小家碧玉
，不是很有见识，不过很会讨皇帝欢心。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wo",
]));
        set("objects",([
        	__DIR__"npc/hh2" :1,        	
        __DIR__"npc/taijian" :1,        		
        ]));
	setup();
	replace_program(ROOM);
}
