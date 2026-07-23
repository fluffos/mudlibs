#include <ansi.h>
#define QUEST_LETTER(x) ("/quest/letter/qlist" + x)  
//星星(lywin)2000/4/30日改前辈weixiaobao.c成此信使！不胜惶恐！切莫怪之！
inherit NPC;
inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name(HIW"信使"NOR,({"foxmail"}));
        set("long","这是一个专门为人送信的信使，为人机警能干，江湖人称之为“狐狸”。\n");

        set("title",HIG"狐狸"NOR);
        set("gender", "男性");
        set("attitude", "friendly");
         set("age", 40);
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 3000000);
        set("score", 10000);
        set("env/wimpy", 10000);
        set("inquiry", ([
                "任务": "我正在发愁怎么处理这些信件，你来的正好! \n",
        ]) );
        set("no_get", 1);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("cuff", 175);
        set_skill("parry", 170);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");

}

int accept_object(object who, object ob)
{
  if(who->query("combat_exp") > 100000)
        {
                message_vision("信使对$N说：您已是成名人物了，这种小事怎敢劳您大驾？！\n",who);
                return 0;
        }

        if ((int)who->query_condition("hxsd_busy"))  
            {
                    message_vision("$N对着$n摇了摇头说：你做别的任务办事不利,等会再来!\n", this_object(), who);
                    return 1;
            }

        if (ob->query("money_id"))
        {
             if(!who->query("quest") || ( ob->value() < 2000))
             {
                   message_vision("我正缺钱用，多谢您了！\n",who);
                   return 1;
             }
             else
             {
message_vision("信使叹了口气道：好吧，不想做就算了,我去另请高明。\n",who);
                   who->set("quest",0);
                   who->delete("songxin");
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->apply_condition("hxsd_busy",1+random(4));
                   if (ob = present("xin", this_player()))
                   {
                   message_vision("信使将信收了回去！\n",who);
                   destruct(ob);     
                   }
                   return 1;
             }
         }
return 0;
}

int give_quest()
{
        mapping quest ;
        object me,letter,ob;
        int j, combatexp, timep,factor,num;
        string tag = "30000";
        string *levels = ({
                        "500",
                        "10000",
                        "30000",
                        "50000",
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
  if(combatexp < 500)
                {
message_vision("信使轻蔑的看了$N一眼说：你就这点本事？你可不要路也不识得！\n",me);
                  return 0;
          }
  if(combatexp > 100000)
        {
                message_vision("信使对$N说：您已是成名人物了，这种小事怎敢劳您大驾？！\n",me);
                return 0;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("信使对$N说：你得把信帮我送到呀。\n", me);
                        return 0;
                }
        }
//   此处设置送信的间隔时间。如果不需等待可以将之关上！使送信可以随时送！
             if (((int)time() - (int)me->query("last_task_time")) < 10)
                 {
                   message_vision("信使对$N说：现在没信可以送，你还是等会再来吧。\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("信使对$N说：你来得正好，我这儿刚好有一批信件要送出去。\n",me);
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

        quest = QUEST_LETTER(tag)->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "把信送给『" + quest["quest"] + "』你的任务就完成了。\n" NOR);
        message_vision("$N给了$n一封信。\n",this_object(),me);
        if (ob = present("xin", this_player()))
         {
             message_vision("信使将以前的信收了回去！\n",me);
             destruct(ob);
             letter = new(__DIR__"letter");
             letter->move(me);
             quest["quest_type"] = "把信送给";
             quest["exp_bonus"] = quest["exp_bonus"];
             quest["pot_bonus"] = quest["pot_bonus"];
             quest["score"] = 0;

             me->set("quest", quest);
             me->set("songxin",1);
             me->set("task_time", (int)time() + timep);
             me->set("quest_factor", factor);
             me->set("last_task_time", time());
             return 1;     
         }
         else
         {
            letter = new(__DIR__"letter");
            letter->move(me);
            quest["quest_type"] = "把信送给";
            quest["exp_bonus"] = quest["exp_bonus"];
            quest["pot_bonus"] = quest["pot_bonus"];
            quest["score"] = 0;

            me->set("quest", quest);
            me->set("songxin",1);
            me->set("task_time", (int)time() + timep);
            me->set("quest_factor", factor);
            me->set("last_task_time", time());
            return 1;
         }
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

        if(d)
                time = chinese_number(d) + "天";

        else
                time = "";
        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "信使说道：\n在" + time + "内");


                return 1;
}

