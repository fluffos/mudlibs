#include <ansi.h>
#include <title.h>
int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("songtasks"))
    {
        command("say 你记错了吧？我什么时候给过你任务？");
        return 1;
    }
    if (!me->query_temp("songtasks_want_abandon"))
    {
        command("say 你真的要放弃吗？");
        tell_object(me,"如需放弃本次大宋任务，请再次输入"+HIG+"ask shangshu about fail。\n"+NOR);
        me->set_temp("songtasks_want_abandon",1);
        return 1;
    }
    command("say 好吧，我另找别人去做了。");
    me->delete_temp("songtasks_want_abandon");
    me->delete_temp("songtasks");
    return 1;
}

int ask_tasks()
{
	mixed tm=localtime(time());
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
    object me=this_player();
    object ob=this_object(),tc;
	string *wen=({"同中书门下平章事","参知政事","门下侍郎","中书侍郎"}),*wu=({"枢密使","枢密副使","知枢密院事","同知枢密院事"}),*huan=({"入内内侍省都都知",}),pro;
	mapping *tasks,*tasks_wen=({
		(["name":"三司使","id":"sansishi","officer":"三司使","start_pin":6,"pin":3]),
		//(["name":"御史台","id":"yushitai","officer":"御史中丞","start_pin":6,"pin":3]),
		(["name":"兵部","id":"bingbu","officer":"兵部尚书","start_pin":7,"pin":3]),
		(["name":"工部","id":"gongbu","officer":"工部尚书","start_pin":7,"pin":3]),
		(["name":"吏部","id":"libu","officer":"吏部侍郎","start_pin":7,"pin":2]),//query("song/xunjue")勋爵 钦天监需要转移一处，获得部分mark
		(["name":"刑部","id":"xingbu","officer":"刑部尚书","start_pin":7,"pin":3]),//quanzhou目录下的matou.h guiyunzhuang目录下的taihu_boat.h更新
		(["name":"户部","id":"hubu","officer":"户部尚书","start_pin":7,"pin":3]),//yingtianfu/npc/obj/askmap.h修改
		(["name":"礼部","id":"libu2","officer":"礼部尚书","start_pin":7,"pin":3]),///d/taishan/fengchan修改
		(["name":"谏院","id":"jianyuan","officer":"左司谏","start_pin":8,"pin":4]),
		(["name":"鸿胪寺","id":"honglusi","officer":"鸿胪寺卿","start_pin":9,"pin":5]),
		(["name":"学士院","id":"hanlinyuan","officer":"翰林学士","start_pin":9,"pin":5]),
		(["name":"太医局","id":"taiyiyuan","officer":"太医局丞","start_pin":9,"pin":8]),
		//(["name":"太常寺","id":"taichangsi","officer":"太常寺卿","start_pin":9,"pin":5]),
		(["name":"大理寺","id":"dalisi","officer":"大理寺卿","start_pin":9,"pin":5]),
		//(["name":"宗正寺","id":"zongrenfu","officer":"宗正寺卿","start_pin":9,"pin":5]),
		//(["name":"司农寺","id":"sinong","officer":"司农寺卿","start_pin":9,"pin":5]),//司农寺掌管仓库，号称“走卿”；
		//(["name":"太府寺","id":"taifu","officer":"太府寺卿","start_pin":9,"pin":5]),//太府寺所隶场务众多，号称“忙卿”
		//(["name":"将做监","id":"jiangzuo","officer":"将做监判监事","start_pin":9,"pin":6]),//将作监也只管祭祀、供给牲牌、镇石、炷香、盥水等事，
		(["name":"军器监","id":"junqi","officer":"军器监判监事","start_pin":9,"pin":6]),
		(["name":"都水监","id":"dushui","officer":"都水监使者","start_pin":9,"pin":6]),//changjiang有修改
		//(["name":"临安府","id":"linan","officer":"临安府尹","start_pin":9,"pin":6]),
		//(["name":"詹事府","id":"zhanshifu","officer":"詹士府詹士","start_pin":9,"pin":5]),
		
	});
	mapping *tasks_wu=({
		(["name":"殿前都","id":"dianqian","officer":"殿前都都指挥使","start_pin":6,"pin":2]),//inherit/item/army
		(["name":"捧日卫","id":"pengri","officer":"捧日卫上护军","start_pin":9,"pin":3]),
		(["name":"天武卫","id":"tianwu","officer":"天武卫上护军","start_pin":9,"pin":3]),
		(["name":"神卫","id":"shenwei","officer":"神卫上护军","start_pin":9,"pin":3]),
		(["name":"龙卫","id":"longwei","officer":"龙卫上护军","start_pin":9,"pin":3]),
		(["name":"水师","id":"shuishi","officer":"水师大都督","start_pin":9,"pin":3]),// /d/suzhou/hubian2修改 /d/suzhou/shuizeiying修改 /d/suzhou/warship edited. /d/changjiangnorth
		(["name":"步军都","id":"bujun","officer":"步军都都指挥使","start_pin":9,"pin":3]),
		(["name":"马军都","id":"majun","officer":"马军都都指挥使","start_pin":9,"pin":3]),
	});
	mapping *tasks_huan=({
		(["name":"御药院","id":"yuyao","officer":"提举御药院","start_pin":9,"pin":8]),
		(["name":"内东门司","id":"neidongmen","officer":"勾管内东门司","start_pin":9,"pin":8]),
		(["name":"合同凭由司","id":"hetong","officer":"勾管合同凭由司","start_pin":9,"pin":8]),
		(["name":"造作所","id":"zaozuo","officer":"勾管后苑造作所","start_pin":9,"pin":8]),
		(["name":"军头引见司","id":"juntou","officer":"勾管军头引见司","start_pin":9,"pin":8]),
		(["name":"管勾往来国信所","id":"guoxin","officer":"勾管往来国信","start_pin":9,"pin":8]),
		(["name":"翰林院","id":"hanlin","officer":"提举翰林院","start_pin":9,"pin":8]),
	});
	mapping give_task;
	int tasknumber,cdtime;
	string title="",new_title,name,*titles;
	mapping *tasks_overall=tasks_wen;
	tasks_overall+=tasks_wu;
	tasks_overall+=tasks_huan;
	if (!me->query("song/pro")||!DASONG_D->get_my_pin(me))
    {
        command("say 你不是大宋的官员，别来掺和了。\n");
        return 1;
    }
	if (me->query("song/pro")=="文")
	{
		pro="wen";
		tasks=tasks_wen;
		if (member_array(query("posi"),wen)==-1)
		{
			command("say 大人身为文官，应该到政事堂去问问。");
			return 1;
		}
	}
	if (me->query("song/pro")=="武")
	{
		pro="wu";
		tasks=tasks_wu;
		if (member_array(query("posi"),wu)==-1)
		{
			command("say 大人身为武官，应该到枢密院去问问。");
			return 1;
		}
	}
	if (me->query("song/pro")=="宦")
	{
		pro="huan";
		tasks=tasks_huan;
		if (member_array(query("posi"),huan)==-1)
		{
			command("say 宦官不得干政。");
			tell_object(me,"你暗自心想，还是会内廷看看吧。\n");
			return 1;
		}
	}
	tc=load_object("/d/song/record/positions");
	if (query("posi")!=tc->query("task_giver_"+pro))
	{
		command("say 今天是"+tc->query("task_giver_"+pro)+"大人当值，你去问问他吧。");
		return 1;
	}
	if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
		return 1;
    }
	for (int i=0;i<sizeof(tasks_overall);i++)
	{
		if (me->query_temp("songtasks/"+tasks_overall[i]["id"]))
		{
			if (DASONG_D->get_my_pin(me)>3)
			command("say 你已经领过任务了，还不快去做？");
			else
			command("say 大人快去吧。");
			return 1;
		}
	}
	if (day!=me->query("song/task_date"))
	{
		me->set("song/task_date",day);
		me->set("song/task_times",0);
	}
	cdtime=DASONG_D->cdtime(me);
    if ((int)me->query("mud_age")-(int)me->query("song/taskstime")<cdtime)
    {
        command("say 我大宋朝也不能把官员给累死，你先去休息一会吧。");
        return 1;
    }
    me->add_busy(1);
	if (!me->query("song/special")&&me->query("song/pro")!="宦")
    {
        command("say 你有空的时候去门下省官厅报个到(baodao)。");
    }
    if (DASONG_D->get_my_pin(me)==1)
    {
        command("say 老大人乃国之柱石，怎敢劳动老大人？");
        return 1;
    }
    else
    {
		for (int i=0;i<sizeof(tasks);i++)
		{
			if (tasks[i]["start_pin"]<DASONG_D->get_my_pin(me))
			{
				tasks-=({tasks[i]});
			}
		}
		if (sizeof(tasks))
		give_task=tasks[random(sizeof(tasks))];
		else
		{
			command("say 暂时没有任何任务可以给你。");
			return 1;
		}
		title=TITLE_SONG1;
		if (title)
		{
			titles=me->query("multi_title");
			if (titles)
			{
				if (member_array(title,titles)==-1)
				{
					me->set("multi_title", ({title}));
				}
			}
			else
			{
				me->set("multi_title", ({title}));
			}
			
		}
		title="";
        me->set("song/taskstime",me->query("mud_age"));
		me->set_temp("songtasks/"+give_task["id"]+"/start",1);
		name=COLOR_D->uncolor(me->query("name"))[0..1];
		if (DASONG_D->get_my_pin(me)<give_task["pin"])
		new_title="判"+give_task["name"]+"事";
		else if (DASONG_D->get_my_pin(me)==give_task["pin"])
		new_title="知"+give_task["name"]+"事";
		else if (DASONG_D->get_my_pin(me)-give_task["pin"]<2)
		new_title="权知"+give_task["name"]+"事";
		else
		new_title="";
		if (new_title!="")
		{
			title=HIR"大宋 "+NOR+new_title+NOR+" "+me->query("name")+"(" + capitalize(me->query("id")) + ")";
			if (me->query("song/title")!=give_task["officer"]&&pro!="huan")
			{
				command("say 此刻"+give_task["name"]+"事务繁重，毫无头绪，"+name+"大人领"+new_title+"一职一段时间吧。");
				me->set_temp("apply/short",title);
				me->set_temp("song_multi_title",time());
			}
			else
			command("say 此刻"+give_task["name"]+"事务繁重，大人去帮帮他们吧。");
		}
		else
		{
			command("say 此刻"+give_task["name"]+"事务繁重，"+give_task["officer"]+"正在找人帮忙，你去看看吧。");
		}
		if (me->query("song/pro")=="文")
		DASONG_D->multi_record(me,1,"给出",3);
		me->add("song/task_times",1);
        return 1;
    }
}

