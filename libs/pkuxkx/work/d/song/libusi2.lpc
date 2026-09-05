// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "司勋司衙门");
	set("long", @LONG
这里是司勋司的衙门。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","libu");
	set("exits", ([
		"northwest" : __DIR__+query("yamen")+"court",
	
	]));
	setup();
}
void init()
{
	add_action("do_chaxun","chaxun");
	add_action("do_fa","fa");
}
int suici(object me,object pl)
{
	object baoshi;
	string gem;
	int grade,i;
	i = random(20);
	baoshi= new("/obj/gem/gem");
	if (i < 3) gem = "yan";
	else if (i < 6) gem = "mu";
	else if (i < 9) gem = "sui";
	else if (i < 12) gem = "jin";
	else if (i < 15) gem = "bing";	
	else if (i < 16) gem = "gu";
	else if (i < 17) gem = "yu";
	else if (i < 18) gem = "jiao";
	else gem = "jia";
	if (pl->query("song/juewei_1"))
	{
		baoshi->set_level(9816,9999,gem);
	}
	else if (pl->query("song/juewei_2"))
	{
		baoshi->set_level(9446,9999,gem);
	}
	else
	{
		baoshi->set_level(8336,9999,gem);
	}
	baoshi->move(pl);
	CHANNEL_D->do_channel(this_object(), "dasong", pl->query("name")+"受岁赐宝石一枚。", -1);
	tell_object(pl,HIY+me->query("name")+HIY+"代表朝廷岁赐"+baoshi->query("name")+HIY+"一枚予你。\n"NOR);
	return 1;
}
int do_fa(string arg)
{
	object me=this_player(),pl;
	string *ids;
	if (me->query_temp("songtasks/libu/task")!=3)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libucourt");
		return 1;
	}
	if (me->query_temp("songtasks/libu/3/finish"))
	{
		write(HIG+"既然以及做完勋爵的岁赐，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (!me->query_temp("songtasks/libu/chaxun_finish"))
	{
		write("你连查都不查就发出岁赐？当国库是你家开的啊？\n");
		return 1;
	}
	if (!me->query_temp("songtasks/libu/xuejue"))
	{
		write("按例今年无人可获得岁赐，你要发给谁？\n");
		return 1;
	}
	if (!arg)
	{
		write("你要发岁赐给谁？\n");
		return 1;
	}
	ids=me->query_temp("songtasks/libu/xuejue");
	if (member_array(arg,ids)==-1)
	{
		write(arg+"在岁赐名单中吗？\n");
		return 1;
	}
	if (!pl=find_player(arg))
	{
		write(arg+"已经离开了，他的岁赐就省下了。\n");
		ids-=({arg});
		me->set_temp("songtasks/libu/xuejue",ids);
		return 1;
	}
	suici(me,pl);
	ids-=({arg});
	if (sizeof(ids)<1)
	{
		me->set_temp("songtasks/libu/3/finish",1);
		write(HIG+"勋爵的岁赐发放完毕，你可以回去复命了。\n"+NOR);
		return 1;
	}
	me->set_temp("songtasks/libu/xuejue",ids);
	return 1;
}
int do_chaxun()
{
	object me=this_player();
	object *ob;
	string *names=({}),*ids=({}),msg;
	int i,count=0;
	if (me->query_temp("songtasks/libu/task")!=3)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libucourt");
		return 1;
	}
	if (me->query_temp("songtasks/libu/3/finish"))
	{
		write(HIG+"既然以及做完勋爵的岁赐，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (me->query_temp("songtasks/libu/chaxun_finish"))
	{
		write("你不是已经查完了吗？快点发(fa)出岁赐吧。\n");
		return 1;
	}
	ob = DASONG_D->song_players();
	ob = filter_array(ob, (: $1->query("song/xunjue") :) );
	me->set_temp("songtasks/libu/chaxun_finish",1);
	if (!sizeof(ob))
	{
		write("你发现按例居然没有勋爵可以享有岁赐，没想到这么容易完成了任务，回去复命吧。\n");
		me->set_temp("songtasks/libu/3/finish",1);
		return 1;
	}
	msg=(HIW+"你发现如下官员按例应发放岁赐：");
	for (i=0;i<sizeof(ob);i++)
	{
		if (ob[i]==me)
		{
			continue;
		}
		if (time()-ob[i]->query("song/xunjue_suici")>3600*24)
		{
			names+=({ob[i]->query("name")});
			msg+=(ob[i]->query("name")+"("+capitalize(ob[i]->query("id"))+")"+" ");
			ids+=({ob[i]->query("id")});
			ob[i]->set("song/xunjue_suici",time());
			count=1;
		}
	}
	if (count==0)
	{
		write("你发现按例居然没有勋爵可以享有岁赐，没想到这么容易完成了任务，回去复命吧。\n");
		me->set_temp("songtasks/libu/3/finish",1);
		return 1;
	}
	me->set_temp("songtasks/libu/xuejue",ids);
	msg+=("\n那就赶紧发放(fa <id>)下去吧。\n");
	tell_object(me,msg);
	return 1;
}