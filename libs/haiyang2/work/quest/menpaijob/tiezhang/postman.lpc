//[lover 1999]
#include <ansi.h>
#define QUEST_LETTER __DIR__"quest"  
inherit NPC;
//inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("铁掌帮长老",({"tiezhang jobshi","jobshi"}));
        set("long","这是一个铁掌帮负责送劝降书的长老.\n");
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
                "任务": "我正在发愁怎么处理这些劝降书，你来的正好! \n",
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
message_vision("铁掌帮长老叹了口气道：好吧，不想做就算了,我去另请高明。\n",who);
                   who->apply_condition("menpai_busy",8);
                   who->apply_condition("hxsd_busy",8);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   destruct(present("xin",who));
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
        if(me->query("quest"))
            {
                      message_vision("铁掌帮长老对着$N摇了摇头说：你现在还有别的任务!\n", me);
                      return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("铁掌帮长老对着$N摇了摇头说：你等会再来!\n", me);
                      return 1;
            }
if (present("xin",me))
            {
                      message_vision("铁掌帮长老对着$N摇了摇头说：你先把身上的信送到再说!\n", me);
                      return 1;
            }

      if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("铁掌帮长老对着$N摇了摇头说：现在没有任务,你等会再来!\n", me);
                      return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("铁掌帮长老对着$N摇了摇头说：你等会再来!\n", me);
                      return 1;
            }
      if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("铁掌帮长老对着$N摇了摇头说：你办事不利,等会再来!\n", me);
                      return 1;
            }


//   if((int)me->query("potential") > (500+(int)me->query("combat_exp")/1000))
//{
// /message_vision("铁掌帮长老对$N说道：“你的潜能太多了，我不能给你任务！”\n",me);
//  return 1;
//}
      if( me->query("family/family_name") != "铁掌帮")
            {
                message_vision("$N对着$n大喝一声：本派弟子才能送劝降书！\n", this_object(), me);
                return 1;
            }
      if( (int)me->query_skill("guiyuan-tunafa",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
       if(combatexp < 80000)
       {
message_vision("铁掌帮长老对$N说：你经验不够，怕你送不了哟！\n",me);
         return 0;
        }
     if(me->is_busy())
        return notify_fail("你现在正忙。\n");
     if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("铁掌帮长老对$N说：你得把劝降书帮我送到呀。\n", me);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                        return 0;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 1)
                 {
                   message_vision("铁掌帮长老对$N说：现在连我都闲得发慌，你还是等会再来吧。\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("铁掌帮长老对$N说：你来得正好，我这儿刚好有一批劝降书要送出去。\n",me);
}
        quest = QUEST_LETTER->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "把劝降书送给『" + quest["quest"] + "』你的任务就完成了。\n" NOR);
        message_vision("$N给了$n一封劝降书。\n",this_object(),me);
        letter = new(__DIR__"letter");
        letter->move(me);
        quest["quest_type"] = "把劝降书送给";
//        quest["exp_bonus"]=quest["exp_bonus"]+ 100;
//        quest["pot_bonus"]=quest["pot_bonus"]+ 50;
        quest["exp_bonus"] = random(320) + 100;
        quest["pot_bonus"] = random(260) + 50;
        quest["score"] = 0;
me->apply_condition("menpai_busy",9);
me->apply_condition("hxsd_busy",9);
        me->set("tzjob",2);
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

        tell_object(me, HIW "铁掌帮长老说道：\n在" + time + "内");

                return 1;
}
