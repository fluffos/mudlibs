#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIM"南大街"NOR);
	set("long", @LONG
一条宽阔平整的石板大街。北面就可望到钟楼。东面传来朗朗的书
声，那里是唐朝的大学－国子监。路西是一座富丽堂皇的大院子，
那里是招待国宾和外国使节的宾馆。南面是南大街和朱雀大街的
十字路口。
LONG         
	);

	set("exits", ([
 "north" :__DIR__"ndj1",
 "south" :__DIR__"ndj3",
 "west"  :__DIR__"gbg",
 "east"  :__DIR__"gzj",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

