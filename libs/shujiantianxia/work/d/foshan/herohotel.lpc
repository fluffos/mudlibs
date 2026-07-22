// Room: /d/fuoshan/herohotel.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "英雄楼");
	set("long", @LONG
这是一间三开间门面的大酒楼，招牌上写着“英雄楼”三个金漆大字
，两边敞着窗户，酒楼里刀杓乱响，酒肉香气阵阵喷出。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"herohotel2",
  "south" : __DIR__"nanjie",
  "north" : __DIR__"guangchang",
]));
	set("no_clean_up", 0);

        set("objects", ([
        __DIR__"npc/xiaoer" : 1,
]));

	set("coor/x",0);
  set("coor/y",-540);
   set("coor/z",0);
   setup();
}
