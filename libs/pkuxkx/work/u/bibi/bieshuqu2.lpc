// /d/xinfang/bieshuqu.c
//
// Created by bibi
// Modified by pretty (09/18/98)
// Rewritten by bibi (12/01/98) for married couple :-))

#include <ansi.h>

inherit ROOM;

void enter_lover_room(string,object);
void create()
{
	set("short",GRN"花园别墅区"NOR);
	set("long","这里就是著名的"GRN"花园别墅区"NOR"，很多人都在这里买了自己的房子！\n"
                "看着一幢幢的新房，真是让人心动，自己也想买一套新房住！\n"
	);
//	set("valid_startroom",);
//	set("sleep_room",1);

	set("exits", ([
		"east" : "/d/city/nandajie3",
	]));

	setup();
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{ 
	object room, me;

	me = this_player();

	if (!arg)
	{
		write("你要进入哪间房？\n");
		return 1;
	}

	if (arg==me->query("id"))
	{
		if (undefinedp(me->query("myroom")))
		{
			write("你还没有自己的房间!\n"); 
			return 1;
		}
		if ( !objectp(room = me->query_temp("xinfang")) )
		{
			room=new("/u/bibi/xinfang2");
			me->set_temp("xinfang", room);
		}
		message("vision", me->name() + "进入了自己的房间。\n",
			environment(me), ({ me }) );
        
		me->move(room);
		return 1;
	}
	else if( arg == me->query("marry/lover") )
	//确实是要进入爱人的房间么?
	//好,我们按照这个假设进行
	{ 
		enter_lover_room(arg,me);
		return 1;
	}
	else
	{
		if (arg!=me->query_temp("invited"))
		{
			write("你并没有受到主人的邀请！\n");
			return 1;
		}
		else if (!find_player(arg)||undefinedp(environment(find_player(arg))->query("owner"))||environment(find_player(arg))->query("owner")!=find_player(arg)->query("id"))
		{
			write("可惜主人不在家，没有人给你开门！\n" );
			return 1;
		}
		else 
		{
			message("vision", me->name() + "应邀走进了"+find_player(arg)->query("name")+"的房间。\n",
				environment(me), ({ me }) );
         
			me->move(environment(find_player(arg)));

			tell_room(environment(me),me->query("name")+"走了进来！\n",({me}));        
			return 1;
		}
	}
}


void enter_lover_room(string lover_id,object me)
{
	object room;	
	object lover;
	if(!find_player(lover_id))
	{
		//爱人不在线,怎么办呢?
		//以后加从data中取数据
		return;
	}
	else
	{
		lover=find_player(lover_id);
		if ( !objectp(room = lover->query_temp("xinfang")) )
		{
			room=new("/u/bibi/xinfang2");
			room->set("owner",lover_id);
			room->set("short",lover->query("name")+"的甜蜜小屋");
			lover->set_temp("xinfang", room);
		}
		message("vision", me->name() + "进入了爱人的房间。\n",
			environment(me), ({ me }) );    
		me->move(room);
		return ;
	}
}	