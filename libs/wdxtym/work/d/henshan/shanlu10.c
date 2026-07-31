// Room: /d/henshan/shanlu10.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。山路向西通向方广寺。东面是天柱峰。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "eastup"    : __DIR__"tianzhu",
	   "westdown"  : __DIR__"fangguangsi",
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	setup();
}

