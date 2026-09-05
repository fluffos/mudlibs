// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "军器监库房");
	set("long", @LONG
这里是将军器监的库房。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : __DIR__"junqijian",
	]));
	set("at_hangzhou",1);
	setup();
}

void init()
{
    add_action("do_find","find");
}

int do_find()
{
    object me=this_player(),tu;
    if (me->query_temp("songtasks/junqi/task")!=2)
    {
        return 0;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("songtasks/junqi/found"))
    {
        tell_object(me,"你已经拿到草图，赶紧送交(deliver)到城北作坊吧。。\n");
        return 1;
    }
    tu=new("/d/song/obj/draft");
	tu->move(me);
	tu->set("owner",me);
	me->set_temp("songtasks/junqi/found",1);
    return 1;
}