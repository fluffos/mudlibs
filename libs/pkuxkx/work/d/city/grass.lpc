// 草地
// edit: by zine Aug 21 2010

inherit __DIR__"skfroom1";
#include <ansi.h>
int arrest(object me);
int arrest2(object me,object nm,string place,string desc);
void create()
{
	set("short", HIG"草地"NOR);
	set("long", @LONG
一片碧绿的草地，一只小白兔在悠闲地吃着草。南面是一片池塘。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"pool",
		"southeast" : __DIR__"zhulin",
		"southwest" : __DIR__"pingtai",
		"northup" : __DIR__"milinend",	
	]));
	set("objects", ([(__DIR__"npc/rabbit") : 1,
	]));
	set("no_task",1);
	setup();
	::create();
}

int close_door()
{
	delete("exits/yuema");
	return 1;
}
int removezhui(object me)
{
	if (!me->query_temp("skf/rabbit2"))
	{
		tell_object(me,"你半天没有行动，小白兔已经跑得无影无踪了。\n");
		me-> delete_temp("skf/rabbit");
		me-> set_temp("skf/rabbitfail",1);
	}
	return 1;
}
void init()
{
	object me=this_player();
    int i;
    object *all=all_inventory(this_object());
	add_action("do_zhui", ({ "zhui" }));
	add_action("do_make", ({ "make", "zuo"}));
    if (!me->query("mingpin")&&!me->query("ming/tj/pin"))
    {
		if (!me->query_temp("skf/rabbitfail"))
		{
			if ((random(50)>33) && (userp(me)))
			{
				tell_room(this_object(),"小白兔突然跑了起来，往左一转，往右一转，很快失去了方向。\n");
				tell_object(me,HIW"你决定紧紧追(zhui)在小白兔的后面，也许能找到一条近路去桃源。\n"NOR);
				me->set_temp("skf/rabbit",1);
				call_out("removezhui",10,me);
			}
			else
			me->set_temp("skf/rabbitfail",1);
		}
	}
	else
	{
		if (me->query_temp("skf/skf2"))
		{
			message_vision(HIC"$N一声令下，渡河！大队人马开始准备纵马越过(yuema)池塘。\n"NOR,me);
			set("exits/yuema", __DIR__"changjiang-2"); 
			remove_call_out("close_door");
			call_out("close_door",60);
		}
	}
	::init();
	return;	
}

int do_zhui()
{
	if(this_player()->query_temp("skf/rabbit"))
	{
		this_player()->set_temp("skf/canceltimeup",1);
		this_player()->set_temp("skf/qingbing3",1);
		this_player()->set_temp("skf/rabbit2",1);
		this_player()->add_temp("skf/credit",8);
		tell_object(this_player(),"你和难民紧紧跟着小白兔一路跑去。\n");
		call_out("arrest",2,this_player());
	}
	else
	{
		tell_object(this_player(),"你是来护送难民去桃源避难的，没事追兔子干嘛？\n");
	}
	return 1;
}

int arrest(object me)
{
	int i;
	object* all = all_inventory(),pl;
	for(i=0;i<sizeof(all);i++)
	{
		if(!objectp(all[i])) continue;
		if(!living(all[i])) continue;
		if(all[i]->query("skfleader")==me->query("id"))
		{
			pl=all[i];
			pl->move(__DIR__"shanjian");
			break;
		}
	}
	me->move(__DIR__"shanjian");
	tell_object(me,"你和难民越过山涧，紧紧跟着小白兔。\n");
	call_out("arrest2",2,me,pl,__DIR__"xiaoshan","一座小山前");
	return 1;
}

int arrest2(object me,object nm,string place,string desc)
{
	nm->move(place);
	me->move(place);
	tell_object(me,"你和难民来到了"+desc+"。\n");
	if (desc=="一条大江前"&&place==__DIR__"changjiang")
	{
		return 1;
	}
	call_out("arrest2",2,me,nm,__DIR__"changjiang","一条大江前");
	return 1;
}

int dest_zhu(object me,object *zhu)
{
	for(int j=0;j<4;j++)
	{	
		if(present(zhu[j],me)) 
		destruct(zhu[j]);
	}
}

int make2(object me,object *zhu,object sheng)
{
    object zhufa;
	if (random(10)>1)
	{
		zhufa = new("/d/city/obj/rift");
		zhufa->move("/d/city/grass");
		me->add_busy(random(4));
		destruct(sheng);
		dest_zhu(me,zhu);
		message_vision("$N哼哧哼哧地把一条竹筏绑好。\n", me);
		me->add_temp("skf/credit",5);
		tell_object(me,HIY"也许你可以把竹筏推(tui)过池塘。\n"NOR);
	}
	else
	{
		me->add_busy(random(4));
		me->add_temp("skf/credit",2);
		message_vision(RED"$N一不留神，哗啦一声，竹子全部滚进了南边的池塘。\n"NOR, me);
		message_vision("$N看着手上的麻绳，一屁股坐在地上发起呆来。\n", me);
		dest_zhu(me,zhu);
	}
	return 1;
}
	
int do_make(string arg)
{
	int i,zhunum=0;
	object* bamboo=all_inventory(this_player()),*zhu=({}),sheng;
	if (this_player()->query_temp("skf/skf2"))
	return notify_fail("赶紧带大明铁骑去长江天险阻敌吧，不要再浪费时间了！\n");
	if (!arg||(arg!="zhu fa" && arg!="zhufa" && arg!="fa" && arg!="rift" && arg!="竹筏"))
	return notify_fail("你要做什么？\n");
	if(this_player()->is_busy()|| this_player()->is_fighting())
	return notify_fail("你正忙着呢。\n");
	for(i=0;i<sizeof(bamboo);i++)
	{
		if (bamboo[i]->query("is_bamboo"))
		{
			zhu+=({bamboo[i]});
			zhunum++;
		}
	}
	if(zhunum<4)
	return notify_fail("你至少需要四根大竹子才能制作竹筏。\n");
	else if(!sheng=present("ma sheng", this_player()))
	return notify_fail("你需要一根绳子把所有竹子绑起来。\n");
	else
	make2(this_player(),zhu,sheng);    
	return 1; 
}

