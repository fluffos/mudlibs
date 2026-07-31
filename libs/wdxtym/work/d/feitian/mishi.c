// mishi.c 密室
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","密室");
        set("long",
"这是一间密室，里面很暗，房间中间放着一张桌子，桌上一颗夜明珠
，散发着柔和的光芒，使得能依稀看到周围的一切，墙上挂着一幅山水画
（hua），墙边是一个书架，书架（shelf）上放着一些书（book）。\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"out" : __DIR__"woshi",
	]));
         set("item_desc",([
		"shelf" : "上面有一本发黄的书。\n",
          ]));
	set("book_count",1);
	setup();
}

