#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	 set("short", "石路");
	 set("long",@long
这是一条铺的十分平整的石板路，路面打扫的干干净净，西面过去是连接
后院的大门，东面是厨房，北面就是昆仑派弟子歇息的地方了。
long);
	 set("exits",([
             "north" : __DIR__"xiuxishi",
             "west" : __DIR__"gate",
             "east" : __DIR__"chufang",
         ]));

         set("outdoors", "昆仑");
         setup();
}
