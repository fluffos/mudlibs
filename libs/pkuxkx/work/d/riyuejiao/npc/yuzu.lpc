//yuzu Zine Ry newbie job
inherit NPC;
#include "riyuenpc.h"
#include "/d/riyuejiao/bonus.h"
#include <ansi.h>
int ask_job();
int ask_fail();
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title","狱头");
        set("long","他是日月神教监狱的狱头，监狱大小事务都归他管。\n");
	    set("gender", "男性");
        set("no_get",1);
        set("age", 45);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("combat_exp", 500000);
        set("random_npc",1);
        set("inquiry", ([
            "东方不败" : "东方教主的名字也是你叫得的？",
            "东方教主" : (: ask_df :),
	        "任我行" : (: ask_ren :),
            "帮助": (: ask_job :),
            "help": (: ask_job :),
            "job": (: ask_job :),
            "失败": (: ask_fail :),
            "cancel": (: ask_fail :),
            "fail": (: ask_fail :),
	      ]) );
        set("bonus",85);
        set_skill("force", 60);
        set_skill("riyue-shengong", 60);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	    set_skill("strike",40);
	    set_skill("kaishan-zhang",40);
        set_skill("feitian-shenfa", 40);
        set_skill("literate",60);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "kaishan-zhang");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike","kaishan-zhang");
	    create_family("日月神教", 18, "弟子");
        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
        call_out("adv",1);
}

int adv()
{
    int i;
    object *ob;
	if (!environment()||base_name(environment())!="/d/riyuejiao/prison_entry")
	{
		return 1;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("family/family_name")=="日月神教"&&ob[i]->query("combat_exp")>=75000&&ob[i]->query("combat_exp")<=55000&&time()-ob[i]->query_temp("日月广告")>600)
        {
            ob[i]->set_temp("日月广告",time());
            command("tell "+ob[i]->query("id")+" 日月神教新手任务已经开放，你可以到我这里接到新手任务。\n");
        }
    }
	remove_call_out("adv");
    call_out("adv",1200+random(100));
    return 1;
}

int ask_fail()
{
    object me=this_player();
    if (me->query("family/family_name")!="日月神教")
    {
        command("shrug");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query_temp("rynewbiejob/prison/start"))
    {
        tell_object(me,"我没叫你去干吗呀？\n");
        return 1;
    }
    me->delete_temp("rynewbiejob");
    me->set("rynewbiejob/lasttime",time());
    command("kao");
    command("ks "+me->query("id"));
    command("say 一边凉快去，这点活都完成不了。");
    return 1;
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    string *task=({"送牢饭","巡视牢房","逼供",});
    string *roomid = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });
    object key;
    int n,m;
    if (me->query_temp("rynewbiejob/prison/degree")>3+random(2))
    {
        command("say 不错不错，有人代劳就是好啊。");
        bonus(me);
        return 1;
    }
    
    if (me->query("family/family_name")!="日月神教")
    {
        command("shrug");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/prison/start"))
    {
        tell_object(me,"叫你去就快去做，等什么呢？\n");
        return 1;
    }
    if (time()-me->query("rynewbiejob/lasttime")<120-random(20))
    {
        tell_object(me,"我这没别的什么活，你迟点再来吧。\n");
        return 1;
    }
    if (me->query("combat_exp")<75000)
    {
        tell_object(me,"你的能力恐怕还不能胜任这里的工作。\n");
        return 1;
    }
    
    else
    {
            n=random(sizeof(task));
            command("say 黑木崖上的奸细越来越多，被我们关在里监狱里，你去"+task[n]+"吧。");
            me->set_temp("rynewbiejob/prison/start",n+1);
            key=new("/d/riyuejiao/obj/key");
            if (n==0)
            {
                m=random(sizeof(roomid));
                command("say 记得你要去送饭(songfan)的是"+roomid[m]+"号房。");
                me->set_temp("rynewbiejob/prison/room",roomid[m]);
                if (!present("laofang yaoshi",me))
                {
                    key->move(me);
                    command("say 这串钥匙可以开启牢门。");
                }
                
            }
            if (n==1)
            {
                me->set_temp("rynewbiejob/prison/xl_time",time());
            }
            if (n==2)
            {
                m=random(sizeof(roomid));
                command("say 你要拷打(kaoda)的人被关在"+roomid[m]+"号房。");
                me->set_temp("rynewbiejob/prison/room",roomid[m]);
                if (!present("laofang yaoshi",me))
                {
                    key->move(me);
                    command("say 这串钥匙可以开启牢门。");
                }
            }
            return 1;
    }
       
}

void unconcious()
{
    die();
}

void die()
{
    this_object()->fullme();
    return;
}