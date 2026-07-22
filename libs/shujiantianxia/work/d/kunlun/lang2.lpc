#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	 set("short","走廊");
	 set("long",@long
这是一条长廊，连接前厅和客房，不断看见各种打扮的江湖人士走过，看
过廊外，是一片青色的树林，幽静雅致，只听见不断传来的鸟鸣声。
long);
	 set("exits",([
            "north" : __DIR__"lang",
            "east" : __DIR__"liangong",
            "west" : __DIR__"lang1",
         ]));

         set("outdoors", "昆仑");
         setup();
}
