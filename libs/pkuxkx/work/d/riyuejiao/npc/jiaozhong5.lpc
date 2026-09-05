//jiaozhong4.c	日月教众
//by bing
inherit NPC;
#include "riyuenpc.h"
#include <ansi.h>
int ask_job();
void create()
{
        set_name("看管竹篓的弟子", ({ "di zi", "jiaozhong","dizi" }));
        set("long","他是日月神教教下弟子，负责看管连接黑木崖上下的竹篓。\n");
	    set("gender", "男性");
        set("zhulou_dizi",1);
        set("no_get",1);
        set("age", 35);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("combat_exp", 50000);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }));
        set("inquiry", ([
            "东方不败" : "东方教主的名字也是你叫得的？",
            "东方教主" : (: ask_df :),
	        "任我行" : (: ask_ren :),
            "帮助": (: ask_job :),
            "help": (: ask_job :),
	      ]) );

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
	    create_family("日月神教", 22, "弟子");
        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
        call_out("adv",1);
}

int adv()
{
    int i;
    object *ob;
	if (!environment()||base_name(environment())!="/d/riyuejiao/cunlu3")
	{
		return 1;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("family/family_name")=="日月神教"&&ob[i]->query("combat_exp")>=15000&&ob[i]->query("combat_exp")<=55000&&time()-ob[i]->query_temp("日月广告")>600)
        {
            ob[i]->set_temp("日月广告",time());
            command("tell "+ob[i]->query("id")+" 日月神教新手任务已经开放，你可以到我这里接到新手任务。\n");
        }
    }
	remove_call_out("adv");
    call_out("adv",1200+random(100));
    return 1;
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    
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
    if (me->query("rynewbiejob/zhulou/start"))
    {
        tell_object(me,"还不快去做，等什么呢？\n");
        return 1;
    }
    if (time()-me->query("rynewbiejob/lasttime")<120)
    {
        tell_object(me,"我这没别的什么活，你迟点再来吧。\n");
        return 1;
    }
    if (me->query("combat_exp")<15000)
    {
        tell_object(me,"你只是个普通杂役弟子，不能做这种技术活。\n");
        return 1;
    }
    if (me->query("combat_exp")>55000)
    {
        tell_object(me,"这种活对你来说太大材小用了。\n");
        return 1;
    }
    else
    {
            command("say 上黑木崖的竹篓快坏掉了，你去把它换了吧，在竹林劈(pi)下竹子后，削(xiao)下竹条，在黑木崖下编(bian)成竹篓换上去就好了。");
            me->delete("rynewbiejob");
            me->set("rynewbiejob/zhulou/start",1);
            me->set("rynewbiejob/lasttime",time());
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