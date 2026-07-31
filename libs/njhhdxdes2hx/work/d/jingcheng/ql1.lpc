#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"青龙大街"NOR);
	set("long", @LONG               
这里是青龙大街的北段，路西有一座带着异域风情的房子，牌匾上书
“敕建景教寺”，是唐初大书家褚遂良的手笔。南面是玄武大街和青
龙大街的十字路口。
LONG
	);

	set("exits", ([
 "south"  :__DIR__"xw3",
 "west"   :__DIR__"jjs",
 "east"   :__DIR__"mzh1",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

