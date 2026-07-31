#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"红莲的迷宫"NOR);
	set("long", HIR @LONG
  此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且有时有一些奇怪的
岩石结晶，当其被火光映照之时，会反射出绚丽的光线，加上原有的火红构成一副
优美的景色，
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong8"+(random(4)+3),
            	"east" : __DIR__"dong8"+(random(4)+3),
		"south" : __DIR__"dong87",
		"north" : __DIR__"dong8"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong8"+(random(3)+6),
		"north" : __DIR__"dong8"+(random(4)+4),
	]));
        set("objects", ([
              __DIR__"npc/lev9" : 2,
              __DIR__"npc/player" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
