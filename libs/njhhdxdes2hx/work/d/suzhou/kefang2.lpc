//ROOM:/d/suzhou/kefang2.c
//by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "客店房" NOR);
	set("long", @LONG
	这是客栈的客房，里面有几张床，一些客人正睡得香，你轻手轻脚地走进去，
找到一个空铺，准备睡觉。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 0);
        set("sleep_room",0);

	set("exits", ([
		"north" : __DIR__"kezhan2",
	]));

	setup();
}       
  




