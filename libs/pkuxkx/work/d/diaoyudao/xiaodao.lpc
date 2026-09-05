// Room: /d/diaoyudao/xiaodao.c 灌木小道
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "灌木小道");
	set("long", @LONG
你钻进灌木丛，旁边的灌木，已经被你破坏得不成样子，
如果你不小心碰到灌木枝上，就会被刺出血。东北不远就是
山崖底，好象有一个洞口在那里。
LONG
);

	set("exits", ([
                 "northeast" : __DIR__"dongkou",
		 "out" : __DIR__"guanmu"+(random(3)+1),
            ]));
	
	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}
