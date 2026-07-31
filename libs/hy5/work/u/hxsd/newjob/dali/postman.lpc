//[lover 1999]
#include <ansi.h>
#define QUEST_LETTER __DIR__"quest"  
inherit NPC;
//inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("大理将军",({"dali jiangjun","jiangjun"}));
        set("long","这是一个大理段家负责传送军机的将军，正被大堆信件包围着，看起来愁眉苦脸的样子。\n");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");
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
        if (ob->query("money_id"))
        {
               if(!who->query("quest") || ( ob->value() < 5000))
             {
                   message_vision("我正缺钱用，多谢您了！\n",who);
                   return 1;
             }
             else
             {
message_vision("大理将军叹了口气道：好吧，不想做就算了,我去另请高明。\n",who);
                   who->set("quest",0);
                   return 1;
             }
         }
return 0;
}

int give_quest()
{
        mapping quest ;
        object me,letter;
        int combatexp, timep, factor;

        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

   if((int)me->query("potential") > (500+(int)me->query("combat_exp")/1000))
{
 message_vision("大理将军对$N说道：“你的潜能太多了，我不能给你任务！”\n",me);
  return 1;
}
      if( me->query("family/family_name") != "大理段家")
            {
                message_vision("$N对着$n大喝一声：本派弟子才能送军机信件！\n", this_object(), me);
//                return 1;
            }
       if(combatexp < 80000)
       {
message_vision("大理将军对$N说：你经验不够，怕你送不了哟！\n",me);
         return 0;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("大理将军对$N说：你得把信帮我送到呀。\n", me);
                        return 0;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 1)
                 {
                   message_vision("大理将军对$N说：现在连我都闲得发慌，你还是等会再来吧。\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("大理将军对$N说：你来得正好，我这儿刚好有一批军机信件要送出去。\n",me);
}
        quest = QUEST_LETTER->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "把信送给『" + quest["quest"] + "』你的任务就完成了。\n" NOR);
        message_vision("$N给了$n一封信。\n",this_object(),me);
        letter = new(__DIR__"letter");
        letter->move(me);
        quest["quest_type"] = "把信送给";
        quest["exp_bonus"] = random(220) + 80;
        quest["pot_bonus"] = random(200) + 20;
        quest["score"] = 0;

        me->set_temp("tufei",0);
        me->set("quest", quest);
        me->set("task_time", (int)time() + timep);
        me->set("quest_factor", factor);
        me->set("last_task_time", time());
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

        if(d)
                time = chinese_number(d) + "天";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "大理将军说道：\n在" + time + "内");

                return 1;
}
