// Room: /d/fengtian/jjf2.c

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
进入大金皇宫是一个四四方方的大庭院，庭院四周有很多笔直
的白杨树，一条青石甬路打扫的干干净净，这里直通皇帝行宫的
大会客厅，庭院里还种了很多花草显得很有生气。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jjf1",
  "east" : __DIR__"jjf3",
]));

        set("objects",([
        	__DIR__"npc/bing2" :2,        
        	__DIR__"npc/wujiang3" :1,        
       	
        ]));

        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("guan bing", environment(me))) && 
		dir == "east")
		return notify_fail("官兵拦住了你的去路。\n");

	if ( objectp(present("cao huachun", environment(me))) && 
		dir == "east")
		return notify_fail("曹化淳拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

