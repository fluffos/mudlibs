#include <ansi.h>
// /d/dalicheng/shami.c
// paladin
// modified by Zine Tianlong Newbie job
inherit NPC;
int ask_job();
int ask_fail();
int adv();
void create()
{
        set_name("沙弥", ({ "sha mi", "sha", "mi" }));
        set("long",
                "他是天龙寺的小沙弥。\n");
        set("title",RED "天龙寺" NOR + GRN "弟子" NOR);
        set("gender", "男性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        set("max_qi", 200);
        set("max_jing", 150);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 3000);
        set("score", 3000);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 20);
        set_skill("parry", 30);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
        set("times",3);
        set("inquiry", ([
        "job":   (: ask_job() :),
        "工作":   (: ask_job() :),
        "任务":   (: ask_job() :),
        "fail":   (: ask_fail() :),
        "失败":   (: ask_fail() :),
        ]));
        create_family("天龙寺", 17, "弟子");
        setup();
        carry_object("/d/dalicheng/obj/yrobe")->wear();
        call_out("adv",1);
}

int adv()
{
    int i;
    object *ob;
	if (!environment()||base_name(environment())!="/d/tianlong/zhonglou")
	{
		return 1;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("family/family_name")=="天龙寺"&&ob[i]->query("combat_exp")<100000&&time()-ob[i]->query_temp("天龙广告")>600)
        {
            ob[i]->set_temp("天龙广告",time());
            command("tell "+ob[i]->query("id")+" 天龙新手任务已经开放，你可以到我这里接到新手任务。\n");
        }
    }
	remove_call_out("adv");
    call_out("adv",1200+random(100));
    return 1;
}

int ask_fail()
{
    object me=this_player();
    object jing;
    if (!me->query_temp("tlnewbiejob"))
    {
        command("say 有嘛？有嘛？什么都没给你啊。");
        return 1;
    }
    if (present("fo jing",me))
    {
        jing=present("fo jing",me);
    }
    if (!jing)
    {
        me->delete_temp("tlnewbiejob");
        me->set("tlnewbiejob_time",time());
        command("slash "+me->query("id"));
        command("say 去吧去吧，如今的人啊。");
        return 1;
    }
    if (jing->query("is_fo_jing"))
    {
        destruct(jing);
    }
    me->delete_temp("tlnewbiejob");
    me->set("tlnewbiejob_time",time());
    command("slash "+me->query("id"));
    command("say 去吧去吧，如今的人啊。");
    return 1;
}

int job2(object me)
{
    object where,jushi;
    int n=random(100);
    int pin=1+random(100000);
    if (n>66)
    {
        while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/dalicheng/");}
        jushi=new(__DIR__"jushi2");
        jushi->move(where);
        jushi->set("pin",pin);
        jushi->set("gender",me->query("gender"));
        me->set_temp("tlnewbiejob/adv2/pin",pin);
        command("say "+jushi->name()+"家里很有钱，你到大理城"+where->query("short")+"向他化缘(huayuan)重塑佛祖金身吧。\n");
        return 1;
    }
    else if (n>33)
    {
        while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/chengdu/");}
        jushi=new(__DIR__"jushi2");
        jushi->move(where);
        jushi->set("pin",pin);
        jushi->set("gender",me->query("gender"));
        me->set_temp("tlnewbiejob/adv2/pin",pin);
        command("say "+jushi->name()+"家里很有钱，你到成都"+where->query("short")+"向他化缘(huayuan)重塑佛祖金身吧。\n");
        return 1;
    }
    else
    {
        while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/kunming/");}
        jushi=new(__DIR__"jushi2");
        jushi->move(where);
        jushi->set("pin",pin);
        jushi->set("gender",me->query("gender"));
        me->set_temp("tlnewbiejob/adv2/pin",pin);
        command("say "+jushi->name()+"家里很有钱，你到昆明"+where->query("short")+"向他化缘(huayuan)重塑佛祖金身吧。\n");
        return 1;
    }
}

