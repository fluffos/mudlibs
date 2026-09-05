// xiexun.co.c
#include <title.h>
inherit NPC;
inherit F_MASTER;
void heal();
#include <ansi.h>
#include "bonus.h"
int ask_job();
int ask_fail();
int ask_fuming();
void create()
{
        set_name("谢逊", ({ "xie xun", "xie" }));
        set("nickname", YEL"金毛狮王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","他是明教四大法王之一－－金毛狮王。身着一件黄衫，满面红光。\n
"
                   "他有着一头的黄发，只因早年修习特异武功之故。他武艺高强，在 \
n"
                   "明教中是数一数二的人物。\n");
         set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 30);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
       set("combat_exp", 500000);
       set("bonus",5);
       set("inquiry", ([
            
			"job" : (: ask_job :),
            "任务" : (: ask_job :),
			"fail" : (: ask_fail :),
			"失败" : (: ask_fail :),
            "fuming" : (: ask_fuming :),
            "复命" : (: ask_fuming :),
       	]) );
		set("no_teach_skills",({"qishang-quan"}));
        set_skill("force", 110);
		set_skill("qishang-quan",150);
        set_skill("guangming-shenghuogong", 100);
        set_skill("dodge", 110);
        set_skill("parry", 120);
        set_skill("lieyan-dao",120);
        set_skill("datengnuo-bufa", 100);
        set_skill("blade", 110);
        set_skill("literate", 200);
        set_skill("cuff",150);
        map_skill("blade","lieyan-dao");
         map_skill("cuff","qishang-quan");
        map_skill("force", "guangming-shenghuogong");
        map_skill("parry", "qishang-quan");
        map_skill("dodge", "datengnuo-bufa");
        prepare_skill("cuff","qishang-quan");
        create_family("明教", 20, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
        carry_object("/d/mingjiao/obj/gangdao")->wield();
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
                command("say 本王不收外派弟子。");
  command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }
        if ((int)ob->query("score")<500) {
               command("heng"+ob->query("id"));
               command("本王最恨欺师灭祖之人,我怎能收你?");
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
   command("say "+RANK_D->query_respect(ob)+"多次背信弃义，本王怎可收你。");
                return;
        }
        if ((int)ob->query("shen") < 5000) {
                command("say 我谢逊乃顶天立地的好汉，我的弟子应该扶危济困.");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本王一定收你。");
                return;
        }
     command("say 好吧，"+RANK_D->query_respect(ob)+"！本王就收下你了！\n");
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
void init()
{
        object ob;
        mapping fam;
        ob = this_player();
        if ( (int)ob->query("shen") <0 && ob->query("family/master_id") == "xie xun")
        {
   command("say 你多次杀人越货，胡作非为，本王岂能仍是你的师傅。\n");
   command("expell "+ ob->query("id"));
        }
        ::init();
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
    if (!me->query_temp("mingjiao/tasks/shiwang"))
    {
        tell_object(me,"我给过你任务吗？\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/taskno")!=1)
    {
        tell_object(me,"你确定我给过你任务？\n");
        return 1;
    }
    if (!me->query_temp("mingjiao/tasks/task1suc"))
    {
        tell_object(me,"你这么快就回来，圣火有别的弟子接替看守吗？\n");
        return 1;
    }
    else
    {
        tell_object(me,"不错不错，后生可畏啊。\n");
        me->delete("mingjiaonewbiejob/start");
        bonus(me);
        return 1;
    }
}

int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("mingjiao/tasks/shiwang"))
    {
        tell_object(me,"没接任务就放弃？\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/taskno")!=1)
    {
        tell_object(me,"没接任务就放弃？\n");
        return 1;
    }
    else
    {
        tell_object(me,"好吧好吧，每个人的天资有区别，我也不难为你了。\n");
        me->delete_temp("mingjiao/tasks");
        me->set("mingjiaonewbiejob/fail",1);
        me->set("mingjiaonewbiejob/lastfail",1);
        me->delete("mingjiaonewbiejob/start");
        return 1;
    }
}

int ask_job()
{
    object ob=this_object();
    object me=this_player();
    object pushan,where;
    if (!me->query_temp("mingjiao/tasks/shiwang"))
    {
        tell_object(me,"我这里暂时没事，你去别处看看。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/taskno")==1)
    {
        tell_object(me,"接了任务就快点去做吧。\n");
        return 1;
    }
    else
    {
        me->set_temp("mingjiao/tasks/taskno",1);
        tell_object(me,"你去圣火坛看守(kanshou)一下圣火吧。后山小路上可以捡到柴火，记得多捡(jian)点，蒲扇我不记得丢哪了，应该就在明教附近吧。\n");
        tell_object(me,"圣火坛可是我教一个大秘密，在明教大殿enter就进去了。\n");
        pushan=new("/d/mingjiao/obj/pushan");
        pushan->set("owner",me->query("id"));
        
        while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
          where->query("no_mj_newbie"))
        {where=TASK_D->random_room("/d/mingjiao/");}
        me->set_temp("mingjiao/tasks/task1pushanwhere",where);
        pushan->move(where);
        
        return 1;
    }
}

