//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "寨前广场");
        set("long", @LONG
这是鸡笼山上一处山寨寨前的一大片空地，前来剿匪的人在此集结。
LONG
        );
        set("exits", ([
               //"southwest" : __DIR__"guandaosd2",
               //"west" : __DIR__"tulue2",
               //"southeast" : __DIR__"tulue3",
               "out" : __DIR__"jilong",
               //"" : __DIR__"jlsw2",
        ]));
		set("no_task",1);
        set("outdoors", "yingtianfu");
        setup();
        
}
void init()
{
	add_action("do_ready","ready");
	add_action("rejoin","rejoin");
}
int do_ready()
{
	object me=this_player(),*team,room;
	if (!me->query_temp("OustBandit/start"))
	return 0;
	if (!team=me->query_temp("OustBandit/team"))
	return 0;
	if (!arrayp(team))
	return 0;
	message_vision(HIR+"$N"+HIR+"向队友们说：“我准备好了。”\n"+NOR,me);
	if (sizeof(team)<3||sizeof(team)>5)
	{
		write("你的队伍数目不符合清剿山寨任务的条件。\n");
		return 1;
	}
	for (int i=0;i<sizeof(team);i++)
	{
		if (!team[i])
		{
			write("你队伍中有人擅自离开了，任务取消！\n");
			return 1;
		}
		if (environment(team[i])!=this_object())
		{
			write(team[i]->query("name")+"不在这里，任务无法继续。\n");
			return 1;
		}
		if (!team[i]->query_temp("OustBandit/psw")||!team[i]->query_temp("OustBandit/start"))
		{
			write("你队伍中有人擅自离开过，任务取消！\n");
			return 1;
		}
		if (time()-team[i]->query("OustBandit/Last_Time")<7200&&team[i]->query("OustBandit/times")>9)
		{
			write(team[i]->query("name")+"距离上次完成时间太短，任务取消！\n");
			return 1;
		}
		if (team[i]->query("OustBandit/times")>19)
		{
			write("队员"+team[i]->query("name")+"今天已经参加过太多次清剿山寨任务。\n");
			return 1;
		}
	}
	room=new(__DIR__"jilong_shijie");
	room->set("Owner",team);
	room->set("exits/down",this_object());
	room->Gen(this_object(),sizeof(team));
	for (int i=0;i<sizeof(team);i++)
	{
		tell_object(team[i],"\t\t\t"+HIR+"===清剿山寨任务开启===\n\n\n"+NOR);
		team[i]->move(room);
		team[i]->set_temp("OustBandit/Origin",room);
		team[i]->set_temp("OustBandit/size",sizeof(team));
		team[i]->set("OustBandit/Last_Time",time());//前面要加判断
		team[i]->add("OustBandit/times",1);
	}
	return 1;
}

int rejoin()
{
	object me=this_player(),room;
	if (!me->query_temp("OustBandit/Origin")) return 0;
	if (!objectp(room=me->query_temp("OustBandit/Origin"))) return 0;
	if (!room->isroom()) return 0;
	if (me->move(room))
	message_vision("$N充满信心，重装上阵。\n",me);
	else
	write("似乎有什么不对劲，让你无法再次杀入山寨。\n");
	return 1;
}

