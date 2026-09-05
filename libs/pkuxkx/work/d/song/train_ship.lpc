// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
string look_jing();
#include <ansi.h>
void create()
{
	set("short", "轻快战舰");
	set("long", @LONG
这里是一艘轻快的战船，用来训练水师。船首架了一具千里镜(jing)。
LONG
	);
	set("outdoors", "hangzhou");
	set("objects", ([
         // "/d/hangzhou/npc/songbing_y" : 2,
		//__DIR__"npc/shuidu":1,
        ])); 
	set("item_desc",([
		"jing" : (:look_jing:),
	]));
	set("real_dark",1);
	set("at_none",1);
	setup();
}
string look_jing()
{
	object me=this_player();
	if (me->query_temp("songtasks/shuishi/task")!=4)
	return "这是一具千里镜，据说可以看到远处。\n";
	else
	return "你可以通过look <千里镜>来观察训练水域。\n";
}
string get_posi(object me,int x,int y)
{
	if (x==me->query_temp("songtasks/shuishi/train/origin_x")&&y==me->query_temp("songtasks/shuishi/train/origin_y"))
	return me->query_temp("songtasks/shuishi/train/entry_mark");
	if (x==me->query_temp("songtasks/shuishi/train/real_x")&&y==me->query_temp("songtasks/shuishi/train/real_y"))
	return me->query_temp("songtasks/shuishi/train/myself_mark");
	else if (x==me->query_temp("songtasks/shuishi/train/x")&&y==me->query_temp("songtasks/shuishi/train/y"))
	return me->query_temp("songtasks/shuishi/train/barrier_mark");
	else
	return "∞";
}
string get_tick(object me,int x,int y)
{
	if (x==me->query_temp("songtasks/shuishi/train/origin_x")&&y==me->query_temp("songtasks/shuishi/train/origin_y"))
	return me->query_temp("songtasks/shuishi/train/entry_mark");
	else if (x==me->query_temp("songtasks/shuishi/train/x")&&y==me->query_temp("songtasks/shuishi/train/y"))
	return me->query_temp("songtasks/shuishi/train/barrier_mark");
	else
	return "∞";
}
string get_detail(object me)
{
	int n=12+random(3),x,y,z;
	string msg,msg_title;
	if (me->query_temp("songtasks/shuishi/sea_introduce"))
	{
		tell_object(me,me->query_temp("songtasks/shuishi/sea_introduce"));
		return "\n";
	}
	x=1+random(9);
	y=1+random(9);
	if (random(2))
	{
		me->set_temp("songtasks/shuishi/train/origin_x",9);
		me->set_temp("songtasks/shuishi/train/origin_y",1+random(9));
		me->set_temp("songtasks/shuishi/train/entry_mark","↑");
		me->set_temp("songtasks/shuishi/train/barrier_mark","＝");
	}
	else
	{
		me->set_temp("songtasks/shuishi/train/origin_x",1+random(9));
		me->set_temp("songtasks/shuishi/train/origin_y",1);
		me->set_temp("songtasks/shuishi/train/entry_mark","→");
		me->set_temp("songtasks/shuishi/train/barrier_mark","‖");
	}
	me->set_temp("songtasks/shuishi/train/myself_mark","¤");
	while (x==me->query_temp("songtasks/shuishi/train/origin_x")&&y==me->query_temp("songtasks/shuishi/train/origin_y"))
	{
		x=1+random(9);
		y=1+random(9);
	}
	z=n*9;
	me->set_temp("songtasks/shuishi/train/real_x",me->query_temp("songtasks/shuishi/train/origin_x"));
	me->set_temp("songtasks/shuishi/train/real_y",me->query_temp("songtasks/shuishi/train/origin_y"));
	me->set_temp("songtasks/shuishi/train/x",x);
	me->set_temp("songtasks/shuishi/train/y",y);
	msg_title=sprintf("\n%|"+z+"s",HIR+"水师训练舆图"+NOR,);
	msg="\n\n";
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,1,1),get_tick(me,1,2),get_tick(me,1,3),get_tick(me,1,4),get_tick(me,1,5),get_tick(me,1,6),get_tick(me,1,7),get_tick(me,1,8),get_tick(me,1,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,2,1),get_tick(me,2,2),get_tick(me,2,3),get_tick(me,2,4),get_tick(me,2,5),get_tick(me,2,6),get_tick(me,2,7),get_tick(me,2,8),get_tick(me,2,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,3,1),get_tick(me,3,2),get_tick(me,3,3),get_tick(me,3,4),get_tick(me,3,5),get_tick(me,3,6),get_tick(me,3,7),get_tick(me,3,8),get_tick(me,3,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,4,1),get_tick(me,4,2),get_tick(me,4,3),get_tick(me,4,4),get_tick(me,4,5),get_tick(me,4,6),get_tick(me,4,7),get_tick(me,4,8),get_tick(me,4,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,5,1),get_tick(me,5,2),get_tick(me,5,3),get_tick(me,5,4),get_tick(me,5,5),get_tick(me,5,6),get_tick(me,5,7),get_tick(me,5,8),get_tick(me,5,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,6,1),get_tick(me,6,2),get_tick(me,6,3),get_tick(me,6,4),get_tick(me,6,5),get_tick(me,6,6),get_tick(me,6,7),get_tick(me,6,8),get_tick(me,6,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,7,1),get_tick(me,7,2),get_tick(me,7,3),get_tick(me,7,4),get_tick(me,7,5),get_tick(me,7,6),get_tick(me,7,7),get_tick(me,7,8),get_tick(me,7,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,8,1),get_tick(me,8,2),get_tick(me,8,3),get_tick(me,8,4),get_tick(me,8,5),get_tick(me,8,6),get_tick(me,8,7),get_tick(me,8,8),get_tick(me,8,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_tick(me,9,1),get_tick(me,9,2),get_tick(me,9,3),get_tick(me,9,4),get_tick(me,9,5),get_tick(me,9,6),get_tick(me,9,7),get_tick(me,9,8),get_tick(me,9,9));
	msg=replace_string(msg,"↑",HBBLU+HIW+"↑"+NOR);
	msg=replace_string(msg,"→",HBBLU+HIW+"→"+NOR);
	msg=replace_string(msg,"＝",HBBLU+HIR+"＝"+NOR);
	msg=replace_string(msg,"‖",HBBLU+HIR+"‖"+NOR);
	msg=replace_string(msg,"∞",HBBLU+HIB+"∞"+NOR);
	msg=replace_string(msg," ",HBBLU+" "+NOR);
	msg+="标识定义："+HIB+"∞"+NOR+"——海水	"+HIW"↑/→"+NOR+"——战船所在	"+HIR+"＝/‖"+NOR+"——目标所在\n";
	msg=msg_title+msg;
	tell_object(me,msg);
	me->set_temp("songtasks/shuishi/sea_introduce",msg);
	return "你必须使用划桨(hua)命令，接近目标，摧毁(destory)目标。\n注意接近目标的意思，是划至目标一格以内，如完全重叠，将烧毁自身，燃料有限，只能做一次摧毁，否则任务失败。\n";
}
mapping tran_dirs=(["north":"北","south":"南","east":"东","west":"西","northwest":"西北","northeast":"东北","southwest":"西南","southeast":"东南"]);
int look_map(object me)
{
	string msg,msg_title;
	int n=12+random(2);
	msg_title=sprintf("\n%|"+n*9+"s",HIR+"水域图"+NOR,);
	msg="\n\n";
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,1,1),get_posi(me,1,2),get_posi(me,1,3),get_posi(me,1,4),get_posi(me,1,5),get_posi(me,1,6),get_posi(me,1,7),get_posi(me,1,8),get_posi(me,1,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,2,1),get_posi(me,2,2),get_posi(me,2,3),get_posi(me,2,4),get_posi(me,2,5),get_posi(me,2,6),get_posi(me,2,7),get_posi(me,2,8),get_posi(me,2,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,3,1),get_posi(me,3,2),get_posi(me,3,3),get_posi(me,3,4),get_posi(me,3,5),get_posi(me,3,6),get_posi(me,3,7),get_posi(me,3,8),get_posi(me,3,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,4,1),get_posi(me,4,2),get_posi(me,4,3),get_posi(me,4,4),get_posi(me,4,5),get_posi(me,4,6),get_posi(me,4,7),get_posi(me,4,8),get_posi(me,4,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,5,1),get_posi(me,5,2),get_posi(me,5,3),get_posi(me,5,4),get_posi(me,5,5),get_posi(me,5,6),get_posi(me,5,7),get_posi(me,5,8),get_posi(me,5,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,6,1),get_posi(me,6,2),get_posi(me,6,3),get_posi(me,6,4),get_posi(me,6,5),get_posi(me,6,6),get_posi(me,6,7),get_posi(me,6,8),get_posi(me,6,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,7,1),get_posi(me,7,2),get_posi(me,7,3),get_posi(me,7,4),get_posi(me,7,5),get_posi(me,7,6),get_posi(me,7,7),get_posi(me,7,8),get_posi(me,7,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,8,1),get_posi(me,8,2),get_posi(me,8,3),get_posi(me,8,4),get_posi(me,8,5),get_posi(me,8,6),get_posi(me,8,7),get_posi(me,8,8),get_posi(me,8,9));
	msg+=sprintf("%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",get_posi(me,9,1),get_posi(me,9,2),get_posi(me,9,3),get_posi(me,9,4),get_posi(me,9,5),get_posi(me,9,6),get_posi(me,9,7),get_posi(me,9,8),get_posi(me,9,9));
	msg=replace_string(msg,"↑",HBBLU+HIW+"↑"+NOR);
	msg=replace_string(msg,"→",HBBLU+HIW+"→"+NOR);
	msg=replace_string(msg,"＝",HBBLU+HIR+"＝"+NOR);
	msg=replace_string(msg,"‖",HBBLU+HIR+"‖"+NOR);
	msg=replace_string(msg,"∞",HBBLU+HIB+"∞"+NOR);
	msg=replace_string(msg,"¤",HBBLU+MAG+"¤"+NOR);
	msg=replace_string(msg," ",HBBLU+" "+NOR);
	msg+="标识定义："+HIB+"∞"+NOR+"——海水	"+HIW"↑/→"+NOR+"——战船所在	"+HIR+"＝/‖"+NOR+"——目标所在	 "+HIM+"¤"+NOR+"——自身所在\n";
	msg=msg_title+msg;
	tell_object(me,msg);
	return 1;
}
int hua(object me,string arg)
{
	if (arg=="north")
	{
		me->add_temp("songtasks/shuishi/train/real_x",-1);
	}
	if (arg=="south")
	{
		me->add_temp("songtasks/shuishi/train/real_x",1);
	}
	if (arg=="west")
	{
		me->add_temp("songtasks/shuishi/train/real_y",-1);
	}
	if (arg=="east")
	{
		me->add_temp("songtasks/shuishi/train/real_y",1);
	}
	if (arg=="northeast")
	{
		me->add_temp("songtasks/shuishi/train/real_y",1);
		me->add_temp("songtasks/shuishi/train/real_x",-1);
	}
	if (arg=="northwest")
	{
		me->add_temp("songtasks/shuishi/train/real_y",-1);
		me->add_temp("songtasks/shuishi/train/real_x",-1);
	}
	if (arg=="southeast")
	{
		me->add_temp("songtasks/shuishi/train/real_y",1);
		me->add_temp("songtasks/shuishi/train/real_x",1);
	}
	if (arg=="southwest")
	{
		me->add_temp("songtasks/shuishi/train/real_y",-1);
		me->add_temp("songtasks/shuishi/train/real_x",1);
	}
	if (me->query_temp("songtasks/shuishi/train/real_y")==me->query_temp("songtasks/shuishi/train/origin_y")
		&&me->query_temp("songtasks/shuishi/train/real_x")==me->query_temp("songtasks/shuishi/train/origin_x"))
	{
		tell_object(me,"你划回了岸边。\n");
		me->move("/d/song/qiantang2");
		return 1;
	}
	me->add_busy(2);
	tell_object(me,"你向"+tran_dirs[arg]+"划了过去。\n");
	return 1;
}
int do_hua(string arg)
{
	object me=this_player();
	string *legal_dirs=({"north","south","east","west","northwest","northeast","southwest","southeast"});
	if (member_array(arg,legal_dirs)==-1)
	{
		tell_object(me,"划船的方向只能是north、south、east、west、northwest、northeast、southwest或是southeast。\n");
		return 1;
	}
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (me->query_temp("songtasks/shuishi/train/real_x")==9&&member_array(arg,({"south","southwest","southeast"}))!=-1)
	return notify_fail("你已经划到这块水域的边缘，不能再向"+tran_dirs[arg]+"划了。\n");
	if (me->query_temp("songtasks/shuishi/train/real_x")==1&&member_array(arg,({"north","northwest","northeast"}))!=-1)
	return notify_fail("你已经划到这块水域的边缘，不能再向"+tran_dirs[arg]+"划了。\n");
	if (me->query_temp("songtasks/shuishi/train/real_y")==1&&member_array(arg,({"west","northwest","southwest"}))!=-1)
	return notify_fail("你已经划到这块水域的边缘，不能再向"+tran_dirs[arg]+"划了。\n");
	if (me->query_temp("songtasks/shuishi/train/real_y")==9&&member_array(arg,({"east","northeast","southeast"}))!=-1)
	return notify_fail("你已经划到这块水域的边缘，不能再向"+tran_dirs[arg]+"划了。\n");
	return hua(me,arg);
}
int do_destory()
{
	object me=this_player();
	int x=me->query_temp("songtasks/shuishi/train/real_x")-me->query_temp("songtasks/shuishi/train/x"),y=me->query_temp("songtasks/shuishi/train/real_y")-me->query_temp("songtasks/shuishi/train/y");
	float distance;
	if (me->query_temp("songtasks/shuishi/task")!=4)
	return 0;
	if (me->query_temp("songtakss/shuishi/train/fired"))
	{
		tell_object(me,"船上的引火物已经用完了。\n");
		return 1;
	}
	distance=sqrt(to_float(x*x+y*y));
	if (distance<1)//烧毁自己
	{
		me->delete_temp("songtasks");
		tell_object(me,"你点燃了引火物，可是你的坐船离目标太近，也被一起引燃了。\n你拼命游回了岸边，你的任务失败了！\n");
		DASONG_D->task_finish(me,-2);
		me->move("/d/song/qiantang2");
		return 1;
	}
	if (distance>2)
	{
		me->delete_temp("songtasks");
		tell_object(me,"你点燃了引火物，可惜离目标太远，根本无法点燃目标。\n你的任务失败了，你失望的划回岸边。\n");
		DASONG_D->task_finish(me,-3);
		me->move("/d/song/qiantang2");
		return 1;
	}
	me->set_temp("songtasks/shuishi/4/finish",1);
	me->set_temp("songtakss/shuishi/train/fired",1);
	tell_object(me,"你点燃了引火物，掷向了目标，大火熊熊地燃烧起来。\n"+HIG+"你的任务完成，可以回去复命了。\n"+NOR);
	return 1;
}
int do_look(string arg)
{
	object me=this_player();
	if (arg!="千里镜"||me->query_temp("songtasks/shuishi/task")!=4)
	return 0;
	else
	return look_map(me);
}
void init()
{
	add_action("do_look",({"look","l"}));
	add_action("do_hua","hua");
	add_action("do_destory","destroy");
}