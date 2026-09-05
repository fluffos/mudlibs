// Room: /d/gumu/zoudao1.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "走道");
        set("long", @LONG
    你走在一条一人多高的走道里，四周一片寂寂，这里有
四个洞口，西边通向厨房，不断传来阵阵香味。南边有一个休息
室，西北方向通向另一个走道，东方通向一间大侧室。


LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"chufang",
  "south" : __DIR__"xiuxishi",
  "east" : __DIR__"ceshi2",
  "northwest" : __DIR__"zoudao3",
]));
//	  set("objects",([__DIR__"npc/popo":1,]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
