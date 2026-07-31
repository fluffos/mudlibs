// shan.c

inherit NPC;
//inherit F_SKILL;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name("单正", ({ "shan zheng", "shan", "zheng" }));
	set("nickname", HIB"铁面判官"NOR);
	set("age", 63);
	set("str", 25);
	set("dex", 16);
	set("per", 22);
	set("long", 
"他生平嫉恶如仇，只要知道江湖上有什么不公道之事，定然伸手
要管。他满脸红光，当得起“童颜鹤发”四字，神情却甚谦和，
不似江湖上传说的出手无情。\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 50);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me,ob;
        int j, combatexp, timep,factor,num;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        if(combatexp<10000)
        {
message_vision("单正对$N哼了一声道：“这种小角色还想除暴安良？”\n",me);
             return 1;
        }
        if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }

	if(combatexp>2000000)
        {
message_vision("单正对$N哼了一声道：“你武功太高了，已经没有适合给你的任务了。”\n",me);
             return 1;
        }


        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
message_vision("单正对$N冷冷一笑道：让你办的事如何了？\n", me);
message_vision("单正瞟了$N一眼说道：你要是没本事，就拿点儿费用出来我让别的人去申张正义。\n",me);
                   return 0;
             }
             else
             {
message_vision("单正对着$N叹了一口气：哎，我就再给你一次机会吧。\n", me);
                   me->delete("songxin");
                   me->add("qi",-(int)(me->query("qi")/10));
             }
        }

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];
        quest = QUESTS_D(tag)->query_quest();
        timep = quest["time"];

        time_period(timep, me);
        if(quest["quest_type"]=="杀")
             tell_object(me,"先替我把『"+quest["quest"]+"』给我杀了，别的差使以后再说。\n" NOR);

        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
//                   if (ob = present("xin", this_player()))
//                   {
//                   destruct(ob);     
//                   }
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW "单正吩咐道：给你在" + time + "内");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                   message_vision("单正笑道：那我可就不客气了。\n",who);
                   return 1;
             }
             if (who->query("songxin") > 0)
             {
                   message_vision("你这家伙，明明是接的送信任务，怎么到我这儿来取消？银子没收！\n",who);
                   return 1;
             }
             else
             if ( ob->value() < 2000)
             {
message_vision("单正一双尖针般的眼睛直盯着$N：这点钱可不够我们的开销！\n", who);
                   return 1;
             }
             else
             {
message_vision("单正笑道：那好，咱们买卖不成仁义在。想讨差使再找我吧！\n",who);
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->apply_condition("menpai_busy",5);
                   who->apply_condition("hxsd_busy",1+random(5));
                   return 1;
             }
        }
        return 1;
}
