#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"玄武大街"NOR);
	set("long", @LONG
这里是玄武大街的中段。西面是玄武大街和北门大街的十字路口。
北边是长安城的天监台，祭天求雨的仪式都在那里举行。东边看去
有一座高大的府第，一定是什么大官住的地方。
LONG
	);

	set("exits", ([
 "east"  :__DIR__"xw6",
 "west"  :__DIR__"bdj3",
 "north" :__DIR__"tianjt",
 "south" :__DIR__"tiejp",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

