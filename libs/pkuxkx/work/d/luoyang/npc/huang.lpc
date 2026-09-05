//黄裳
//created by Zine 15 Feb 2011

#include <ansi.h>
inherit NPC;

int ask_start();
int ask_finish();

void create()
{
        set_name("黄裳", ({ "huang shang","huang","shang"}) );
        set("gender", "男性" );
		
        set("age", 81);
        set("long", 
            "他是九阴真经的作者——黄裳，精通各大门派武学，所以写出了破解之道。\n");
        set("str", 80);
        set("dex", 80);
        set("con", 80);
        set("int", 80);
		set("shen_type", 1);
		set_skill("force", 2500);
        set_skill("jiuyin-zhengong",2500);
        set_skill("strike",2500);
        set_skill("jiuyin-shenzhang",2500);
        set_skill("claw",2500);
        set_skill("parry",2500);
        set_skill("jiuyin-shenzhua",2500);
        set_skill("dodge",2500);
        set_skill("jiuyin-shenfa",2500);

        map_skill("strike","jiuyin-shenzhang");
        map_skill("claw","jiuyin-shenzhua");
        map_skill("dodge","jiuyin-shenfa");
        map_skill("force","jiuyin-zhengong");
        map_skill("parry","jiuyin-shenzhua");

        prepare_skill("claw","jiuyin-shenzhua");
        prepare_skill("strike","jiuyin-shenzhang");

		set("combat_exp", 1000000000);
		set("max_qi", 1000000);
        set("max_jing", 1000000);
        set("neili", 4000000);
        set("max_neili", 4000000);
		set("uni_target",1);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "老夫黄裳",
			"试炼开始" : (: ask_start :),
            "start" : (: ask_start :),
            "试炼结束" : (: ask_finish :),
			"finish" : (: ask_finish :),
			
			
            
       	]) );
		
        setup();
        
		carry_object("/d/city/npc/items/cloth1")->wear();

}

void init()
{
	add_action("do_colorselect", ({ "select" }));
}

void unconcious()
{
        die();
}

void die()
{
        message_vision("$N道，有必要吗？\n",this_object());
        this_object()->fullme();
        return;
}

int ask_start()
{
    int i=random(6);
    object ob=this_object();
    object me=this_player();
    if (ob->is_busy() || ob->is_fighting())
	{
        command("say 没看我正忙着吗？\n");
		return 1;
    }
    if (me->is_busy() || me->is_fighting())
	{
        tell_object(me,"你正忙着呢。\n");
		return 1;
    }
    if (me->query("combat_exp")<10000000)
    {
        command("say 你的经验太欠缺，还是下次请早吧。\n");
		return 1;
    }
    else
    {
        me->set("gamblematch/initexp",me->query("combat_exp"));
        me->set("gamblematch/targetexp",me->query("combat_exp")/100*(102+i));
        me->set("gamblematch/begining",time());
        command("say "+me->query("name")+"，此刻你的历练是"+chinese_number(me->query("gamblematch/initexp"))+"，假如一周后再见到我时能达到"+chinese_number(me->query("gamblematch/targetexp"))+"，就算通过了历练。\n");
        me->add_busy(1);
        ob->add_busy(1);
        return 1;
    }
}

int ask_over()
{
    object ob=this_object();
    object me=this_player();
    object qian;
    if (ob->is_busy() || ob->is_fighting())
	{
        command("say 没看我正忙着吗？\n");
		return 1;
    }
    if (me->is_busy() || me->is_fighting())
	{
        tell_object(me,"你正忙着呢。\n");
		return 1;
    }
    else
    {
        if (!me->query("gamblematch/begining"))
        {
            command("say 你一周之前请求过试炼吗？\n");
		    return 1;
        }
        if (time()-me->query("gamblematch/begining")>605000)//一周时间604800
        {
            command("say 你确定你参加的是这次试炼吗？\n");
		    return 1;
        }
        if (me->query("combat_exp")>=me->query("gamblematch/targetexp"))
        {
            if (me->query("combat_exp")>=(me->query("gamblematch/initexp")/5*6))
            {
                qian=new(__DIR__"obj/qian2");
                qian->set("owner",me->query("id"));
                qian->move(me);
                command("say 阁下天纵之才，练功速度实在惊人！\n");
                command("say 这根签交给你，你可以到建康府清凉寺去解签！\n");
		        return 1;
            }
            else
            {
                qian=new(__DIR__"obj/qian1");
                qian->set("owner",me->query("id"));
                qian->move(me);
                command("say 阁下资质平平，勉强合格，但我也会给你个机会！\n");
                command("say 这根签交给你，你可以到建康府清凉寺去解签！\n");
		        return 1;
            }
        }
        else
        {
            command("say 以你的龟速练功，还是回家种田比较有前途啊！\n");
		    return 1;
        }
    }
}
