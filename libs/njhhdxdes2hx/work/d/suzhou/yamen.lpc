// Room: /d/suzhou/yamen.c
//by dwolf
//97.11.4 

#include <ansi.h>         
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"衙门大门"NOR);
        set("long", @LONG
	这里是衙门大门，两扇朱木大门紧紧关闭着。你四处望望"肃静"."回避"的牌
子分放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门
前巡逻。
LONG
	);

	set("exits", ([
		"south" : __DIR__"eroad2",
		"north" : __DIR__"ymzting",
	]));        
	create_door("north", RED"朱木大门"NOR, "south", DOOR_CLOSED);

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && me->query("family/family_name")!="朝廷" && objectp(present("ya yi", environment(me))) && dir == "north")
		return notify_fail(YEL"衙役喝道：“威……武……。”\n"NOR);
	return ::valid_leave(me, dir);
}
