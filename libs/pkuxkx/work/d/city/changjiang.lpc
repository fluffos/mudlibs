// 长江天险
// edit: by zine Sep 2 2010

inherit __DIR__"skfroom1";
#include <ansi.h>


void create()
{
	set("short", "长江天险");
	set("long", @LONG
你历尽险阻来到这里，却被一条大江(river)挡住了去路。江边停着一条破
船(chuan)。
LONG
	);
	set("exits", ([ 
	]));
	set("item_desc", ([
		"river" : "长江形胜，自古就是天险。朝廷为阻女真人南下，以下令收缴长江沿岸渡船。\n", 
		"chuan" : "这是一条破船，你可以上(shang)船横渡长江。\n",
	]));
	set("no_task",1);
	setup();
	::create();
}

void init()
{
	object me=this_player();
	add_action("do_xiang", "xiang");
	add_action("do_zhan", "refuse");
	add_action("do_shang", ({ "shang" }));
	if (me->query_temp("skf/qingbing3"))
	call_out("message1",3,me);
	::init();
	return;
}

int bonus(object me)
{
	int skftime;
	if (me->query("skfjob_last_time"))
	skftime=time()-(me->query("skfjob_last_time"));
	if (skftime<0)
	{
		me->add_temp("skf/credit",-5);
	}
	if (skftime>=0)
	{
		me->add_temp("skf/credit",5);
	}
	if (skftime>=60)
	{
		me->add_temp("skf/credit",5);
	}
	if (skftime>=120)
	{
		me->add_temp("skf/credit",5);
	}
	if (skftime>=180)
	{
		me->add_temp("skf/credit",5);
	}
	if (skftime>=240)
	{
		me->add_temp("skf/credit",5);
	}
	me->add("score",10);//暂时奖励
	me->delete_temp("skf");
    me->delete("skf/jobasked");
	me->set_temp("skf/canceltimeup",1);
	return 1;	
}

int punish(object me) //渡江投降处罚
{
}
int dujiang(object me,object nm)
{
	me->set_temp("skf/djstart",1);
	if(objectp(nm)) 
	destruct(nm);
	if(random((int)me->query("kar"))<((int)me->query("kar")-3)||random(100)<65)
	{
		tell_object(me,WHT"你让难民先爬上渡船，当你再登船时，小船一晃，几乎要倾覆。看来这条小船只能容纳一个人。\n"NOR);
		tell_object(me,HIY"你咬了咬牙，突然发力一推船边，渡船向长江深处飘去。\n"NOR);
		tell_object(me,HIY"难民大惊，“义士，你不跟我一起走吗？”\n"NOR);
		tell_object(me,HIY"你答道：“鞑子逼近，我且拖他们一拖。你先走，我马上就来。”\n"NOR);
		tell_object(me,HIY"难民嚎啕大哭起来。\n"NOR);
		tell_object(me,HIY"渡船渐渐远去，女真骑兵的马蹄声越来越近。\n"NOR);
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s大仁大义，掩护扬州难民渡江，只身留下对抗敌军，此义举必留名于青史。\n", me->query("name")));
		me->add_busy(random(3));
		me->add_temp("skf/credit",20);
		call_out("qbarrive",6,me);
	}
	else
	{
		tell_object(me,WHT"你和难民爬上渡船，用浸过水的竹竿作桨，撑起渡船，越划越远。\n"NOR);
		tell_object(me,HIY"你们来到了长江南岸。\n"NOR);
		me->add_busy(random(3));
		me->add_temp("skf/credit",20);
		me->add("zhusantimes",1);
		bonus(me);
		this_player()->move("/d/suzhou/road1");
		tell_object(me,"难民对你拱了拱手，多谢义士一路相送，我们后会有期。\n");
		tell_object(me,"难民转身离开。\n");
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s大智大勇，掩护扬州难民全身而退，此义举必留名于青史。", me->query("name")));
		call_out("aftereffect",2,me);
	}
	return 1;
}
int do_shang()
{	
	object me = this_player();
	object nm=me->query_temp("skf/nanmin");
	me->set_temp("skf/canceltimeup",1);
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
    if (me->query_temp("skf/djstart"))
	return notify_fail("渡船已经离开，你尽快准备和女真铁骑决一死战吧。\n");
	if(me->query_temp("skf/rabbit"))
	{
		dujiang(me,nm);
	}
	else if (!present("zhuzi", me))
	{
		tell_object(me,"有船无桨，还是过不了长江。\n");
		tell_object(me,"也许拆开竹筏，你们两人或可用竹筏作桨，横渡长江。\n");
		tell_object(me,"那么先把竹筏拆(chai)开吧。\n");
		me->set_temp("skf/zhufapass",1);
	}
	else
	{
		dujiang(me,nm);
	}
	return 1;
}

