// yin tianzheng.co.c
#include <title.h>
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include "bonus.h"
int ask_job();
int ask_fail();
void create()
{
        set_name("殷天正", ({ "yin tianzheng", "yin" }));
        set("nickname", HIW"白眉鹰王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","他是明教四大法王之一－－白眉鹰王。身着一件白衫，他白须白眉，
\n"
                   "威风凛凛。四大法王中数他年纪最大。他在鹰爪功上浸淫了几十年
\n"
                   "工夫，在明教中算得上一等好手。\n");
         set("gender", "男性");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("bonus",4);
        set("inquiry", ([
            
			"job" : (: ask_job :),
            "任务" : (: ask_job :),
			"fail" : (: ask_fail :),
			"失败" : (: ask_fail :),
            
            
       	]) );
        set_skill("force", 110);
        set_skill("guangming-shenghuogong", 100);
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set_skill("myingzhua-gong",120);
        set_skill("datengnuo-bufa", 100);
        set_skill("claw", 110);
        set_skill("literate", 100);
        map_skill("claw","myingzhua-gong");
        map_skill("force", "guangming-shenghuogong");
        map_skill("parry", "myingzhua-gong");
        map_skill("dodge", "datengnuo-bufa");
        prepare_skill("claw","myingzhua-gong");
        create_family("明教", 20, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
}void attempt_apprentice(object ob)
{
    if (ob->query("family/family_name")=="明教"&& ob->query("family/enter_time")>1303862399
     &&((!ob->query("chushi")&&ob->query("exp/mjnewbiejob")<40000)||(ob->query("chushi")&&ob->query("exp/mjnewbiejob")<5000)))
        {
            command("say 你对本教贡献不够，我暂时不能收你，多去帮帮杨左使吧。");
            return;
        }
         if ((string)ob->query("family/family_name")!="明教" )
        {
                command("say 我不收外派弟子。");
  command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }
        if ((int)ob->query("score")<500){
             command("sigh");
             command("say 你对本门不忠,这怎么能让本王相信你呢?");
             return;
            }
        if ((int)ob->query_skill("guangming-shenghuogong", 1) < 30) {
                command("say 你的光明圣火功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在光明圣火功上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=10)
        {
   command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
     command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
          ob->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
        return;
}

void re_rank(object student)
{
        student->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title")); 
        return;
}

int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("mingjiao/tasks/yingwang"))
    {
        tell_object(me,"没接任务就放弃？\n");
        return 1;
    }
    if (!me->query_temp("mingjiao/tasks/task2color"))
    {
        tell_object(me,"没接任务就放弃？\n");
        return 1;
    }
    else
    {
        tell_object(me,"好吧好吧，每个人的天资有区别，我也不难为你了。\n");
        me->delete_temp("mingjiao/tasks");
        me->set("mingjiaonewbiejob/fail",1);
        me->set("mingjiaonewbiejob/lastfail",2);
        me->delete("mingjiaonewbiejob/start");
        return 1;
    }
}

int ask_job()
{
    object ob=this_object();
    object me=this_player();
    int n;
    string* setcolor=({HIR,HIY,HIB,HIG,HIC,HIM,HIW});
    string color;
    n=sizeof(setcolor);
    n=random(n);
    color=setcolor[n];
    if (!me->query_temp("mingjiao/tasks/yingwang"))
    {
        tell_object(me,"我这里暂时没事，你去别处看看。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/task2color"))
    {
        tell_object(me,"接了任务就快点去做吧。\n");
        return 1;
    }
    else
    {
        me->set_temp("mingjiao/tasks/taskno",2);
        if (random(1000)>499)
        {
            message_vision("$N对$n道：你去练功房找(zhao)一件"+color+"钢刀"+NOR+"去武场打磨(mo)一下交给我。\n",ob,me);
            me->set_temp("mingjiao/tasks/task2blade",1);
            me->set_temp("mingjiao/tasks/task2color",n+1);
            return 1;
        }
        else
        {
            message_vision("$N对$n道：你去练功房找(zhao)一件"+color+"钢剑"+NOR+"去武场打磨(mo)一下交给我。\n",ob,me);
            me->set_temp("mingjiao/tasks/task2sword",1);
            me->set_temp("mingjiao/tasks/task2color",n+1);
            return 1;
        }
    }
}


int dest(object weapon)
{
	if(weapon)
	destruct(weapon);
	return 1;
}

int accept_object(object me, object weapon)
{
	if (me->query_temp("mingjiao/tasks/task2sword")
      &&me->query_temp("mingjiao/tasks/task2color")==weapon->query("color")
      &&weapon->query("mingjiaoquest")==1
      &&weapon->query("moed"))
    {
        tell_object(me,"不错不错，后生可畏啊。\n");
        me->delete("mingjiaonewbiejob/start");
        bonus(me);
        call_out("dest",1,weapon);
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/task2blade")
      &&me->query_temp("mingjiao/tasks/task2color")==weapon->query("color")
      &&weapon->query("mingjiaoquest")==2
      &&weapon->query("moed"))
    {
        tell_object(me,"不错不错，后生可畏啊。\n");
        me->delete("mingjiaonewbiejob/start");
        bonus(me);
        call_out("dest",1,weapon);
        return 1;
    }
    else
    {
        return notify_fail("这是什么玩意？\n");
    }
}