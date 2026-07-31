inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "寝宫");
	set("long", @LONG
这里就是保定帝的寝宫了，寝宫整个布置都很简洁，若不是床上被褥的花
纹绣着只有帝王之家特有的龙的图案，你根本就不能想到这里就是大理皇帝段
正明的寝宫。
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan",
	]));
	set("objects", ([
            __DIR__"npc/queen" : 1
	]) );

	set("coor/x",-310);
  set("coor/y",-380);
   set("coor/z",-20);
   setup();
}


