// yangxiao.co.c
#include <title.h>
inherit NPC;
inherit F_MASTER;
int adv();
void heal();
int ask_tasks();
int ask_finish();
int ask_fail();
#include <ansi.h>
#include "bonus.h"
void create()
{
        set_name("杨逍", ({ "yang xiao", "yang" }));
        set("title",GRN "明教" NOR + YEL +"光明左使" NOR);
        set("long","明教光明左使。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
                (: adv :),
        }));
        set("bonus",2);
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 30);
        set("combat_exp", 800000);
        set("score", 5000);
        set("inquiry", ([
	
         "任务": (: ask_tasks :),
         "job": (: ask_tasks :),
         "复命": (: ask_finish :),
         "fuming": (: ask_finish :),
         "失败": (: ask_fail :),
         "fail": (: ask_fail :),
	
	    ]));
        set_skill("force", 120);
        set_skill("guangming-shenghuogong", 120);
        set_skill("dodge", 150);
        set_skill("parry", 120);
        set_skill("blade", 140);
        set_skill("datengnuo-bufa", 120);
        set_skill("hanbing-zhang", 150);
        set_skill("lieyan-dao",150);
        set_skill("strike", 120);
        set_skill("literate", 110);
        set_skill("shenghuo-lingfa", 50);
        map_skill("force", "guangming-shenghuogong");
        map_skill("parry", "lieyan-dao");
        map_skill("blade","lieyan-dao");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        prepare_skill("strike","hanbing-zhang");
        create_family("明教", 20, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/gangdao")->wield();
        carry_object("/d/mingjiao/obj/qingshan")->wear();
}

int adv()
{
    if (random(100)>96)
    {
        command("mp 本派弟子在黄河岸边发现一处浅滩，可以搬(ban)起石头泅渡(swim)过河。\n");
    }
}

int ask_finish()
{
    object me=this_player();
    object ob=this_object();
    if (me->query("combat_exp")<=10000&&me->query_temp("mingjiao/tasks/newnewbiefinish"))
    {
        me->delete("mingjiaonewbiejob/start");
        message_vision("$N对$n道：幸苦了。\n",ob,me);
        bonus(me);
        return 1;
    }
    /*if (me->query("mingjiaonewbiejob/damingfinish"))
    {
        me->delete_temp("mingtasks");
        bonus(me);
        me->delete("mingjiaonewbiejob/lucky");
        me->delete("mingjiaonewbiejob/damingfinish");
        message_vision("$N道：这次帮助明国，$n幸苦了。\n",ob,me);
        
        return 1;
    }*/
    else
    {
        message_vision("$N道：有其他复命去找四大法王。\n",ob);
        return 1;
    }
}

int ask_fail()
{
    object me=this_player();
    if (!me->query("mingjiaonewbiejob/start")&&!me->query_temp("mingjiao/tasks/newnewbie"))
    {
        command("say 我这里只能放弃嘹望任务，四大法王的任务找他们本人去放弃。");
        return 1;
    }
    command("say 既然如此，也就罢了吧。\n");
    if (me->query_temp("mingjiao/tasks/newnewbie"))
    {
        me->delete_temp("mingjiao/tasks/newnewbie");
    }
    me->delete("mingjiaonewbiejob/start");
    me->set("mingjiaonewbiejob/fail",1);
    return 1;
}

