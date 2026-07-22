//Yanqi 08/10/2k
#include <ansi.h>
inherit NPC;

int ask_job();

void create()
{
        set_name("李公公", ({ "li gonggong", "li", "gonggong" }) );
        set("gender", "无性" );
        set("age", 60);
        set("long", "他就是皇上身边的李公公。看起来脸色不太好，可能是最近比较操劳。\n");
        set("nickname","钦差大臣");
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("shen_type", -1);

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("huashan-jianfa" ,50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 5);
        set_temp("apply/attack", 5); 
        set_temp("apply/defense", 5);
        set("combat_exp", 80000);

        set("attitude", "peaceful");

        set("inquiry", ([
                "job": (: ask_job :)
        ]));

        set("chat_chance", 3);
        set("chat_msg", ({
                "李公公不停地催促着：快点，快点，耽误了朝廷的大事，一个也跑不了。\n",
                "李公公对你怒道：如此废物，亏你还是习武之人！\n",
                "李公公不停地嘟囔道：进度如此缓慢，当初就不该插手此事！\n",
                }) );
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
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
        add_action("do_task","task"); 
}

int ask_job()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if (me->query_condition("job_busy")){
           command("say 你正忙着呢?");
           return 1;
        }
    
        if( exp1 > 50000 )
        {
                command("consider "+me->query("id"));
                return 1;
        }
    
        if (present("shi kuai", me))
        {
                command("angry "+me->query("id"));
                command("say 你的任务还没有完成，怎么如此拖拉！");
                return 1;
        }


        if (random(10) > 4 || me->query_temp("newbiejob1/over"))
        {
                message_vision(CYN"李公公恶狠狠地对$N说的道：“你把我脚下的这块石头搬到大坝那边给我砌好。快去！”\n"NOR,me);
                message_vision(HIM"只见两个壮汉架着一块巨石放在了$N的身上。\n"NOR,me);
                tell_object(me,HIR"你感到双肩一沉，不由得深深吸了一口气。\n"NOR);

                new(__DIR__"obj/shi")->move(me);
                if((me->query("qi")<10) || (me->query("jingli")<20))
                me->unconcious();
                else {
                  me->add("jingli",-10);
                  me->add("qi",-5);
                }
                me->set_temp("newbiejob1/start",1);
                me->start_busy(2+random(6));
                return 1;
        }
        else
        {
                message_vision(CYN"李公公抱歉地对$N说道：“这里暂时没有工作了，等等吧”\n"NOR,me);
                return 1;
        }
}

void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
       if(ob->query_temp("newbiejob1/start")
        && ob->query_temp("newbiejob1/over") > 7 ){ 
           command("nod " +ob->query("id"));
           command("whisper "+ob->query("id")+" 你辛苦了，可以跟我覆命（task ok）了! ");
           return;
       }
}

int do_task(string arg)
{
        object me;
        int pot,exp,sil;
        
        me=this_player();
        
       if(!( arg || arg=="ok")) return 0;
        
        if (me->query_temp("newbiejob1/start")){ 
            if( me->query_temp("newbiejob1/over") > 4 + random(4)){
                exp = 80+random(me->query_skill("force"))/2;
                pot = exp/5 + random(exp/6);
		sil = me->query_skill("force")/10+random(5);
                me->add("potential",pot);
                if(me->query("potential") > me->query("max_pot"))
                        me->set("potential", me->query("max_pot"));
                me->add("combat_exp",exp);
                me->apply_condition("job_busy",random(4)+3);
                me->delete_temp("newbiejob1");
                tell_object(me,HIW"你被奖励了："+chinese_number(exp)+"点经验和"+chinese_number(pot)+"点潜能。\n"NOR);
		this_object()->add_money("silver", sil);
		command("give "+me->query("id")+" "+sil+" silver");
                return 1;
            }
            else {
                command("say 你才搬了"+chinese_number(me->query_temp("newbiejob1/over"))+"次就想要奖励啊，再给我干活去。");
                return 1;
            }
        }
        else {
                command("kick3 "+me->query("id"));
                command("say 来人呀！快把"+me->query("name")+"给我痛打一顿！");
                message_vision(HIR"只见两个壮汉走了过来，一顿棍棒打的$N报头痛哭！\n"NOR,me);
                me->delete_temp("newbiejob1");
                me->apply_condition("job_busy",random(4)+3+me->query_condition("job_busy"));
                me->unconcious();
                return 1;
        }
}
