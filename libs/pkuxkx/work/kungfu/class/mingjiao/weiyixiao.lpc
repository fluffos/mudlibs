// weiyixiao.co.c
// changed by fast
#include <ansi.h>
#include <title.h>

inherit NPC;
inherit F_MASTER;
#include "bonus.h"
void heal();
int ask_job();
int ask_fail();
int ask_fuming();
void create()
{
        set_name("韦一笑", ({ "wei yixiao", "wei" }));
        set("nickname", HIC"青翼蝠王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","他是明教四大法王之一－－青翼幅王韦一笑。身着一件青衫。他脸色
泛青，\n"
                   "可能是修习寒冰绵掌之故。他的轻功独步天下，凭此一技在江湖上闯
出了 \n"
                   "青翼幅王的名声。\n");
         set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 30);
        set("bonus",3);
        set("inquiry", ([
            
			"job" : (: ask_job :),
            "任务" : (: ask_job :),
			"fail" : (: ask_fail :),
			"失败" : (: ask_fail :),
            "fuming" : (: ask_fuming :),
            "复命" : (: ask_fuming :),
       	]) );
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
set("chat_chance_combat", 100);
set("chat_msg_combat", ({
(: perform_action , "strike.shixue" :),
}));
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
          set("combat_exp",400000);
        set_skill("force", 110);
        set_skill("guangming-shenghuogong", 100);
        set_skill("dodge", 200);
        set_skill("parry", 120);
        set_skill("hanbing-zhang",100);
        set_skill("datengnuo-bufa", 200);
        set_skill("strike", 110);
        set_skill("literate", 100);
        map_skill("force", "guangming-shenghuogong");
        map_skill("parry", "hanbing-zhang");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        prepare_skill("strike","hanbing-zhang");
        create_family("明教", 20, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/qingshan")->wear();
}
void init()
{
        object ob;
        mapping myfam;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "明教") &&
                       (int)ob->query("combat_exp")>1000000 &&
                        (!wizardp(ob))) {
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
}
void do_killing(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
void attempt_apprentice(object ob)
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
        if ((int)ob->query_skill("guangming-shenghuogong", 1) < 30) {
                command("say 你的光明圣火功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在光明圣火功上多下点功夫？");
                return;
        }
       if ((int)ob->query("shen") >-10000)
        {
                command("say 我韦一笑最看不过眼满肚子伪善道德的人。");
                command("say " + RANK_D->query_respect(ob) + "若能杀他" +
                        "几个伪君子，我一定收你。");
                return;
        }
        if ((int)ob->query("score") < 500)
          {
             command("say 我不收对师门不忠的人!");
             command("heng");
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
  

int ask_fuming()
{
    object me=this_player();
    if (!me->query_temp("mingjiao/tasks/fuwang"))
    {
        tell_object(me,"我给过你任务吗？\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/taskno")!=3)
    {
        tell_object(me,"你确定我给过你任务？\n");
        return 1;
    }
    if (!me->query_temp("mingjiao/tasks/task3suc"))
    {
        tell_object(me,"你找到奸细了吗？\n");
        return 1;
    }
    else
    {
        message_vision("$N把刚采的人血交给了了$n,$n一饮而尽，面色红润得多了。\n",me,this_object());
        tell_object(me,"不错不错，后生可畏啊。\n");
        me->delete("mingjiaonewbiejob/start");
        bonus(me);
        return 1;
    }
}

int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("mingjiao/tasks/fuwang"))
    {
        tell_object(me,"没接任务就放弃？\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/taskno")!=3)
    {
        tell_object(me,"没接任务就放弃？\n");
        return 1;
    }
    else
    {
        tell_object(me,"好吧好吧，每个人的天资有区别，我也不难为你了。\n");
        me->delete_temp("mingjiao/tasks");
        me->set("mingjiaonewbiejob/fail",1);
        me->set("mingjiaonewbiejob/lastfail",3);
        me->delete("mingjiaonewbiejob/start");
        return 1;
    }
}

int ask_job()
{
    object ob=this_object();
    object me=this_player();
    object jianxi,where;
    if (!me->query_temp("mingjiao/tasks/fuwang"))
    {
        tell_object(me,"我这里暂时没事，你去别处看看。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/taskno")==3)
    {
        tell_object(me,"接了任务就快点去做吧。\n");
        return 1;
    }
    else
    {
        me->set_temp("mingjiao/tasks/taskno",3);
        jianxi=new("/d/mingjiao/npc/jianxi");
        jianxi->set("owner",me->query("id"));
        
        while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
          where->query("no_mj_newbie"))
        {where=TASK_D->random_room("/d/mingjiao/");}
        me->set_temp("mingjiao/tasks/task3jianxiwhere",where);
        jianxi->move(where);
        tell_object(me,"我好久没有饮人血了，听说六大派派了一个叫"+jianxi->query("name")+"的奸细来到明教附近，你去把他揪出来吧。\n");
        
        
        return 1;
    }
}