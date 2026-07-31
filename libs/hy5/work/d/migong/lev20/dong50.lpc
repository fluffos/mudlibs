
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"前世的宫殿"NOR);
	set("long", HIY @LONG
   这里是前世的宫殿的尽头!!
  这里是一处已废弃多年的祭坛.但是仍然有祭祀的行动,
某个人似乎利用这里来进行一种秘密的祭典.祭坛上有著一
团熊熊烈火在燃烧著。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
        set("outdoors", "migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong49",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong49",
                "north" : __DIR__"dong49",
	]));
         set("objects", ([
              __DIR__"npc/lev5" : 1,
              __DIR__"npc/lev8" : 3,
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/player" : 2,
              __DIR__"npc/boss2" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

