//daotong.c
//made by hacky
//modified by Zine for Qz newbiejob
inherit NPC;
#include <ansi.h>
#include "bonus.h"
int ask_help();
int ask_fail();
void create ()
{
 set_name("道童",({"daotong","dao","tong"}));
 set("long",@LONG
他是全真教的小道童.
LONG
    );
 set("title",HIB"全真派"NOR+YEL"道童"NOR);
 set("gender","男性");
 set("age",17);
 set("attitude","peaceful");
 set("shen_type",0);
  set("str",20);
  set("int",25);
  set("con",20);
  set("combat_exp",2500);
  set("score",1000);
  set("max_neili",200);
  set("neili",200);
  set_skill("force",30);
  set_skill("parry",25);
  set_skill("dodge",30);
  set_skill("unarmed",30);
  set_temp("parry/attack",17);
  set_temp("parry/damage",5);
  set_temp("parry/defense",20);
 create_family("全真派",6,"弟子");
 set("inquiry",([
               
                "help" : (:ask_help:),
                "帮忙" : (:ask_help:),
                "fail":   (: ask_fail() :),
                "失败":   (: ask_fail() :),
                ]));
	set("bonus",1);
  set("shen_type",1);set("score",200);setup();
 }

int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("qznewbiejob/task3"))
    {
        command("sign2");
        return 1;
    }
    me->delete_temp("qznewbiejob/task3");
    me->set("qznewbiejob_time",time());
    command("robot "+me->query("id"));
    return 1;
}

int ask_help()
{
    object me=this_player();
    string * task_list=({"找书","核对","誊写"});
    int n;
    object where,jing;
    if (!me->query_temp("qznewbiejob/task3/start"))
    {
        command("say 我这没什么事，你去别处看看吧。");
        return 1;
    }
    if (me->query_temp("qznewbiejob/task3/type"))
    {
        command("say 又一个光说不练的啊。");
        return 1;
    }
    n=random(sizeof(task_list));
    me->set_temp("qznewbiejob/task3/type",task_list[n]);
    if (n==0)
    {
        jing=new(__DIR__"obj/newbie-jing");
        while (!objectp(where) || 
            !where->isroom()||
            TASK_D->place_belong(where)=="不明区域"||
            base_name(where) == "/adm/daemons/taskd"||
            where->query("no_qznewbiejob"))
        {where=TASK_D->random_room("/d/quanzhen/");}
        jing->move(where);
        me->set_temp("qznewbiejob/task3/1where",where);
        command("say 我的前些天誊写的书不见了，但是肯定没带出全真，你帮我找回来好吗？");
    }
    if (n==1)
    {
        jing=new(__DIR__"obj/newbie-jing2");
        command("say 这本誊抄的道德经有个字似乎模糊了，你帮我找(zhao)出来吧。");
        tell_object(me,this_object()->query("name")+"递给你一本"+jing->query("name")+"。\n");
        jing->move(me);
    }
    if (n==2)
    {
        command("say 我肚子不太舒服，你能帮我在这里誊写(write)完道德经吗？");
    }
    return 1;
}

void init()
{
    object me=this_player(); 
    if (me->query_temp("qznewbiejob/task3/finish"))
    {
        me->delete_temp("qznewbiejob/task3/finish");
        bonus(me);
    }
}

int dest(object lizi)
{
	if(lizi)
	destruct(lizi);
	return 1;
}

int accept_object(object me, object lizi)
{
    int task_factor=1;
	if( lizi->query("id") == "daotong's jing"&&me->query_temp("qznewbiejob/task3/type")=="找书")
	{
        message_vision(this_object()->query("name")+"接过$N手里的书，大喜道：就是我的！\n",me);
	    me->delete_temp("qznewbiejob/task3");
        bonus(me);
	    call_out("dest",1,lizi);
        return 1;
    }
    if( lizi->query("id") == "daode jing"&&me->query_temp("qznewbiejob/task3/type")=="核对"&&me->query_temp("qznewbiejob/task3/complete"))
	{
        task_factor=task_factor+random(2);
        message_vision(this_object()->query("name")+"接过$N手里的书，大喜道：就是我的！\n",me);
	    me->delete_temp("qznewbiejob/task3");
        bonus(me);
	    call_out("dest",1,lizi);
        return 1;
    }
	else
    {
        return notify_fail(this_object()->query("name")+"道：不要不要就不要！\n");
    }
}