// zhike.c 知客                              
//made by hacky

#include <ansi.h>
#include "bonus.h"
inherit NPC;

void heal();
int adv();
int ask_job();
int ask_fail();
void create()
{
	set_name("杂役道人", ({ "zayi daoren", "daoren" }));
	set("long", 
		"他是全真教的管杂役的道人。\n");
	set("gender", "男性");
	set("title", HIB"全真教" NOR + GRN "道长" NOR);
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
        }) );

	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("quanzhen-jian", 20);
	set_skill("daoxue-xinfa", 20);
       set_skill("xiantian-gong",40);
	set_skill("literate", 20);

	
	map_skill("parry", "quanzhen-jian");
        map_skill("force","xiantian-gong");
	map_skill("sword", "quanzhen-jian");


        create_family("全真派",4,"弟子");
	set("bonus",2);
	set("inquiry", ([
        "job":   (: ask_job() :),
        "工作":   (: ask_job() :),
        "任务":   (: ask_job() :),
        "fail":   (: ask_fail() :),
        "失败":   (: ask_fail() :),
    ]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
    call_out("adv",1);
}

int adv()
{
    int i;
    object *ob;
    if (!environment()||base_name(environment())!="/d/quanzhen/gongmen")
	{
		return 1;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("family/family_name")=="全真派"&&ob[i]->query("combat_exp")<(int)ob[i]->query("int")*600&&time()-ob[i]->query_temp("qz广告")>600)
        {
            ob[i]->set_temp("qz广告",time());
            command("tell "+ob[i]->query("id")+" 全真派新手任务已经开放，你可以到我这里接到新手任务。\n");
        }
    }
	remove_call_out("adv");
    call_out("adv",1200+random(100));
    return 1;
}

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}



int accept_fight(object me)
{
 command ("say 我与"+RANK_D->query_respect(me)+"无冤无仇,为何要打打杀杀?");
 command ("sigh"+me->query("id"));
 return 0;
 }

int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("qznewbiejob/task1"))
    {
        command("sign2");
        return 1;
    }
    me->delete_temp("qznewbiejob/task1");
    me->set("qznewbiejob_time",time());
    command("robot "+me->query("id"));
    return 1;
}

int ask_job()
{
    object me=this_player();
    object saoba;
    
    if (me->query("family/family_name")!="全真派")
    {
        command("say 我派弟子众多，不需要外人帮忙。");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (time()-me->query("qznewbiejob_time")<150&&me->query("combat_exp")>40000)
    {
        tell_object(me,"你刚刚才来过，歇息一会吧。\n");
        return 1;
    }
    if (me->query_temp("qznewbiejob/task1/start"))
    {
        command("say 我不是让你去清扫石阶了吗？");
        return 1;
    }
    me->set("qznewbiejob_time",time());
    if (me->query("combat_exp")<(int)me->query("int")*600)
    {
        command("say 你去把从山下石阶到宫门的一段路去扫(sao)干净。");
        me->set_temp("qznewbiejob/task1/start",1);
        if (!present("da saoba",me))
        {
            saoba=new(__DIR__"obj/saoba");
            saoba->move(me);
            tell_object(me,this_object()->query("name")+"给你一把大扫把。\n");
        }
        return 1;
    }
    else
    {
        command("say 你的经验够多了，去别处看看吧。");
        return 1;
    }
    
}

void init()
{
    object me=this_player();
    object ob=this_object();
    int task_factor;
    if (me->query_temp("qznewbiejob/task1/start"))
    {
        if (me->query_temp("qznewbiejob/task1/1/finish")
            &&me->query_temp("qznewbiejob/task1/2/finish")
            &&me->query_temp("qznewbiejob/task1/3/finish")
            &&me->query_temp("qznewbiejob/task1/4/finish")
            &&me->query_temp("qznewbiejob/task1/5/finish")
            &&me->query_temp("qznewbiejob/task1/6/finish")
            &&me->query_temp("qznewbiejob/task1/7/finish"))

        {
            command("say 这么快就打扫完了？后生可畏啊。");
            task_factor=2;
            bonus(me);
            me->delete_temp("qznewbiejob/task1");
            return;
        }
    }
}
  

