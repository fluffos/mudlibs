//dadi.c 任务使
// [lsg 1999/11/24]

inherit NPC;
#define QUEST_KILL __DIR__"quest"  
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
        set_name("长老", ({ "zhang lao", "zhang", "lao"}));
        set("title", HIG"昆仑派"NOR);
        set("gender", "男性" );
        set("age", 82);
        set("str", 950);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"一位的长老。专门负责给本派弟子各种任务.\n");
        set("combat_exp", 50000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
        set_skill("force", 300);
        set_skill("zhemei-shou", 300);
        set_skill("unarmed", 500);
        set_skill("xiantian-qigong", 500);

         map_skill("unarmed","zhemei-shou");
       map_skill("force","xiantian-qigong");
        
        set("inquiry", ([
              "job"  : "本派弟子可以在我这用quest领任务啦，我不会为难你们的。\n",       
]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string room;
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

        if( me->query("family/family_name") != "昆仑派")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }
        if (me->query("kunlun_job")==1)  
            {
                      message_vision("$N对着$n你身上的任务还没完成呢!难道你把我要找的人给杀了?\n", this_object(), me);
                      return 1;
            }
        if(combatexp<10000)
        {
tell_object(me,"\n昆仑派长老笑着说到，你的武功还不行....”\n");
             return 1;

        }

        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
tell_object(me,"昆仑派长老瞪了你一眼说道，我刚才要你找的东西呢？\n");
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                   return 0;
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


        if (random(2) == 0)
        {
     quest = QUESTS_D(tag)->query_quest();
	}
       else
        if (random(2) == 1)
        {
     quest = QUESTH_D(tag)->query_quest();
	}
       else
     quest = QUESTS_D(tag)->query_quest();
        timep = quest["time"];

        time_period(timep, me);
        if(quest["quest_type"]=="杀")
             tell_object(me,"把『"+quest["quest"]+HIC"』带来，他想看看他是什么模样。\n" NOR);
        else
             tell_object(me,"找回『"+quest["quest"]+HIC"』此物对本派有用。\n" NOR);

        me->set("quest", quest);
        me->set("kunlun_job", 1);
        me->set("task_time", (int) time()+(int) quest["time"]);
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

        tell_object(me,HIC "昆仑派长老说道：请帮我在" + time + "内");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                  tell_object(who,"没找到？你真差劲，看来还是请别的弟子帮忙算了！\n");
                   who->apply_condition("menpai_busy",7);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->set("kunlun_job", 0);
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"昆仑派长老看了看$P交上来的钱说道，太少了，这么点你也好意思拿出手！\n");
                   return 1;
             }
             else
             {

tell_object(who,"昆仑派长老说道，好吧，这次就算了，下不为例。\n");
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob"); 
                  who->apply_condition("menpai_busy",7);
                   who->set("quest",0);
                   who->set("kunlun_job", 0);
                  return 1;
             }
        }
        if(!(quest = who->query("quest")))
        {
             tell_object(who,"昆仑派长老说道：你秀逗了，我要的不是这个。\n");
             return 0;
        }

	if( !ob->is_character() ) {
        tell_object(who,"昆仑派长老火冒三丈：这是什么？想鱼目浑珠呀，真是气死老夫了！\n");
        return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"昆仑派长老火冒三丈：这是什么？想鱼目浑珠呀，真是气死老夫了！\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
             tell_object(who,"昆仑派长老说道：对不起，时间过了，别的弟子刚把那个家伙给抓来！\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"昆仑派长老高兴地说道：太好了！我就是要这个家伙，你真有本事！\n");
             exp = quest["exp_bonus"] + 300;
             pot = quest["pot_bonus"] + 260;
             score = quest["score"] + random(20);

//             exp = 200 + random(250);
//             pot = 100 + random(150);
//             score = 10 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
//             if( bonus > 100000) bonus = 100000;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
who->start_busy(3);
             tell_object(who,HIW"恭喜你又完成一个任务！\n"NOR);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，\n"+ chinese_number(pot) + "点潜能，\n"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("quest", 0 );
             who->set("kunlun_job", 0);
	if( ob->is_character() ) {
       call_out("destroying", 0,ob);                              
//   1    remove_call_out("destroying");
//             destruct(ob);
	}
//             return 1;
}
        return 1;
}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "昆仑派长老狞笑着说：我是无敌不死版！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

void destroying(object ob)
{   
   destruct(ob);
}