#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "石屏风");
		  set("long",@long
这是一个巨大的屏风，用昆仑山特产的汗白玉雕成，屏风上的图案是昆仑
派的师祖昆仑三圣何足道挑战少林的风姿，英姿挺拔，颇有一派宗师之象。
屏风后面就是昆仑派的前厅了。
long);
		 set("exits",([
"north" : __DIR__"guangchang",
"south" : __DIR__"qianting",
]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
