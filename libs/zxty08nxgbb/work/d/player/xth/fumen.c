// qjc 2000/5/3 

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "府门");
	set("long", "
    你来到一座结构宏伟的建筑前，左右石坛上各插着一根两丈多高的旗杆，
杆上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的狮子，狮子上头有一只
蝙蝠飞翔。左首旗子上写着"BLINK HIR"啸天会"NOR"三个烫金大字，银钩铁划，刚劲非凡。\n");

	set("exits", ([
		"south" : __DIR__"sclk",
          "north" : "/d/xingxiu/jiayuguan",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir=="south"){
 if (me->query("ttt")==1) return 1;
else    return notify_fail("你不是本会的人，还是先找会长加入我会在进去吧!\n");
}
       else return 1;
}
