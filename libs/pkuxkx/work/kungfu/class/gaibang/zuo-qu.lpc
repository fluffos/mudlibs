// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"
#include "bonus.h"
#include <title.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
void create()
{
        set_name("左全", ({"zuo quan", "zuo", "quan"}));
        set("title",MAG "丐帮" NOR + YEL "七袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 35);
        set("long",
                "这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 26);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: heal :),
        }));
        set("dai",7);
        set("max_qi", 1200);
        set("max_jing", 300);
        set("neili", 1010);
        set("max_neili", 1010);
        set("jiali", 106);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );
        set("inquiry",
                ([
                        "job" : (: ask_job :),
                        "任务" : (: ask_job :),
                        "fail" : (: ask_fail :),
                        "失败" : (: ask_fail :),
                ]));
        set("combat_exp", 408000);

        set_skill("force", 103);
        set_skill("huntian-qigong", 100);
        set_skill("strike", 100);
        set_skill("xianglong-zhang", 103);
        set_skill("dodge", 100);
        set_skill("xiaoyaoyou", 101);
        set_skill("parry", 100);
        set_skill("begging", 80);
        set_skill("checking", 80);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 20, "弟子");
        set("shen_type",1);set("score",1000);setup();
		carry_object("/d/gaibang/obj/jing_cloth")->wear();
}

void init()
{
    object me=this_player();
    if (me->query_temp("gbnewbiejob/checkfinish"))
    {
        command("nod "+me->query("id"));
        bonus(me);
    }
    return;
}
void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
                command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<6)
        {
                command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<600){
          command("say 我虽然是个粗人,但也知效忠本帮,你这种不忠不义之人,我不会收你的.");
          return;
          }        
        if (ob->query("dai")== 6 )
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
                command("say 希望你能好好学习本门武功，将来为丐帮争一口气！。");
                command("recruit " + ob->query("id"));
                if (this_player()->query("is_beggar"))
                  this_player()->set("title",MAG "丐帮" NOR + WHT + "污衣派" + YEL +"六袋" NOR + MAG "弟子" NOR);
                else    
                	this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"六袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, ob->query("title"));
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}

int ask_job()
{
    object me=this_player();
    string *dir=({"东","南","西","北",});
    int i=random(sizeof(dir));
    if (me->query("family/family_name")!="丐帮")
    {
        command("say 阁下不是我帮弟子，这是何意？");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        command("say 等你忙完再来找我吧。");
        return 1;
    }
    if (me->query("combat_exp")>10000+(int)me->query("int")*(int)me->query("str")*(int)me->query("dex")*(int)me->query("con")/10)
    {
        command("say 你的武艺已经不错了，去看看彭、鲁两位长老有何任务吧。");
        return 1;
    }
    if (me->query("gbnewbiejob/start"))
    {
        command("say 你上次任务还没有完成呢！");
        return 1;
    }
    if (time()-me->query("gbnewbiejob/lasttime")<120&&me->query("combat_exp")>10000)
    {
        command("say 你刚刚做过任务，先去休息一会吧。");
        return 1;
    }
    else
    {
        me->set("gbnewbiejob/start","check");
        me->set("gbnewbiejob/lasttime",time());
        me->set_temp("gbnewbiejob/check",dir[i]);
        message_vision("$N对$n说道：人人都知道我们丐帮消息天下最为灵通，打探消息就靠你们这些跑腿的了，你去"+dir[i]+"门打听(dating)些消息回来。\n",this_object(),me);
        return 1;
    }
}


int ask_fail()
{
    object me=this_player();
    object ob=this_object();
    
    if (me->query("family/family_name")!="丐帮")
    {
        command("say 阁下不是我帮弟子，这是何意？");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        command("say 等你忙完再来找我吧。");
        return 1;
    }
    if (!me->query("gbnewbiejob/start"))
    {
        command("say 你没接过任务啊！");
        return 1;
    }
    me->delete("gbnewbiejob/start");
    me->delete_temp("gbnewbiejob");
    command("say 没关系，没做到就算了吧。");
    punish(me);
    return 1;
}