 // Room: /d/oldpine/keep2.c
#include <ansi.h> 
inherit ROOM; 
void create()
{
        set("short", "老云寨");
        set("long", @LONG
这里应该是老云寨了，虽然围绕著你的墙都是木头搭成的，但是仔
细一看，在许多险要的位置都放了不少沙包石堆，後面显然是埋伏人手
的好地方，如果有人贸然从大门口攻进来，肯定会吃大亏的，大寨的门
在你的西边，东边越过一排木桩之後就是大厅。
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"keep15",
                "east" : __DIR__"keep3",
        ]));
        set("objects", ([
                __DIR__"npc/bandit_guard" : 3,
                __DIR__"npc/bandit_leader" : 2
        ]) ); 
        set("coor/x",590);
        set("coor/y",2350);
        set("coor/z",90);
        setup();
} 
int valid_leave(object me, string dir)
{
	if ( objectp(present("bandit", environment(me))) && 
		dir == "east")
		return notify_fail("土匪拦住了你的去路。\n");
	if ( objectp(present("bandit leader", environment(me))) && 
		dir == "east")
		return notify_fail("土匪头子拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

