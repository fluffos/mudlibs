
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"前世的宫殿"NOR);
	set("long", HIY @LONG
  这里是一处已废弃多年的祭坛.但是仍然有祭祀的行动,
某个人似乎利用这里来进行一种秘密的祭典.祭坛上有著一
团熊熊烈火在燃烧著。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("no_npc",1);
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong50",
		"west" : __DIR__"dong4"+(random(9)+1),
                "east" : __DIR__"dong4"+(random(9)+1),

	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong50",
                "west" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong48",
                "north" : __DIR__"dong49",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong33",
                "west" : __DIR__"dong4"+(random(9)+1),
		"north" : __DIR__"dong50",
                "south" : __DIR__"dong49",
	]));

         set("objects", ([
              __DIR__"npc/lev9" : 5,
              __DIR__"npc/lev7" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

