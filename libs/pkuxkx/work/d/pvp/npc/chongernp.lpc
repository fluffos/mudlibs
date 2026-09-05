// chongerx.c by becool 2008-11-21
inherit FAMILY_NPC;
#include <ansi.h>;
int do_start(string arg);
int do_onlykill(string arg);
int do_nohalt();
int do_noperform(string arg);
int do_noyun(string arg);
void create()
{
        set_name(HIR"虫二"NOR, ({ "chong er", "chong", "chonger" }) );
        set("nickname",HIW"冷面鬼"NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
               "这人跟外面那个长得一模一样，只是眼神似乎更凌厉些。\n");
        set("combat_exp",900000000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("apply/attack", 500+random(500));
        set("apply/defense", 500+random(500));
        set("max_qi", 70000);
        set("max_jing", 70000);
        set("max_neili", 70000);
        set("neili", 70000);
        family_skill(this_object(), "huashan2", 500+random(250), 1);
        set("chat_chance_combat", 80);
        set("no_get",1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}
void init()
{
        ::init();
        add_action("do_start", "kill");
        add_action("do_onlykill","hit");
        add_action("do_onlykill","fight");
        add_action("do_onlykill","hitall");
        add_action("do_onlykill","killall"); 
        add_action("do_nohalt","halt");
        add_action("do_noperform","perform");
        add_action("do_noperform","exert");
        add_action("do_nobusy","jiuming");
}
int do_onlykill(string arg)
{
        write("在这里还是动真格吧！\n");
        return 1;
}
int do_nobusy()
{
        int level = this_player()->query("level");
        if (this_player()->is_fighting() && this_player()->is_busy())
        {
           if (level < 31)
                 this_player()->start_busy(random(7-level/10));
           else if (level < 61)
                 this_player()->start_busy(random(10-level/10));
           else  this_player()->start_busy(random(13-level/10));     
        message_vision(HIW"$N大呼救命，"HIR"虫二"HIW"伸出手指朝$N臀部一戳，$N竟慢慢的缓过气来。\n"NOR,this_player());
        return 1;
        }
}
int do_nohalt()
{
        if (this_player()->is_fighting() && !wizardp(this_player()))
        {
        message_vision(HIW"$N已经杀红了眼，再也停不下来了。\n"NOR,this_player());
        return 1;
        }
}
int do_noperform(string arg)
{
        if(arg == "sword.feilong"
        || arg == "strike.leiting"
        || arg == "sword.cixue"
        || arg == "finger.feihua"
        || arg == "finger.yizhi")
                {
                if (this_player()->is_fighting() && !this_player()->is_busy())
                        {
                        this_player()->set("qi", this_player()->query("qi")/10);
                        message_vision(HIW"$N用尽全身力气拼死一搏，真气耗尽，一口鲜血从口中喷了出来。\n"NOR,this_player());
                        }
                return 0;
                }
}
int do_start(string arg)
{
        object ob1, ob2;
        object old_target;
        ob1 = this_player();
        if( !arg || arg=="" ) return 1;
        if ( this_object()->query_temp("busy") )
                return notify_fail("每次只能有两人参加格斗。\n");
        if ( arg == "chong" || arg == "chong er" || arg == "chonger" )
             {
             command("say " + "想找死？\n");
             return 1;
             }
        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁格斗？\n");
        if(!ob2->is_character() || ob2->is_corpse())
           return notify_fail("你看清楚一点，它是活物吗!!!! \n");
        if (ob1 == ob2)    return notify_fail("想自杀回家去！\n");
        if( objectp(old_target = ob1->query_temp("pending/fight")) )
            {
            tell_object(old_target, YEL + ob1->name() + "取消了和你
比试的念头。\n" NOR);
            return 1;
            }
        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N对着$n说道：“这位"
                        + RANK_D->query_respect(ob2) + "，别怪"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "手下无情了！”\n", ob1, ob2
);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, HIW "如果你愿意和对方进行格斗，请你也对" + ob1
->name() + "("+(string)ob1->query("id")+")"+ "下一次 kill 指令。\n" NOR);
                write(HIW "稍等下，对方正在考虑要不要跟你拼命。\n" NOR);
                return 1;
        }
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");
        remove_call_out("check");
        remove_call_out("fighting");
        command("say " + "好，三秒后格斗将自动开始！\n");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");
        call_out("fighting",3,ob1,ob2);
        return 1;
}
void fighting(object ob1, object ob2)
{
        command("say " + "FIGHT!\n");
        call_out("check",1,ob1,ob2);
        ob1->kill_ob(ob2);
        ob2->kill_ob(ob1);
}
void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name")
            + "与" + ob2->query("name") + "，现在开始单挑！\n");
}
