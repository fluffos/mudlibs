
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
		"southup" : __DIR__"dong40",
                "northdown" : __DIR__"dong3"+(random(4)+5),
		"westsouth" : __DIR__"dong3"+(random(4)+5),
                "eastnorth" : __DIR__"dong3"+(random(4)+5),

	]));
if (random(2)==0)
	set("exits", ([
		"southup" : __DIR__"dong3"+(random(4)+5),
                "northdown" : __DIR__"dong3"+(random(4)+5),
		"westsouth" : __DIR__"dong3"+(random(4)+5),
                "eastnorth" : __DIR__"dong40",
	]));
         set("objects", ([
              __DIR__"npc/lev1" : 3,
              __DIR__"npc/lev3" : 2,
              __DIR__"npc/lev2" : 3,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}