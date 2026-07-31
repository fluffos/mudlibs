// Room: /d/xiangyang/caodi3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进
城了，虽然蒙古兵没来到南门，但肃杀氛围丝毫不减。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
//		"north"  : __DIR__"southgate2",
		"north"  : "quest/menpaijob/gaibang/guanka",
		"south"  : "/d/wudang/wdroad5",
		"west"   : "/p/guangchang1",
		"southdown"  : "/d/tiezhang/hunanroad1",
		"east"   : "/quest/skills2/wakuang/kuangshan",
	]));
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv;
	int sizeinv;
        if( dir=="west" && !userp(me) )
                return notify_fail("那里只有玩家才能进去。\n");
      if( dir=="west" )		
{
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character()&& userp(inv[sizeinv])  )  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
}		
        return ::valid_leave(me, dir);
}