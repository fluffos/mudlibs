// By Zine
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();


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
            
       	]) );    
        setup();
        carry_object("/d/shaolin/npc/obj/dao-cloth")->wear();
	

}

int bonus(object me)
{
    int exp,pot,beauty,f=1;
    if (me->query("jiangnanquest/finish"))
    {
        return 1;
    }
    else
    {
        me->set("jiangnanquest/finish",1);
        exp=(int)me->query("int")*(int)me->query("dex")*(int)me->query("con")*(int)me->query("str"); //初始80点，如果平均分配最高20^4=160000，如果偏科10×30×10×30=90000
        if (me->query("combat_exp")>300000000)
        {
            f=17;
        }
        if (me->query("combat_exp")<300000000)
        {
            f=16;
        }
        if (me->query("combat_exp")<250000000)
        {
            f=15;
        }
        if (me->query("combat_exp")<200000000)
        {
            f=14;
        }
        if (me->query("combat_exp")<170000000)
        {
            f=13;
        }
        if (me->query("combat_exp")<140000000)
        {
            f=12;
        }
        if (me->query("combat_exp")<110000000)
        {
            f=11;
        }
        if (me->query("combat_exp")<90000000)
        {
            f=10;
        }
        if (me->query("combat_exp")<70000000)
        {
            f=9;
        }
        if (me->query("combat_exp")<50000000)
        {
            f=8;
        }
        if (me->query("combat_exp")<40000000)
        {
            f=7;
        }
        if (me->query("combat_exp")<30000000)
        {
            f=6;
        }
        if (me->query("combat_exp")<20000000)
        {
            f=5;
        }
        if (me->query("combat_exp")<10000000)
        {
            f=4;
        }
        if (me->query("combat_exp")<8000000)
        {
            f=3;
        }
        if (me->query("combat_exp")<6000000)
        {
            f=2;
        }
        if (me->query("combat_exp")<4500000)
        {
            f=1;
        }
        if (me->query("combat_exp")<3000000)
        {
            f=0;
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
        exp=exp*(f*2+10)/160+random(beauty+20000);//按自身exp基数，最优情况，4.5M以下8000(+10000)奖励基点，300M以上136000(+10000)奖励基点，3M以下未进入主流无奖励，避免一步登天 By Zine
        pot=random(exp);
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
    if (!me->query("jiangnanquest/step8"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step7"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step6"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step5"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step4"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step3"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step2"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step1"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }

    else
    {
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
            tell_object(me,"老和尚开始和你一起回忆你在江南的游历。\n");
            me->delete_temp("jiangnanquest/readybonus");
            bonus(me);
		    return 1;
        }
		return 1;
    }
}

