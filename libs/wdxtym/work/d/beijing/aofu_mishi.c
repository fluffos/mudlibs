#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","鳌府密室");
	set("long", @LONG
这里是鳌拜府的密室，而且这里似乎也没有珍藏什么特别的宝贝。
LONG );
	set("exits", ([
		"up" :  __DIR__"aofu_shufang",
	]));

	"/clone/weapon/xtbishou"->foo();
	"/clone/weapon/jsbaojia"->foo();

	setup();
}
