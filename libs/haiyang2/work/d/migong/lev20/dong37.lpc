
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
                "westup" : __DIR__"dong33",
		"eastdown" : __DIR__"dong38",
		"southwest" : __DIR__"dong35",
                "northeast" : __DIR__"dong32",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong35",
                "west" : __DIR__"dong38",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(3)+6),
                "north" : __DIR__"dong3"+(random(3)+6),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

