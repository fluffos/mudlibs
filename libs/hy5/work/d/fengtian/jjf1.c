// Room: /d/fengtian/jjf1.c

inherit ROOM;

void create()
{
	set("short", "大金皇宫大门");
	set("long", @LONG
红漆的大门足有两丈多高，门口是两座威武的石狮子，张牙
舞爪。门上一块横匾上书“大金皇宫”几个大字，门口的石
阶打扫的干干净净，这里就是大金皇帝的府第。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wy6",
  "east" : __DIR__"jjf2",
]));

        set("objects",([
        	__DIR__"npc/bing" :1,        
        	__DIR__"npc/bing2" :3,        	
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
	return ::valid_leave(me, dir);
}

