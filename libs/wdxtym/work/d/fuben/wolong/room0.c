// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
这里就是卧龙堡的大门，据说里面聚集着许多高手，堡主周啸天当年闯荡江湖，结了许多的恩仇，最后归隐在此处。大门边上守卫着几个精神抖擞的庄丁。
LONG
	);
	set("exits", ([
		"south" : __DIR__"enter",
		"north" : __DIR__"room1",
	]));
	set("objects", ([
		__DIR__"npc/zhuangding": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("zhuang ding", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "north")) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"对你大吼道：找死！吃了熊心豹子胆，居然擅闯卧龙堡？\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
#include "/d/fuben/room_fb.h"