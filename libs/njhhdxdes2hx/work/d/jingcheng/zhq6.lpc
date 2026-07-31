#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"朱雀大街"NOR);
	set("long", @LONG
这里还是朱雀大街的中段。向东再走几步就到白虎大街了。路南有一
家店面整洁的小木器铺，清清静静，没有几个人走动。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq5",
 "east" :__DIR__"zhq7",
 "south" :__DIR__"kmu",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

