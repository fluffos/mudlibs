// Modify By River 98/12 
inherit ROOM;
void create()
{
        set("short", "长廊");
	set("long", @LONG
这是镇南王府内的一条长廊，长廊一直通向王府内，廊边雕满了花边，透
过缕空的花纹，你可以看见廊外的树木花草。西面是镇南王的卧室，东面是书
房。南面过去是一个小花园。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"lang3",
            "southeast" : __DIR__"lang7",
            "east" : __DIR__"shufang",
	    "west" : __DIR__"woshi1",
        ]));

	set("objects", ([
		__DIR__"npc/caodi-puren": 1,
	]) );
 
        set("coor/x",-310);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();
}
