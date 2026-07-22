// /d/mingjiao/shuling1.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",GRN"树林"NOR);
       set("long", @LONG
这是一片乱树林。几十丈高的树木簇在一块，密实的枝叶象一蓬蓬巨伞般
伸向天空，把阳光遮得丝毫也无。你一走进这这觉得阴阴森林的，你的感觉告
诉你，要赶快离开，东面是明教的巨木旗。
LONG);    
	set("exits", ([
		"east" : "/d/mingjiao/muqi",			
		"south" : __DIR__"shuling3",
		"west" : __DIR__"shuling4",
                "north" : __DIR__"shuling"+(3+random(2)),
	]));    
	set("objects", ([
             BINGQI_D("shitou") : 1,
	     BINGQI_D("da-shitou") : 1,
	]));
        set("outer_times", 10);
        set("outdoors", "明教光明顶");
        set("coor/x",-300);
  set("coor/y",190);
   set("coor/z",100);
   setup();
}

#include "/d/mingjiao/npc/attacker.h";

