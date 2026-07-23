// helian.c

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name("赫连铁树", ({ "helian tieshu", "helian", "tieshu" }));
	set("title", HIY"西夏国征东大将军"HIM"西夏一品堂"HIR"总管"NOR);
	set("gender", "男性");
	set("age", 35);
	set("str", 25);
	set("dex", 26);
	set("per", 16);
	set("long", "他身穿大红锦袍，三十四五岁年纪，鹰钩鼻、八字须。\n");

	set("combat_exp", 500000);
	set("shen_type", -1);
	set("attitude", "peaceful");
        set("max_qi",2500);
        set("max_jing",1000);
        set("neili", 2500);
        set("max_neili", 2500);
	set("jiali", 200);

        set_skill("claw", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 40);
        set_skill("jiuyin-baiguzhao", 90);
        set_skill("bibo-shengong", 90);
        set_skill("lingxu-bu", 90);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "lingxu-bu");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("inquiry", ([
            "一品堂": "一品堂就是要和中原武林做对！\n",
        ]) );

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}

int accept_fight(object me)
{
        command("say 你敢来一品堂撒野！不要命了！");
        return 0;
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
                        "15000",
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
        if( !(int)me->query("yipin/joined"))
        {
message_vision("赫连铁树对$N哼了一声道：“你不是本堂的吧？来这凑什么热闹！”\n",me);
             return 1;
        }
        if(combatexp<10000)
        {
message_vision("赫连铁树对$N哼了一声道：“这种小角色还想投身一品堂？”\n",me);
             return 1;
        }
        if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }
	if(combatexp>2000000)
        {
message_vision("赫连铁树对$N哼了一声道：“你武功太高了，已经没有适合给你的任务了。”\n",me);
             return 1;
        }



// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
message_vision("赫连铁树对$N冷冷一笑道：让你办的事如何了？\n", me);
message_vision("赫连铁树很不屑地瞟了$N一眼说道：你要是没本事，就拿点儿费
用出来我让别的人去。\n",me);
                   return 0;
             }
             else
             {
message_vision("赫连铁树对着$N叹了一口气：哎，我就再给你一次机会吧。\n", me);
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
        quest = QUESTH_D(tag)->query_quest();
        timep = quest["time"];

 //       while (quest["quest_type"] == "杀")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }

        time_period(timep, me);
        if(quest["quest_type"]=="杀")
             tell_object(me,"替我把『"+quest["quest"]+HIW"』给我杀了，别的差使以后再说。\n" NOR);
        else
             tell_object(me,"找回『"+quest["quest"]+HIW"』给我，别的差使以后再说。\n" NOR);
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

        tell_object(me,HIW "赫连铁树吩咐道：给你在" + time + "内");
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
                   message_vision("赫连铁树笑道：那我可就不客气了。\n",who);
                   return 1;
             }
           //  if (who->query("songxin"))
          //   {
           //        message_vision("你这家伙，明明是接的送信任务，怎么到我这儿来取消？银子没收！\n",who);
           //        return 1;
          //   }
             else
             if ( ob->value() < 2000)
             {
message_vision("赫连铁树一双尖针般的眼睛直盯着$N：这点钱可不够我们的开销！\n", who);
                   return 1;
             }
             else
             {
message_vision("赫连铁树笑道：那好，咱们买卖不成仁义在。想讨差使再找我吧！\n",who);
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->apply_condition("menpai_busy",5);
                   who->apply_condition("hxsd_busy",1+random(5));
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"赫连铁树说道：这不是我想要的。\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"赫连铁树说道：这是什么东西？我叫你办的差使你就这样糊弄？！\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"赫连铁树说道：真是废物！你没有在指定的时间内回来！\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"赫连铁树赞许地点头说道：不错！差使办得还不错！\n");
             exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
             pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
             score = quest["score"]/2 + random(quest["score"]/2);
             factor=who->query("quest_factor");
             destruct(ob);

             if (factor)
             {
                  exp=exp*factor/10;
                  pot=pot*factor/10;
                  score=score*factor/10;
             }
             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             if( bonus > 10000) bonus = 10000;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，"+ chinese_number(pot) + "点潜能，"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("quest", 0 );
             tell_object(who,HIW"恭喜你完成一个差使！\n"NOR);
             return 0;
        }
        return 1;
}
