// /d/miaojiang/slu1.c

#include <ansi.h>
#include <wanted.h>
inherit ROOM;

void create()
{
        set("short", "山脚");
        set("long", @LONG
这里是山脚下的一块空地，旁边竖立着一块牌子(paizi)。有两名五毒教的教
众在这里看守。北面的高坡就是五毒教的禁地，任何人都不敢进去。
LONG
        );
	set("exits", ([
		"northup" : __DIR__"slu2",
		"east" : __DIR__"jiedao4",
		"northwest" : __DIR__"shanlu",
	]));
	set("item_desc", ([
		"paizi" : HIR "五毒教禁地，擅闯者，死！\n"NOR,
	]));
	set("objects",([
		__DIR__"npc/jiaozhong1" : 2,
		__DIR__"npc/qiyunao" : 1,
	]));
	set("outdoors", "苗疆");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && is_wanted(me))
		return 0;
	if (me->query("family/family_name") != "五毒教"
	&& present("wudujiao dizi", environment(me))
	&& dir =="northup")
		return notify_fail("五毒教众厉声喝到，五毒禁地，擅闯者死。\n");
	return ::valid_leave(me, dir);
}
