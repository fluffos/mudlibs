#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"西长安街"NOR);
	set("long", @LONG
你走在一条宽阔的石板大街上。南面传来阵阵不绝于耳的颂经声和
钟謦声，那里就是长安城最大的一家寺院－“化生寺”。北面是长
安城有名的饭馆“紫阳楼”，传来阵阵觥筹交错的声音。
LONG
	);

	set("exits", ([
 "west" :__DIR__"xizhimen",
 "east" :__DIR__"xchjie3",
 "north":__DIR__"zyl",
 "south":__DIR__"hss",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