int message1(object me)
{
	tell_object(me,"你望着竹筏，不禁仰天长叹，要用竹筏渡江，未免也太儿戏了。\n");
	tell_object(me,"江边的渡船旧了点，但也许可以派上用场。\n");
	return 1;
}
int me_exist(object me)
{
	if (!me||environment(me)!=this_object())
	{
		return 0;
	}
	return 1;
}
int qbarrive(object me)
{
	if (!me_exist(me))
	return 1;
	message_vision(HIR"女真骑兵逼近五里以内了。\n"NOR,me);
	call_out("qbarrive2",3,me);
	return 1;
}

int qbarrive2(object me)
{
	if (!me_exist(me))
	return 1;
	message_vision(HIR"女真骑兵逼近一里以内了。\n"NOR,me);
	call_out("qbarrive3",3,me);
	return 1;
}

int qbarrive3(object me)
{
	if (!me_exist(me))
	return 1;
	message_vision(RED"女真骑兵已经把这里包围了。\n"NOR,me);
	call_out("theend",2,me);
	return 1;
}
int xiang(string arg,object me)
{
	if (arg=="xiang")
	{
		remove_call_out("over");
		message_vision("$N对女真铁骑屈膝投降了！\n",me);
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s贪生怕死，竟然对女真铁骑屈膝投降了！\n", me->query("name")));
		me->delete_temp("skf");
		me->add("skfxiang",1);
		me->set_temp("skf/cancaltimeup2",1);
		me->move("/d/city/beimen");//应该move除军营外北侠任何一个地点
		punish(me);
	}
	else
	{
		message_vision("$N露出坚毅的目光，决定和女真骑兵决一死战。\n",me);
		me->set_temp("skf/refuse",1);
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s决定在长江天险处于女真骑兵决一死战。\n", me->query("name")));
	}
	return 1;
}
int theend(object me)
{
	object zz;
	if (!me_exist(me))
	return 1;
	zz=present("zhuzi",me);
	tell_object(me,HIW"你现在可以选择投降(xiang)或者不投降(refuse)。\n"NOR);
	tell_object(me,HIW"你不尽快做出选择马上女真骑兵就要放箭了。\n"NOR);
	if(objectp(zz)) 
	destruct(zz);
	me->set_temp("skf/zhanxiang",1);
	me->add("zhusantimes",1);
	tell_object(me,"是战是降，总得有个分说。(xiang/refuse)\n");
	input_to((:xiang:),me);
	call_out("over",2,me);
	return 1;
}

int over(object me)
{
	object qb;
	if (!me_exist(me))
	return 1;
	for (int i=0;i<10;i++)
	{
		qb=new("/d/city/npc/qingbing");
		qb->move(this_object());
	}
	if (!me->query("biography/jobs/skf"))
	{
		me->set("biography/jobs/skf",time());//个人传记记录第一次完成任务时间ZINE
	}
    me->set_temp("last_damage_from",qb);
	me->start_busy(2);
	return 1;
}
int aftereffect(object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
	tell_object(me,HIG"护送民众过江之后，你决定回到扬州帮史督师抗敌。\n"NOR);
	tell_object(me,"这时更多的民众从北面进入苏州城，其间更有溃散的明军。\n");
	tell_object(me,"你不禁心中生疑，上前找了一位老汉打听扬州的情况。\n");
	call_out("aftereffect2",2,me);
	return 1;
}

int aftereffect2(object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
	tell_object(me,"老汉带着哭腔道：“扬州没了，鞑子进城了，满城都是火和血！”\n");
	tell_object(me,"你紧紧抓住老汉的手，问道：“史督师呢？”\n");
	tell_object(me,HIR"老汉道：“没有督师殿后，大家都逃不出来。督师殉国了！！”\n"NOR);
	tell_object(me,"你听罢，只觉得一阵天昏地暗，恨不得立刻杀回扬州，和鞑子决一死战。\n");
	tell_object(me,"老汉和旁边众人死死拉住你，君子报仇，十年不晚，现在去送死岂不辜负督师一番苦心？\n");
	tell_object(me,HIC"督师的样貌似乎在天际出现，你暗暗发誓，大明子民的血债一定要鞑子们血偿。\n"NOR);
	return 1;
}