int job1(object me)
{
    object where,jushi,jing;
    object *inv;
    int i;
    int n=random(100);
    int pin=1+random(100000);
    if (n>74)
    {
        while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/tianlong/");}
        jushi=new(__DIR__"jushi");
        jushi->set("gender",me->query("gender"));
        jushi->move(where);
        jing=new("/d/tianlong/obj/jing");
        jing->move(me);
        jushi->set("pin",pin);
        me->set_temp("tlnewbiejob/adv1/pin",pin);
        command("say "+jushi->name()+"前些日子在我寺捐了很多香火钱，你到天龙"+where->query("short")+"把这本佛经送(song)给他吧。\n");
        return 1;
    }
    else if (n>49)
    {
        while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/dalicheng/");}
        inv=all_inventory(where);
        for (i=0;i<sizeof(inv);i++)
        {
            if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类")
				continue;
            if(inv[i]->query("uni_target") || inv[i]->query("random_npc"))
				continue;
            jushi=inv[i];
        }
        if (!jushi)
        {
            jushi=new(__DIR__"jushi");
            jushi->set("gender",me->query("gender"));
            jushi->move(where);
        }
        jing=new("/d/tianlong/obj/jing");
        jing->move(me);
        jushi->set("pin",pin);
        me->set_temp("tlnewbiejob/adv1/pin",pin);
        command("say "+jushi->name()+"前些日子在我寺捐了很多香火钱，你到大理城"+where->query("short")+"把这本佛经送(song)给他吧。\n");
        return 1;
    }
    else if (n>24)
    {
        while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/kunming/");}
        inv=all_inventory(where);
        for (i=0;i<sizeof(inv);i++)
        {
            if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类")
				continue;
            if(inv[i]->query("uni_target") || inv[i]->query("random_npc"))
				continue;
            jushi=inv[i];
        }
        if (!jushi)
        {
            jushi=new(__DIR__"jushi");
            jushi->set("gender",me->query("gender"));
            jushi->move(where);
        }
        jing=new("/d/tianlong/obj/jing");
        jing->move(me);
        jushi->set("pin",pin);
        me->set_temp("tlnewbiejob/adv1/pin",pin);
        command("say "+jushi->name()+"前些日子在我寺捐了很多香火钱，你到昆明"+where->query("short")+"把这本佛经送(song)给他吧。\n");
        return 1;
    }
    else
    {
        while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/chengdu/");}
        inv=all_inventory(where);
        for (i=0;i<sizeof(inv);i++)
        {
            if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类")
				continue;
            if(inv[i]->query("uni_target") || inv[i]->query("random_npc"))
				continue;
            jushi=inv[i];
        }
        if (!jushi)
        {
            jushi=new(__DIR__"jushi");
            jushi->set("gender",me->query("gender"));
            jushi->move(where);
        }
        jing=new("/d/tianlong/obj/jing");
        jing->move(me);
        jushi->set("pin",pin);
        me->set_temp("tlnewbiejob/adv1/pin",pin);
        command("say "+jushi->name()+"前些日子在我寺捐了很多香火钱，你到成都"+where->query("short")+"把这本佛经送(song)给他吧。\n");
        return 1;
    }
}

int ask_job()
{
    object me=this_player();
    int n=random(100);
    
    if (me->query("family/family_name")!="天龙寺")
    {
        command("say 施主有什么需要我帮忙的吗？");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (time()-me->query("tlnewbiejob_time")<180&&me->query("combat_exp")>45000)
    {
        tell_object(me,"你刚刚才来过，歇息一会吧。\n");
        return 1;
    }
    if (me->query_temp("tlnewbiejob/lead/start"))
    {
        command("say 我不是让你去帮助迷路的人了吗？");
        return 1;
    }
    if (me->query_temp("tlnewbiejob/adv1/pin"))
    {
        command("say 我不是让你去送佛经了吗？");
        return 1;
    }
    if (me->query_temp("tlnewbiejob/adv2/pin"))
    {
        command("say 我不是让你去化缘了吗？");
        return 1;
    }
    me->set("tlnewbiejob_time",time());
    if (me->query("combat_exp")<10000)
    {
        if (!me->query_skill("kurong-shengong",1))
        {
            me->set_skill("kurong-shengong",1);
            me->set_temp("天龙入门教内功",1);
            command("say 哎呀，你一点内功基础都不会啊，这怎么行？");
            tell_object(me,"小沙弥指点了你一些内功。\n");
            tell_object(me,HIC"你的『枯荣禅功』进步了！\n"NOR);
        }
        if (!me->query_skill("force",1))
        {
            me->set_skill("force",1);
            me->set_temp("天龙入门教内功",1);
            command("say 哎呀，你一点内功基础都不会啊，这怎么行？");
            tell_object(me,"小沙弥指点了你一些内功。\n");
            tell_object(me,HIC"你的『基本内功』进步了！\n"NOR);
        }
        if (me->query_temp("天龙入门教内功"))
        {
            command("say 你知道吗，有了内功，不会用，等于零，你要enable force kurong-shengong。");
            me->delete_temp("天龙入门教内功");
        }
        command("say 你刚入本门，一切还不熟悉，应该尽快习惯天龙寺的生活。");
        command("say 这几点，我必须和你说清楚。");
        tell_object(me,HIG+this_object()->query("name")+"告诉你：凌晨的早课在三元宫举行，你跟着大家念(nian)经就好了。\n早晨新弟子必须去钟楼敲(knock)钟，到了晌午，你要去厨房帮厨(bangchu)，\n正午时分别忘了在雨花院打坐(dazuo)并至少获得一点内力，\n到了下午，要从山脚挑(tiao)一担水到后院，记得早一点时间去后院拿水桶，\n傍晚又要帮厨(bangchu)了，晚上在睡房睡(sleep)好了。这就是天龙弟子的一天。\n"+HIR+"你可以使用time命令获得当前北侠的时分。\n"+NOR);
        return 1;
    }
    else if (me->query("combat_exp")<30000)
    {
        command("say 近年来道路变化极大，很多人都难辨方向，你去天龙寺山脚看看有没有人迷路了，有的话去帮帮他们吧。");
        me->set_temp("tlnewbiejob/lead/start",1);
        return 1;
    }
    else
    {
        if (n>66)
        {
            job1(me);
            return 1;
        }
        else if (n>15)
        {
            job2(me);
            return 2;
        }
        else
        {
            command("say 近年来道路变化极大，很多人都难辨方向，你去天龙寺山脚看看有没有人迷路了，有的话去帮帮他们吧。");
            me->set_temp("tlnewbiejob/lead/start",1);
            return 1;
        }
    }
}


