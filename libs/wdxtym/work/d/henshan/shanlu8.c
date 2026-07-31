// Room: /d/henshan/shanlu8.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。南边就是福严寺。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southup"  : __DIR__"fuyansi",
	   "northup"  : __DIR__"mojingtai",
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	setup();
}

