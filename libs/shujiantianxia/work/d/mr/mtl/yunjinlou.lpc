// /d/mr/yunjinlou.c
// update 1997.6.20 by beyond

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",MAG"云锦楼"NOR);
	set("long",@long
云锦楼陈设富丽，一副中堂绘的是孔雀开屏图，两边柱子上写了一幅对联
(duilian)。东面是一间客厅，西面是厢房，往北面走是后院，南面是后花园。
long);
	set("item_desc", ([
		"duilian" : "漆叶云差密, 茶花雪忌艳。\n"
	]));
	set("valid_startroom", 1);
	set("exits",([
		"east" : __DIR__"keting",
		"west" : __DIR__"xiangfang1",
		"south" : __DIR__"hhyuan",
		"up" : __DIR__"cangshuge",
		"north" : __DIR__"houyuan",
	]));
	set("objects",([
		__DIR__"../npc/wang" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");

        if ((!fam || fam["family_name"] != "姑苏慕容") && dir == "up"
         && objectp(present("wang furen", environment(me))))
        	return notify_fail("王夫人哼了一声：“楼上是我曼佗罗山庄的藏书阁，你也想上？\n");
	return ::valid_leave(me, dir);
}
