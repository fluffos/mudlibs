// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "七怪住所");
	set("long", @LONG
这里是江南七怪在大漠的居所，七怪平时指点郭靖武功，这时却不知身在何
处。
LONG
	);

	set("exits", ([
		"south" : __DIR__"kongdi",
	]));
	set("objects", ([
    //    	__DIR__"obj/ba" : 1,
	]));
	set("no_robber",1);
    set("outdoors", "menggu_e");
	setup();
}

int leave(object me)
{
	if (!me)
	{
		return 1;
	}
	if (userp(me))
	{
		me->move("/d/menggu/kongdi");
	}
	destruct(this_object());
	return 1;
}

int byebye(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	a->byebye(me);
	message_vision(RED+"想到要和朝夕相处的师父分别，$N眼眶一红。\n"+NOR+"七侠说走立刻就走了。\n"+NOR,me);
	tell_object(me,HIC+"你觉得也是时候和大汗辞行了。\n"+NOR);
	destruct(a);
	destruct(b);
	destruct(c);
	destruct(d);
	destruct(e);
	destruct(f);
	me->set_temp("shediaoquest/zjk/farewell",1);
	this_object()->delete("chit");
	return 1;
}
int bye6(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	f->bye(me);
	call_out("byebye",1,a,b,c,d,e,f,me);
	return 1;
}
int bye5(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	e->bye(me);
	call_out("bye6",2,a,b,c,d,e,f,me);
	return 1;
}
int bye4(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	d->bye(me);
	call_out("bye5",1,a,b,c,d,e,f,me);
	return 1;
}
int bye3(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	c->bye(me);
	call_out("bye4",1,a,b,c,d,e,f,me);
	return 1;
}
int bye2(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	b->bye(me);
	call_out("bye3",1,a,b,c,d,e,f,me);
	return 1;
}

int bye(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	message_vision("七侠又和$N闲话了一些家常。\n",me);
	a->bye(me);
	call_out("bye2",1,a,b,c,d,e,f,me);
	return 1;
}

int chit6(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	f->hello(me);
	call_out("bye",3,a,b,c,d,e,f,me);
	return 1;
}
int chit5(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	e->hello(me);
	call_out("chit6",2,a,b,c,d,e,f,me);
	return 1;
}
int chit4(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	d->hello(me);
	call_out("chit5",2,a,b,c,d,e,f,me);
	return 1;
}
int chit3(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	c->hello(me);
	call_out("chit4",1,a,b,c,d,e,f,me);
	return 1;
}
int chit2(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	b->hello(me);
	call_out("chit3",1,a,b,c,d,e,f,me);
	return 1;
}
int chit(object a,object b,object c,object d,object e,object f,object me)
{
	if (!me||!a||!b||!c||!d||!e||!f)
	{
		tell_room(this_object(),"话别的场面被破坏了。\n");
		leave(me);
		return 1;
	}
	a->hello(me);
	call_out("chit2",1,a,b,c,d,e,f,me);
	return 1;
}
void init()
{
	object me=this_player(),a,b,c,d,e,f;
	if (!me->query("shediaoquest/dmfy")||me->query("shediaoquest/zhebie")!=3||!me->query("shediaoquest/shediao")||me->query("shediaoquest/mayu")!=2||me->query("shediaoquest/jdfm")!=2)
	{
		return;
	}
	if (this_object()->query("chit"))
	{
		return;
	}
	if (me->query_temp("shediaoquest/zjk/farewell"))
	{
		return;
	}
	a=new(__DIR__"npc/kezhene");
	a->move(this_object());
	b=new(__DIR__"npc/zhucong");
	b->move(this_object());
	c=new(__DIR__"npc/hanbaoju");
	c->move(this_object());
	d=new(__DIR__"npc/nanxiren");
	d->move(this_object());
	e=new(__DIR__"npc/quanjinfa");
	e->move(this_object());
	f=new(__DIR__"npc/hanxiaoying");
	f->move(this_object());
	message_vision("$N发现七侠正在这里休息，忙将受到成吉思汗封赏为金刀驸马的消息告诉了七侠。\n",me);
	this_object()->set("chit",1);
	call_out("chit",1,a,b,c,d,e,f,me);
	return;
}