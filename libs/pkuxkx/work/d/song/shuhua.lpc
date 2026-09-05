// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "翰林书画院");
	set("long", @LONG
这里是翰林书画院，负责一些书画的收藏。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"hanlin",
	]));
	set("at_hangzhoupalace",1);
	setup();
}

void init()
{
	add_action("do_find","find");
}

int do_find()
{
	object me=this_player(),thing;
	if (me->query_temp("songtasks/hanlin/task")!=1)
	return 0;
	if (me->query_temp("songtasks/hanlin/got_painting"))
	{
		tell_object(me,"你已经拿过了书画，快去送给官家吧。\n");
		return 1;
	}
	if (random(100)>49)
	thing=new("/d/guiyunzhuang/obj/guwan");
	else
	thing=new("/d/guiyunzhuang/obj/zihua");
	thing->set("owner",me->query("id"));
	thing->set("no_sell_in_playershop",1);
    thing->set("SONG_PAINTING",1);
	thing->set("no_store",1);
    thing->move(me);
	me->set_temp("songtasks/hanlin/got_painting",1);
    message_vision("$N从书架上取了一套"+thing->name()+"。\n",me);
	return 1;
}