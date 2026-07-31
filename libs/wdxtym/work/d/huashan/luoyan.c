#include <room.h>
inherit ROOM;
void create()
{
	set("short", "落雁峰");
	set("long", @LONG
南峰又名落雁峰，是华山最高峰。峰头题刻极多，如“太华峰头”、“竣
极于天”、“袖拂天星”等，极言华岳之高。环顾四周，皆在足下。
LONG
	);
	set("objects", ([
		CLASS_D("huashan") + "/feng" : 1,
	]));
	set("action_list", ([
		"向风请教":"ask feng qingyang about 破剑式",
	]));
	set("exits", ([
		"northdown" : __DIR__"zhandao",
	]));
	set("outdoors", "huashan");
	setup();
}
