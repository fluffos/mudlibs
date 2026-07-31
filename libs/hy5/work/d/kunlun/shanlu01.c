// shanlu01.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "山路");
		  set("long",@long
这里已经是昆仑派的地方了，路边花草满地，虽然是寒冬，这里却
仍然生机勃勃，到处传来鸟兽的叫声，前面山上就是昆仑派的居所了，
北面是来的时候的山门。
long);
		 set("exits",([
"westdown" : __DIR__"shanmen",
"southup" : __DIR__"shanlu02",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
