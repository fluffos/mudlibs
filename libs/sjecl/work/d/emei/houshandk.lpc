// emei 洞口

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
这里是峭壁上的洞口，洞口边插满了刀剑，里面黑乎乎的，你仔细定
了定神，好像洞里有一个人影正在研究武学。
LONG);
	set("exits", ([
		"enter" : __DIR__"houshansd",
	]));

	set("objects",([
		"/clone/weapon/blade/chuanliu-dao" : 1,
	]));

        set("outdoors", "峨眉山");
        setup();
}
