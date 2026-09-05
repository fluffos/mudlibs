// By Zine
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
int ask_karma();
void Register_me(object me)
{
	if (!environment(me)) return;
	STATISTIC_D->set("Karma_Holder",me);
}
void create()
{
	set_name("老和尚", ({ "lao heshang","heshang","monk"}));
        
	set("long",
	"他是这里的主持，执掌清凉寺几十年了。\n"
         );
	set("title",HIC"大智大慧"NOR);
	set("gender", "男性");
	
	set("age", 73);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
        set("qi", 1000);
        set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 650000+random(100000000));
	
    set("inquiry", ([
			"quest" : (: ask_quest :),
            "江南八镇" : (: ask_quest :),
            "倒浮屠" : (: ask_karma :),
			"karma" : (: ask_karma :),
       	]) );    
	setup();
	carry_object("/d/shaolin/npc/obj/dao-cloth")->wear();
	call_out("Register_me",1,this_object());

}

int bonus(object me)
{
    int exp,pot,beauty,factor=17,*exp_limit=({300000000,250000000,200000000,170000000,140000000,110000000,90000000,70000000,50000000,40000000,
	30000000,20000000,10000000,8000000,6000000,4500000,3000000});
    if (me->query("jiangnanquest/finish"))
    {
        return 1;
    }
    else
    {
        me->set("jiangnanquest/finish",1);
        exp=(int)me->query("int")*(int)me->query("dex")*(int)me->query("con")*(int)me->query("str"); //初始80点，如果平均分配最高20^4=160000，如果偏科10×30×10×30=90000
        for (int i=0;i<sizeof(exp_limit);i++)
		{
			if (me->query("combat_exp")<exp_limit[i])
			factor-=1;
		}
        if (me->query_temp("beauty"))
        {
            me->delete_temp("beauty");
            beauty=(int)me->query("per")*100;
            if (beauty>20000)
            {
                beauty=20000;
            }
        }
        exp=exp*(factor*2+10)/160+random(beauty+20000);//按自身exp基数，最优情况，4.5M以下8000(+10000)奖励基点，300M以上136000(+10000)奖励基点，3M以下未进入主流无奖励，避免一步登天 By Zine
        pot=1+random(exp);
        me->add("combat_exp",exp);
        me->add("potential",pot); //一次性奖励，且quest属性，不须加入rewardd机器人判断，by Zine
        if (random(10000)>9990)//千分之一概率奖励根骨 by Zine
        {
            me->add("con",1);
            tell_object(me,HIW"在江南历练之后，你觉得冥冥中自己增长了一点根骨。\n"NOR);
        }
        tell_object(me,this_object()->query("name")+"道：施主大智慧，并非凡人，此番历练必将有益此后的武学进展。\n");
        tell_object(me,HIC+sprintf("你的经验增加了%s点，你的潜能增加了%s点。\n",chinese_number(exp),chinese_number(pot))+NOR);
        return 1;
    }
}



int ask_quest()
{
    object ob=this_object();
    object me=this_player();
    if (me->query("jiangnanquest/finish"))
    {
        command("say 你别当我老糊涂了，来重复领奖，我可是天天喝脑白金的！\n");
        return 1;
    }
	for (int i=1;i<9;i++)
	{
		if (!me->query("jiangnanquest/step"+i))
		{
			command("say 江南很大，你还需要去历练一些。\n");
			return 1;
		}
	}
    if (!me->query_temp("jiangnanquest/readybonus"))
    {
		command("say 既然你已游历了江南八镇，准备好拿奖励了？\n");
		tell_object(me,BLINK+HIR+"江南八镇Quests的奖励根据自身经验有一些浮动，避免低经验做完一步登天的状况，\n"NOR);
		tell_object(me,HIW"你如果愿意此时领奖就再ask一遍，也可以等你厉害点再领奖。\n"NOR);
		me->set_temp("jiangnanquest/readybonus",1);
		return 1;
	}
    else
	{
		message_vision("$N开始和$n一起回忆你在江南的游历。\n",ob,me);
		me->delete_temp("jiangnanquest/readybonus");
		bonus(me);
		return 1;
	}
	return 1;
}
int ask_karma()
{
	int num;
	object me=this_player();
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	if (!query("allow_enter_karma"))
	command("say 佛云：“不可说，不可说。”");
	else if (time()-me->query("karma/LastTrial")<259200)
	command("say 你本周刚刚尝试过，把机会让给别人吧。");
	else if (num=load_object("/d/yingtiannorth/qlsi2")->query("player_num")>12)
	command("say 现在要已经有很多人在尝试，你下次再来吧。");
	else
	{
		command("say 好吧，你要愿意我就送你进去。");
		message_vision("$N大袖一挥，把$n送进了后院。\n",this_object(),me);
		me->move("/d/yingtiannorth/qlsi2");
		me->set_temp("karma/LegalEnter",1);
		me->set("karma/LastTrial",time());
		if (num&&num<12)
		command("jh 地宫中现有"+chinese_number(num)+"位英雄在等待队友。");
	}
	return 1;
}
void start()
{
	command("jh 清凉寺地宫任务开启，请有缘人速来建康府北城清凉寺报名参加。");
	set("allow_enter_karma",1);
}
void die()
{
	this_object()->fullme();
	message_vision("老和尚真气在经脉内运转一遍，竟完全恢复了。\n",this_object());
	return;
}
