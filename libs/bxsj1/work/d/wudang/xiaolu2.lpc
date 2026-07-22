// xiaolu1.c 林间小径
// by shang 97/6

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"小径"NOR);
	set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶声
和鸟鸣声，听不到别的动静。
LONG
	);
	set("outdoors", "武当");

	set("exits", ([
		"south" : __DIR__"yuanmen",
		"north" : __DIR__"xiaolu1",
	]));

	setup();
}

int get_object(object ob)
{
	return (userp(ob));
}

int valid_leave(object me, string dir)
{
	object *ob, *inv;
	mapping myfam;
	myfam =( mapping)me->query("family");

	inv = deep_inventory(me);
	if (dir == "south"){
		if (!userp(me) && me->query("hbtarget"))
			return notify_fail("\n");
		write("南面是一条小径，两旁种满了竹子，修篁森森，绿荫满地。\n");
		ob = filter_array(inv,(:get_object:));        
		if (me->query_condition("killer") && me->query("family/family_name") != "武当派") ;
		else if (myfam && myfam["family_name"] =="武当派" && myfam["generation"] == 2 && ! sizeof(ob))
			write("由于你走惯了这条小径，所以信步走出了竹林。\n");
		else {
			tell_room(environment(me), me->name()+"往南面的"YEL"小径"NOR"快步离开。\n"NOR, ({ me }));
			me->move(__DIR__"xiaolu3");
			tell_room(environment(me), me->name()+"从"YEL"小径"NOR"快步走了过来。\n"NOR, ({ me }));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
