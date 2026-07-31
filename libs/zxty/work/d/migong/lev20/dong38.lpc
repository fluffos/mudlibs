
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong39",
                "east" : __DIR__"dong37",
		"south" : __DIR__"dong35",
                "north" : __DIR__"dong32",

	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong33",
                "north" : __DIR__"dong39",
		"west" : __DIR__"dong34",
                "east" : __DIR__"dong32",
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(4),
              __DIR__"npc/lev3" : 2,

         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

