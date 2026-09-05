// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，有的
独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地注意着四
周。看到你进来，他们全都向你包围了过来，形势看来不太妙。南边有一个门(door)。
LONG);

	set("item_desc", ([
		"men" : "这是一扇极厚的铁门。\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));

	set("objects", ([
		__DIR__"npc/shi" : 1,
                "d/city/npc/wujiang1"+random(2) : 1,
                "d/city/npc/wujiang2"+random(2) : 1,
		__DIR__"npc/bing" : 6,
	]));

	create_door("south", "铁门", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

	if( dir != "south" || me->query("class") == "officer" )
		return ::valid_leave(me, dir);
	ob = all_inventory( environment( me ));
	for(i=0; i<sizeof(ob); i++) 
	{
		if( living(ob[i]) && ob[i]->query("id") == "guan bing" )
			return notify_fail("官兵们拦住了你的去路\n");
	}
	return ::valid_leave(me, dir);
}
