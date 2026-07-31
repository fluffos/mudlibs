// Room: yushu-lou.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"御书楼"NOR);
	set("long", @LONG
穿过碎石路，你来到了这座御书楼面前，它是嵩山派的武学秘籍等
珍贵书籍的藏居之所。北边是专供弟子们研习武功的藏书阁，南边是放
置兵器的轩辕剑阁，再往东行就是左冷禅的书房。
LONG);
	set("exits", ([ 
            "north" : __DIR__"cangshu-ge",
            "south" : __DIR__"jiange",
            "east" : __DIR__"suishilu4",
            "west" : __DIR__"shufang",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/deng" : 1,
        ]));
	set("outdoors", "嵩山");
	set("coor/x",20);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