int ask_tasks()
{
    object ob=this_object();
    object me=this_player();
    string *tasks=({"金毛狮王","白眉鹰王","青翼蝠王","紫杉龙王"});
    int tasknumber,cdtime=90+90*(int)me->query("mingjiaonewbiejob/fail");
    if (time()<1303862399&&!wizardp(me))
    {
        command("say 新任务2011年4月26日12点后开放。");
        return 1;
    }
    if (me->query("family/family_name")!="明教")
    {
        command("say 有趣有趣，你不是明教弟子，跑来干嘛？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
		return 1;
    }
    /*if (me->query("mingjiaonewbiejob/damingfinish"))
    {
        tell_object(me,"大明国事了之后，你应该和我复命一下。\n");
        return 1;
    }
    if (me->query("mingjiaonewbiejob/daming"))
    {
        tell_object(me,"叫你去大明国了，还不快去做？\n");
        return 1;
    }*/
    if (me->query("mingjiaonewbiejob/start"))
    {
        tell_object(me,"你已经领过任务了，还不快去做？\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks"))
    {
        tell_object(me,"你已经领过任务了，还不快去做？\n");
        return 1;
    }
    if (time()-(int)me->query("mingjiaonewbiejob/lastgive")<cdtime)
    {
        tell_object(me,"你刚做完任务不久，先去休息一会吧。\n");
        return 1;
    }
    me->add_busy(1);
    if (me->query("combat_exp")<10000)
    {
        command("say 了望塔是我教一处关键所在，你去了望(liaowang)山下，观察敌踪吧。");
        me->set_temp("mingjiao/tasks/newnewbie",1);
        me->set("mingjiaonewbiejob/start",1);
        me->set("mingjiaonewbiejob/lastgive",time());
        return 1;
    }
    /*if (random(100)>101)//取消大明任务
    {
        //大明任务
        command("say 大明国是我教旁支，现在正在遭受刀兵，你去帮帮他们吧。\n");
        command("say 他们正在防备，想必城门紧闭，但你持我手令，可从正阳门或通济门进入，去找吏部尚书看能帮他什么。\n");
        command("whisper "+me->query("id")+" 大明任务比较复杂，如果不会做，可以参考新手攻略以及大明任务攻略。");
        command("whisper "+me->query("id")+" 新手攻略 http://www.pkuxkx.net/forum/viewthread.php?tid=20440&highlight=%C3%F7%BD%CC%D0%C2%CA%D6");
        command("whisper "+me->query("id")+" 大明任务攻略 http://www.pkuxkx.net/forum/viewthread.php?tid=20461&highlight=%B4%F3%C3%F7");
        me->set("mingjiaonewbiejob/daming",1);
        return 1;
    }*/
	me->set("mingjiaonewbiejob/start",1);
	if (me->query("mingjiaonewbiejob/lastfail"))
		{
            if (me->query("mingjiaonewbiejob/lastfail"))
            {
                tasknumber=(int)me->query("mingjiaonewbiejob/lastfail")-1;
                command("say 现在"+tasks[tasknumber]+"正在找人帮忙，你去看看吧。\n");
                me->delete("mingjiaonewbiejob/lastfail");
                me->delete("mingjiaonewbiejob/fail");
                me->set("mingjiaonewbiejob/lastgive",time());
                if (tasknumber==0)
                {
                    me->set_temp("mingjiao/tasks/shiwang",1);
                }
                if (tasknumber==1)
                {
                    me->set_temp("mingjiao/tasks/yingwang",1);
                }
                if (tasknumber==2)
                {
                    me->set_temp("mingjiao/tasks/fuwang",1);
                }
                if (tasknumber==3)
                {
                    me->set_temp("mingjiao/tasks/longwang",1);
                }
                return 1;
            }
        }
        tasknumber=random(sizeof(tasks));
        while (me->query("combat_exp")<5000 && tasknumber==2)
        {
            tasknumber=random(sizeof(tasks));
        }
        
        command("say 现在"+tasks[tasknumber]+"正在找人帮忙，你去看看吧。\n");
        me->set("mingjiaonewbiejob/lastgive",time());
        if (tasknumber==0)
        {
            me->set_temp("mingjiao/tasks/shiwang",1);
        }
        if (tasknumber==1)
        {
            me->set_temp("mingjiao/tasks/yingwang",1);
        }
        if (tasknumber==2)
        {
            me->set_temp("mingjiao/tasks/fuwang",1);
        }
        if (tasknumber==3)
        {
            me->set_temp("mingjiao/tasks/longwang",1);
        }
        return 1;
   
}
void attempt_apprentice(object ob)
{
    if (ob->query("family/family_name")=="明教"&& ob->query("family/enter_time")>1303862399 &&ob->query("exp/mjnewbiejob")<60000)
        {
            command("say 你对本教贡献不够，我暂时不能收你，多来帮帮我吧。");
            return;
        }
         if ((string)ob->query("family/family_name")!="明教" )
        {
         command("say 我不收外派弟子。");
         command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }if ((int)ob->query("shen") < 5000) {
                command("say 我杨逍乃顶天立地的好汉，我的弟子应该扶危济困.");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本使一定收你。");
                return;
        }
        if ((int)ob->query("score")<500){
            command("sigh"+ob->query("id"));
            command("say 你若为本门立点功劳,本使一定收你");
            return;      
            }
        if ((int)ob->query_skill("guangming-shenghuogong", 1) < 30) {
          command("say 你的光明圣火功太低了，无法修习我的功夫。");
          command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在光明圣火功上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=1)
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
          ob->set("title",GRN "明教" NOR + YEL +"护法" NOR);
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
void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
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

