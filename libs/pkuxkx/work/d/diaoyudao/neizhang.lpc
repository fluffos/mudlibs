// Room: /d/diaoyudao/neizhang.c 内帐
// hongdou 98.09.20

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "内帐");
	set("long", @LONG
这里是内帐，通常是将帅休息的地方。现在已经被倭寇占有，成了他们的
休息室，地上一溜地摆着几张地铺，上面铺的是棉被。使人一看就想睡觉。
LONG
	);
	set("sleep_room",1);

	set("exits", ([
            "south" : __DIR__"dazhang",
	]));

	setup();
	replace_program(ROOM);

}
