#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"秩序的迷宫"NOR);
	set("long",HIW @LONG
在这里你能感觉到一种神圣且庄严的力量,四周柔和的
亮光更使得这地方充满著祥和的气氛,这里东西南北都有通
路,但是每个通道上似乎都有魔法障壁。
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"north" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong70",
	]));
if (random(2)==0)
	set("exits", ([
		"north" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong6"+(random(7)+3),
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong70",
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong69",
		"west" : __DIR__"dong70",
	]));

       set("objects", ([
              __DIR__"npc/player" : 3,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
