#include <ansi.h>
mapping depart_name=([
		"sansishi":"三司使",
		"yushitai":"御史台",
		"bingbu":"兵部",
		"gongbu":"工部",
		"libu":"吏部",
		"xingbu":"刑部",
		"hubu":"户部",
		"libu2":"礼部",
		"jianyuan":"谏院",
		"honglusi":"鸿胪寺",
		"hanlinyuan":"翰林院",
		"taiyiyuan":"太医局",
		"taichangsi":"太常寺",
		"dalisi":"大理寺",
		"zongrenfu":"宗正寺",
		"sinong":"司农寺",
		"taifu":"太府寺",
		"jiangzuo":"将做监",
		"junqi":"军器监",
		"dushui":"都水监",
		"linan":"临安府",
		"zhanshifu":"詹事府",
		"dianqian":"殿前都",
		"pengri":"捧日卫",
		"tianwu":"天武卫",
		"shenwei":"神卫",
		"longwei":"龙卫",
		"shuishi":"水师",
		"bujun":"步军都",
		"majun":"马军都",
]);
int task_finish(object me,int reward,string comment)
{
	if (DASONG_D->get_my_pin(me)!=1)
	command("say "+comment);
	else
	command("flatter "+me->query("id"));
	me->delete_temp("songtasks");
	me->add("song/total_task_finish",1);
	if (me->query("song/pro")=="文"&&DASONG_D->get_my_pin(me)!=1)
	DASONG_D->multi_record(me,1,"完成",3);
	return DASONG_D->task_finish(me,reward);
}

int task_pending(object me,object ob)
{
	if (DASONG_D->get_my_pin(me)!=1)
	command("say 你完成了吗？\n");
	else
	message_vision("$N一副欲言又止的样子。\n",ob);
	return 1;
}

string if_give_task(object me,string depart)
{
	object guanyin;
	mixed tm=localtime(time());
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	if (!me->query("song/pro")||!DASONG_D->get_my_pin(me))
	return this_object()->name()+"道：“你不是大宋的官员，别来掺和了。”\n";
	if (!me->query_temp("songtasks/"+depart+"/start")&&DASONG_D->get_my_pin(me)!=1)
    return this_object()->name()+"道：“我这里暂时没有什么事，你去别的衙门看看哪里需要帮忙吧。”\n";
    if (DASONG_D->get_my_pin(me)==1&&day!=me->query("song/1pintask/date"))
	{
		me->set("song/1pintask/date",day);
		me->set("song/1pintask/times",0);
		me->set("song/1pintask/departs",({}));
	}
	if (!me->query_temp("song_identification"))
	{
		if (me->query("song/pro")=="文"&&!guanyin=present("guan yin",me))
		return "你的官印不在，无法取信于人。\n";
		if (me->query("song/pro")=="武"&&!guanyin=present("pei jian",me))
		return "你的佩剑不在，无法取信于人。\n";
		if (me->query("song/pro")=="宦"&&!guanyin=present("fu chen",me))
		return "你的拂尘不在，无法取信于人。\n";
		if (!guanyin->is_guanyin())
		return "你的官印/佩剑/拂尘不在，无法取信于人。\n";
		me->set_temp("song_identification",guanyin);
	}
	if (DASONG_D->get_my_pin(me)==1&&me->query("song/1pintask/times")>3)
	return "今日你已经很辛苦了，明天再继续吧。\n";
	if (DASONG_D->get_my_pin(me)==1&&member_array(depart,me->query("song/1pintask/departs"))!=-1)
	return "今日你已经指导过"+depart_name[depart]+"了，再去看看其他的衙门吧。\n";
    if (me->is_busy() || me->is_fighting())
    return "你正忙着哪！\n";
    if (me->query_temp("songtasks/"+depart+"/task"))
    return "你领了任务，就赶紧去做吧。\n";
    return "approve";
}

int pre_1pin(object me,string depart,mapping *tasks)
{
	string *departs=({});
	tell_object(me,"完成"+HIR+"『"+tasks[me->query_temp("songtasks/"+depart+"/task")-1]["name"]+"』"+NOR+"任务后，你将获得大宋功勋度"+HIG+tasks[me->query_temp("songtasks/"+depart+"/task")-1]["range"]+NOR+"点。\n");
	if (DASONG_D->get_my_pin(me)!=1)
	return 1;
	tell_object(me,"作为朝廷一品大员，你将能获得150%的功勋度奖励。\n");
	if (me->query("song/1pintask/departs"))
	departs=me->query("song/1pintask/departs");
	departs+=({depart});
	me->add("song/1pintask/times",1);
	me->set("song/1pintask/departs",departs);
	command("say 恭送"+me->query("name")+"大人。");
	return 1;
}
int pre_assign(object me,string depart,mapping *tasks)
{
	string msg;
    if (if_give_task(me,depart)!="approve")
	{
		msg=if_give_task(me,depart);
		write(msg);
		return 0;
	}
    else
    {
		me->set_temp("songtasks/"+depart+"/task",random(sizeof(tasks))+1);
        return me->query_temp("songtasks/"+depart+"/task");
    }
}

int is_finish(object me,string depart,mapping *finishes)
{
    object ob=this_object();
	if (!me->query_temp("songtasks/"+depart+"/start")&&DASONG_D->get_my_pin(me)!=1)
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
	for (int i=1;i<sizeof(finishes)+1;i++)
	{
		if (me->query_temp("songtasks/"+depart+"/"+i+"/finish"))
			return task_finish(me,finishes[i-1]["reward"],finishes[i-1]["comment"]);
	}
	return task_pending(me,ob);
}
