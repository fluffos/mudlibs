// Room: /d/gumu/zoudao3.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "走道");
        set("long", @LONG
        你走在一条一人多高的走道里，四周一片寂寂，这里有
两个洞口，北边通向侧室，东南方向通向另一个走道。


LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  //est" : __DIR__"chufang",
  "north" : __DIR__"ceshi3",
  //ast" : __DIR__"ceshi2",
  "southeast" : __DIR__"zoudao1",
]));
//	  set("objects",([__DIR__"npc/popo":1,]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
