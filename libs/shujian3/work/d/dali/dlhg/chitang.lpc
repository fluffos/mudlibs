// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "池塘");
	set("long", @LONG
这里是一个池塘，池塘里长满了荷花，远远望去一片绿色的世界，不由使你
想起“碧叶菡萏天接水”的诗句。仔细看还有不少鱼儿在水中嬉戏。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"xiaoqiao",
                "northwest" : __DIR__"jiashan",
	]));
	set("outdoors", "大理");
	set("coor/x",-320);
  set("coor/y",-390);
   set("coor/z",-20);
   setup();
}
