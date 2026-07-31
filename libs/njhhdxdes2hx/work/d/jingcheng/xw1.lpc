#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"玄武大街"NOR);
	set("long", @LONG
这里是玄武大街的中段，往东走几步就是玄武大街和北门大街的十
字路口。北面是一个黑帮的堂口，来来往往的多是些不正派人物，
血腥场面屡见不鲜。
LONG
	);

	set("exits", ([
 "west"  :__DIR__"xw2",
 "east"  :__DIR__"bdj3",
 "north" :__DIR__"treeflow",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

