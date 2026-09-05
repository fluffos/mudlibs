// Room: /d/gumu/ceshi3.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "侧室");
        set("long", @LONG
这是一间较小的石室，约一人高，里面堆满了各种各样的
杂物，看样子是古墓派的储藏室。
LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  
  "south" : __DIR__"zoudao3",
  
]));
	  set("objects",([__DIR__"obj/jiang":1,
                        __DIR__"obj/yufengzhen":20,
				
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
