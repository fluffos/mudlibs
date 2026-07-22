// writed by cly 06/07/2007

inherit BHNPC;
#include <ansi.h>
#include "/d/erengu/npc/quest_kill.h"

int place_room(object me,object ob);
string ask_job();
string ask_cancel();
string ask_erengu();

void create()
{
        set_name(HIC"铁战"NOR, ({ "tie zhan", "tie" }));
		set("title", HBK"十大恶人之一"NOR);
		set("nickname", HIR"狂狮"NOR);
        set("shen_type", 0);
        set("gender", "男性");
        set("age", 40);
        set("long", 
			"十大恶人之一的狂狮铁战。此人实乃一粗莽汉子，之所以被列为恶人之一，只因\n"
			"其发起狂来六亲不认，见人就打。就连他的儿子，都被逼得非和他打一场不可。\n"
			"但真被打死的，却没有半个。\n");
        set("combat_exp", 30000000);
		set("max_neili", 100000000);
		set("neili", 100000000);
		set("max_qi",20000000);
		set("qi",20000000);
		set("max_jing",20000000);
		set("jing",20000000);
		set("max_jingli",100000000);
		set("jingli",100000000);
		set("per",20);
        set("jiali", 400);
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("jiuyang-shengong",500);

        set("inquiry", ([
                "quest" : (: ask_job :), 
                "job"   : (: ask_job :), 
                "工作"  : (: ask_job :),
				"cancel": (: ask_cancel :),
				"恶人谷": (: ask_erengu :),
		]) );
        set("no_clean_up",1);

		set_temp("apply/attack", 1000000);
		set_temp("apply/defense", 1000000);
		set_temp("apply/damage", 1000000);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

string ask_job()
{   
    int kill_count,reward_exp,reward_pot,reward_rmb,reward_gold;
    object me,killer,lingpai;
    me=this_player();

	if( stringp(me->query("banghui/name")) )
	{
		return CYN+"走开，来找碴的么？\n"+NOR;
	}

	if(me->query("combat_exp")< 50000000)//经验下限5千万
		return CYN"你的身手不行，恐怕会丢了你的性命！\n"NOR;
	
	if(me->query("combat_exp")> 2000000000)//经验上限20亿
		return CYN"你的身手太高，恐怕恶人谷请不起您！\n"NOR;

	if(me->query("bh_quest") && me->query_temp("bh_quest/have_task"))
		return HIW+me->query("name")+",你现在的任务是去除掉在"
			+me->query("bh_quest/killed_place_name")
			+"一带活动的"+me->query("bh_quest/killed_name")+"("
			+me->query("bh_quest/killed")+")。\n"+NOR;

	if(!me->query_temp("bh_quest/killed") && (time()-(int)me->query("bh_quest/time"))< 10)
		return	CYN+"辛苦你了，你先好好休息下吧！\n"+NOR;

	if( me->query_temp("bh_quest/count") > 14
		&& !me->query_temp("bh_quest/reward"))
	{
		reward_exp=(int)me->query("combat_exp")/1000;
		if(reward_exp>200) reward_exp=200;
		reward_exp=reward_exp+random(reward_exp);
		reward_pot=reward_exp/4;
		me->add("bh_quest/reward_exp",reward_exp);
		me->add("bh_quest/reward_potential",reward_pot);
		me->add("combat_exp", reward_exp);
		me->add("potential", reward_pot);
		reward_rmb = 18+random(22);
		reward_gold = reward_rmb + random(reward_rmb/2);
                me->add("money",random(reward_gold));
                 me->add("rmb", random(reward_rmb/1000));
		me->set_temp("bh_quest/reward",1); 

		return 
HIW+me->query("name")+", 恶人谷在你的帮助之下又少了一个威胁。\n鉴于你出色的表现，老夫要额外嘉奖你：\n"+
CHINESE_D->chinese_number(reward_exp) +"点的『实战经验』 "+
CHINESE_D->chinese_number(reward_pot)+"点的『潜能』！\n"+
CHINESE_D->chinese_number(reward_gold) +"两的『黄金』 "+
CHINESE_D->chinese_number(reward_rmb) +"圆的『人民币』。\n"+NOR; 
    }

	if( me->query_temp("bh_quest/count") > 14)
	{
		me->set_temp("bh_quest/reward",0); 
		me->set_temp("bh_quest/count", 0);
	}
	killer=new("/d/erengu/npc/job_npc");
	place_room(me,killer);
	killer->start_escape(killer,me);
	me->set("bh_quest/killed",killer->query("id"));
	me->set("bh_quest/killed_name",killer->query("name"));
	me->set("bh_quest/killed_place_name",killer->query("area"));
	me->set("bh_quest/time",time());
	me->set_temp("bh_quest/have_task",1);
	return 
HIC+me->query("name")+"，听说"+HIG+killer->query("name")+"("+killer->query("id")+")"+
HIC+"正在"+HIG+killer->query("area")+HIC+"打探恶人谷的消息。\n你应该知道怎么做了！切记在十二分钟内完成！\n"NOR;
}

string ask_cancel()
{
    int reward_exp,reward_pot,level=0;
	int reward_gold,reward_rmb;
    object me,lingpai;

    me=this_player();

	if(me->query("bh_quest") && me->query_temp("bh_quest/have_task"))
	{
		reward_exp=100+random(50)+level+
			(int)me->query_temp("bh_quest/count")*20;
		reward_rmb = me->query_temp("bh_quest/count") + 10 + 3*random(me->query_temp("bh_quest/count")/2+1) + random(20);
		reward_gold = reward_rmb + random(reward_rmb * 2);
		if(me->query("combat_exp") < 100000 )
			reward_exp -=reward_exp/50;
		if(me->query("combat_exp") > 1000000)
			reward_exp +=reward_exp/30;

		reward_pot=reward_exp/30+random(50)+50;

		me->add("combat_exp",-reward_exp);
		me->add("potential",-reward_pot);
		me->add("money",-reward_gold*100);
                 me->add("rmb",-reward_rmb/100);
		me->set_temp("bh_quest/reward",0); 
		me->set_temp("bh_quest/count", 0);
		me->set_temp("bh_quest/have_task",0);
		return sprintf("%s%s%s%s%s%s%s"NOR"\n",
	HIC+me->query("name"),"，你太让老夫失望了，现扣去你\n",
	CHINESE_D->chinese_number(reward_exp) +"点的『实战经验』",
	CHINESE_D->chinese_number(reward_pot)+"点的『潜能』！\n",
	CHINESE_D->chinese_number(reward_gold) +"两的『黄金』",
	CHINESE_D->chinese_number((reward_rmb)/10) +"圆的『人民币』",
	"作为惩罚，你下去休息吧。"NOR);
	}
	else
	{
		return	CYN+"辛苦你了，你先好好休息下吧！\n"+NOR;
	}
}

int accept_object(object who, object ob)
{
	int base_value, amount, value;

	if(!ob->query("money_id"))
	{
		return notify_fail("给我这些废物干什么？");
	}

	if( who->query_temp("go_erengu") )
	{
       command("say "+who->query("name")+"，上次的事都还没办成，怎么好再收你的钱！\n");
       return 0;
	}

	base_value = ob->query("base_value") / 10000;
	amount = ob->query_amount();

	if(base_value <= 0)
	{
       command("say "+who->query("name")+"，多谢你的馈赠了！ \n");
       return 1;
	}

	if(amount >= 2100000000 / base_value)
	{
       command("say "+who->query("name")+"，这么多钱我可不敢收！\n");
       return 0;
	}

	value = (base_value * amount);
    if( value >= 10000)
	{
		message_vision("不知道$N有什么问题要问我呢？\n", who);
		who->add_temp("go_erengu", value / 10000);
		return 1;
	}
	else
	{
       command("say "+who->query("name")+"，多谢你的馈赠了！ \n");
       return 1;
	}
}

string ask_erengu()
{
	int count;
	object me = this_player();

	count = (int)me->query_temp("go_erengu");
	if( count )
	{
	     if( me->query("rmb") >= count * 1 )
		{
			tell_object(me,HIG"嘿嘿！恶人谷处在一个极度隐蔽的地方，我送你过去吧！(扣取RMB 1元)\n"NOR);
			//me->add("rmb", -count * 1);
			me->move("d/erengu/erengu");
			me->delete_temp("go_erengu");
			me->add("erengu/count",count);
		}
		else
		{
			tell_object(me,HIG"嘿嘿！我可是要冒着掉脑袋的危险送你进谷的，请准备好再来吧！\n"NOR);
		}
	}

	return HIC"恶人谷在一个隐蔽的地方。\n"NOR;
}


