// Room: /d/fuoshan/grocer.c 
 
inherit MISC_ROOM; 
 
void create() 
{ 
	set("short", "杂货店");
	set("long", @LONG
这是一间刚刚开张的杂货铺，门面很小，卖的都是一些日常用品。据
说老板是从外地来的，经常去各地进一些常用的物品。
    门前立了个牌子(sign)。
LONG
	);
        set("item_desc", ([
                "zhaopai": "货物表\n",]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongjie",
]));
        set("objects", ([
                __DIR__"npc/li": 1,]));

	set("no_clean_up", 0);

	set("coor/x",10);
  set("coor/y",-520);
   set("coor/z",0);
   setup();
}
