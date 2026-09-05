// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
string look_longgu();
void create()
{
	set("short", "水师造船厂");
	set("long", @LONG
这里是大宋水师的船厂，战舰的龙骨(longgu)停在船坞中。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"shuishi",
		//"east" : __DIR__"qiantang2",
		//"southwest" : __DIR__"qiantang",//吏部
		"south" : __DIR__"shuishi",//礼部
	]));
	set("item_desc",([
		"longgu" : (:look_longgu:),
	]));
	set("objects", ([
         // "/d/hangzhou/npc/songbing_y" : 2,
		//__DIR__"npc/shuidu":1,
        ])); 
	set("at_hangzhou",1);
	setup();
}
void init()
{
	add_action("do_action","action");
}
string get_tick(object me,int flag,int flag2)
{
	int no;
	string *steps=({"上帆","刷漆","蒙皮","装上压舱物"});
	if (member_array(me->query_temp("songtasks/shuishi/step"+flag),steps)!=-1)
	{
		no=member_array(me->query_temp("songtasks/shuishi/step"+flag),steps)+1;
	}
	if (no==flag2)
	return "√";
	else
	return "";
}
string look_longgu_detail(object me)
{
	string step,*steps=({"上帆","刷漆","蒙皮","装上压舱物"}),msg;
	int n=18+random(10);
	if (me->query_temp("songtasks/shuishi/sche"))
	{
		tell_object(me,me->query_temp("songtasks/shuishi/sche"));
		return "你必须按上述步骤执行。\n";
	}
	for (int i=1;i<=4;i++)
	{
		step=steps[random(sizeof(steps))];
		steps-=({step});
		me->set_temp("songtasks/shuishi/step"+i,step);
	}
	msg="\n\n";
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n","","上帆","刷漆","蒙皮","装上压舱物");
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n","第一步",get_tick(me,1,1),get_tick(me,1,2),get_tick(me,1,3),get_tick(me,1,4),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n","第二步",get_tick(me,2,1),get_tick(me,2,2),get_tick(me,2,3),get_tick(me,2,4),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n","第三步",get_tick(me,3,1),get_tick(me,3,2),get_tick(me,3,3),get_tick(me,3,4),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n","第四步",get_tick(me,4,1),get_tick(me,4,2),get_tick(me,4,3),get_tick(me,4,4),);
	tell_object(me,msg);
	me->set_temp("songtasks/shuishi/sche",msg);
	return "你必须按上述步骤执行。用action 命令进行，比如action 上帆。\n";
}
int do_action(string arg)
{
	object me=this_player();
	string *steps=({"上帆","刷漆","蒙皮","装上压舱物"});
	if (me->query_temp("songtasks/shuishi/3/finish"))
	{
		return notify_fail("督造战舰已经完成了，你快回去复命吧。\n");
	}
	if (me->query_temp("songtasks/shuishi/task")!=3)
	{
		return 0;
	}
	if (!me->query_temp("songtasks/shuishi/sche"))
	{
		return notify_fail("你看都不看就自己乱来？\n");
	}
	if (!arg||member_array(arg,steps)==-1)
	{
		return notify_fail("你不知道该干什么，就再看看龙骨吧。\n");
	}
	if (arg==me->query_temp("songtasks/shuishi/step"+(me->query_temp("songtasks/shuishi/stepcheck")+1)))
	{
		me->add_temp("songtasks/shuishi/stepcheck",1);
		tell_object(me,"你做对了第"+chinese_number(me->query_temp("songtasks/shuishi/stepcheck"))+"步。\n");
		if (me->query_temp("songtasks/shuishi/stepcheck")==4)
		{
			me->set_temp("songtasks/shuishi/3/finish",1);
			tell_object(me,"督造战舰完成了，你回去复命吧。\n");
			return 1;
		}
		return 1;
	}
	me->delete_temp("songtasks");
	tell_object(me,RED"大宋任务失败！\n"NOR);
	DASONG_D->task_finish(me,-5);
	return notify_fail("没有按照要求的步骤来，新舰船工期被你严重拖后了。\n");
}
string look_longgu()
{
	object me=this_player();
	if (me->query_temp("songtasks/shuishi/task")==3)
	{
		return look_longgu_detail(me);
	}
	else if (me->query("song/pro"))
	{
		return "几十个工匠在龙骨下忙碌着。\n"; 
	}
	else
	{
		return "水师的士兵阻止了你对待造舰船的窥探。\n";
	}
}