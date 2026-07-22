// yanshang2.c 盐商头子
//Yanqi 08/11/2k
//提升到160k可以做@yeju

#include <ansi.h>
inherit NPC;
int ask_job();

void create()
{
        set_name("盐商", ({ "yanshang touzi", "touzi", "yanshang" }));
        set("gender", "男性");
        set("age", 32+random(20));
        set("long", "他是这里盐商的头子，表面上中规中矩，但是背地里干着贩运私盐的勾当。\n");
        set("combat_exp", 3000);        
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 30);
        set_skill("dodge", 20);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("inquiry", ([
                "job": (: ask_job :)
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
                "盐商不停地嘟囔道：朝廷如此没落，叫我等百姓如何生存？\n",
        }) );
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
        setup();        
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int ask_job()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if( exp1 < 30000 || exp1 > 160000 )
        {
                command("say 你别是官府派来卧底的吧，一边待着去。");
                return 1;
        }
        
        if (me->query_condition("job_busy")) 
        {
                command("say 你正忙着做别的任务呢？");
                return 1;
        }
                
        me->delete_temp("newbiejob2");       
        me->apply_condition("job_busy",5 + random(5));
        me->set_temp("newbiejob2/start",1);
        
        command("whisper "+me->query("id")+" 你速去泰山脚下的海滨等候我的船来。");
        return 1;
}

void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
       if(ob->query_temp("newbiejob2/start")
        && ob->query_temp("newbiejob2/over")
        && ob->query_temp("newbiejob2/middle"))
       { 
           command("nod " +ob->query("id"));
           command("whisper "+ob->query("id")+" 你辛苦了，可以跟我覆命（give yanshang yan）了! ");
           return;
       }
}

int accept_object(object me, object yan)
{
        int pot,exp;
        
        if (!(me->query_temp("newbiejob2/start")))
                return notify_fail("你没有在我这里要任务呀？\n");
                
        if (!(me->query_temp("newbiejob2/middle")))
                return notify_fail("你怎么还没有去海滩？\n");

        if ( yan->query("id") != "yan ba") 
                return notify_fail("你给我这个干吗啊？");

        if (me->query_temp("newbiejob2/over"))
        {
                pot =30 + random(15);
                exp = pot*3+random(me->query("age",1));
                pot = exp/5 + random(exp/10);
                me->add("potential",pot);
                me->add("job_time/盐枭",1);
                if(me->query("potential") > me->query("max_pot"))
                        me->set("potential", me->query("max_pot"));
                me->add("combat_exp",exp);
                me->delete_temp("newbiejob2");
                call_out("destroying", 1, yan);
                tell_object(me,HIW"你被奖励了："+chinese_number(exp)+"点经验和"+chinese_number(pot)+"点潜能。\n"NOR);
                return 1;
        }
        else
        {
                message_vision("来人呀！快把"+me->query("name")+"给我痛打一顿！也不打听打听大爷我的名号。\n",me);
                message_vision("只见两个身穿黑衣的大汉走了过来，一顿拳脚打的$N昏了过去！\n"NOR,me);
                me->delete_temp("newbiejob2");
                me->apply_condition("job_busy", 4);
                call_out("destroying", 1, yan);
                me->unconcious();
                return 1;
        }
}

void destroying(object yan)
{
        if(!yan) return;
        destruct(yan);
}
