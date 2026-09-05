// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("黎生", ({"li sheng", "li", "sheng"}));
        set("title",MAG "丐帮" NOR + YEL "八袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 38);
        set("long",
                "这是位生性刚直，嫉恶如仇的丐帮八袋弟子。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 18);
        set("con", 20);
        set("dex", 23);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: heal :),
        }));
        set("dai",8);
        set("max_qi", 1500);
        set("max_jing", 300);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 110);

        set("combat_exp", 800000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set_skill("force", 111);
        set_skill("huntian-qigong", 112);
        set_skill("strike", 115);
        set_skill("xianglong-zhang", 105);
        set_skill("blade", 110);
        set_skill("liuhe-dao", 110);
        set_skill("dodge", 110);
        set_skill("xiaoyaoyou", 112);
        set_skill("parry", 112);
        set_skill("staff", 110);
        set_skill("begging", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("parry", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 19, "弟子");
        set("shen_type",1);set("score",1000);setup();
		carry_object("/d/gaibang/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
                command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<7)
        {
                command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<700){
           command("sigh");
           command("say 小兄弟你对本帮有二心,这叫我怎么能相信你呢?");
           return;
           }          
        if (ob->query("dai")== 7 )
        {
                if( ob->query("shen") < 0 ) return;
                command("say 好，有你这样一等一的人才做我徒弟，我欢喜还来不及呢！");
                command("recruit " + ob->query("id"));
                if (this_player()->query("is_beggar"))
                  this_player()->set("title",MAG "丐帮" NOR + WHT + "污衣派" + YEL +"七袋" NOR + MAG "弟子" NOR);
                else    
                	this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"七袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, ob->query("title"));
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}



