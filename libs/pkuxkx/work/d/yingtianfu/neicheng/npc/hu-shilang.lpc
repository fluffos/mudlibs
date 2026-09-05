//户部侍郎

#include <ansi.h>
inherit NPC;
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_help();

void create()
{
    set_name("户部左侍郎", ({"hubu shilang", "shilang"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷的户部左侍郎。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",3);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    
	set("inquiry", ([
	
     "help": (: ask_help :),
     "帮助": (: ask_help :),
     
	]));

    setup();
    setup_player_name();
}

void init()
{
    add_action("do_a1","answer");
}




int do_a1(string arg)
{
    object me=this_player();
    object ob=this_object();
    int answer,n=3+random(3);
  
    if (!me->query("mingpin"))
    {
        tell_object(me,"户部侍郎不解地望着你。\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/hubu/answer"))
    {
        tell_object(me,"户部侍郎不解地望着你。\n");
        return 1;
    }
    
    if(!arg || (sscanf(arg, "%s %d", arg, answer)< 2 ))
    {
        tell_object(me,"你必须回答一个答案！\n");
        return 1;
    }
    if (arg=="甲地"&& answer==ob->query("x"))
    {
        message_vision("$N答道：莫不是"+chinese_number(answer)+"？\n",me);
        tell_object(me,"恭喜你，答对了甲地的平民数。\n");
        ob->delete("x");
        me->add_temp("mingtasks/hubu/answersuc",1);
        if (me->query_temp("mingtasks/hubu/answersuc")==2)
        {
			if (me->query("mingpin")!=1)
			{
				command("say 大人天资不凡，老夫佩服佩服。");
				command("say 漂亮，大人为我大明立下此等功劳，我已上报吏部。\n");
			}
			else
			{
				n=n*3/2;
				command("flatter "+me->query("id"));
				tell_object(me,"你的大明功勋增加了"+chinese_number(n)+"点。\n");
			}
            me->add("ming/credit",n);
            me->delete_temp("mingtasks");
        }
        return 1;
    }
    if (arg=="乙地" && answer==ob->query("y"))
    {
        message_vision("$N答道：莫不是"+chinese_number(answer)+"？\n",me);
        tell_object(me,"恭喜你，答对了乙地的平民数。。\n");
        ob->delete("y");
        me->add_temp("mingtasks/hubu/answersuc",1);
        if (me->query_temp("mingtasks/hubu/answersuc")==2)
        {
            if (me->query("mingpin")!=1)
			{
				command("say 大人天资不凡，老夫佩服佩服。");
				command("say 漂亮，大人为我大明立下此等功劳，我已上报吏部。\n");
			}
			else
			{
				n=n*3/2;
				command("flatter "+me->query("id"));
				tell_object(me,"你的大明功勋增加了"+chinese_number(n)+"点。\n");
			}
            me->add("ming/credit",n);
            me->delete_temp("mingtasks");
        }
        return 1;
    }
    else
    {
		if (me->query("mingpin")!=1)
		{
			tell_object(me,"回答错误！\n");
			tell_object(me,"户部侍郎道：大人还是请回吧，我自己来算算。\n");
			tell_object(me,"尚书大人所托非人啊！\n");
		}
		else
		{
			message_vision("$N一副欲言又止的样子。\n",ob);
		}
        me->delete_temp("mingtasks");
        return 1;
    }
    
}

int ask_help()
{
    object me=this_player();
    object ob=this_object();
    int a1,a2,b1,b2,c1,c2,x,y,*pool=({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
    
    if (!me->query("mingpin"))
    {
        tell_object(me,"户部侍郎傲慢地望着天花板，并不理你。\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/hubu/hukou"))
    {
        tell_object(me,"户部侍郎傲慢地望着天花板，并不理你。\n");
        return 1;
    }
	if (me->query_temp("mingtasks/hubu/answer"))
    {
        tell_object(me,"户部侍郎催促你快去把这个算出来。\n");
        return 1;
    }
    else
    {
        a1=pool[random(sizeof(pool))];
		pool-=({a1});
        a2=pool[random(sizeof(pool))];
		pool-=({a2});
        b1=pool[random(sizeof(pool))];
		pool-=({b1});
        b2=pool[random(sizeof(pool))];
        x=1+random(50000);
        y=1+random(50000);
        c1=a1*x+b1*y;
        c2=a2*x+b2*y;
        ob->set("x",x);
        ob->set("y",y);
		if (me->query("mingpin")==1)
		command("say "+me->query("name")+"大人教我。");
		else if (me->query("mingpin")<4)
		command("say 这个问题我需要请教一下大人。");
        else
        command("say 你是尚书大人介绍来的，应该有几分能耐。");
        tell_object(me,HIW"大明甲地去年税率是"+chinese_number(a1)+"两，乙地税率是"+chinese_number(b1)+"两，他们上缴的税款总额是"+chinese_number(c1)+"两。\n"NOR);
        tell_object(me,HIW"到了今年甲地税率变为"+chinese_number(a2)+"两，乙地税率变成了"+chinese_number(b2)+"两，他们缴纳的税款总额是"+chinese_number(c2)+"两。\n"NOR);
        tell_object(me,HIW"两地各有多少平民呢？回答模式如：answer 甲地 18，answer 乙地 20。\n"NOR);
        me->set_temp("mingtasks/hubu/answer",1);
        return 1;
    }
}