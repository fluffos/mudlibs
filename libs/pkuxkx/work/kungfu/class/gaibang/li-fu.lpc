// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("李斧头", ({"li futou", "li", "futou"}));
        set("title",MAG "丐帮" NOR + YEL "六袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 26);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮六袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("start_room","/d/gaibang/underwd");
        set("chat_chance", 100);
        set("chat_msg", ({
              (: heal :),
        }));
        set("dai",6);
        set("max_qi", 1000);
        set("max_jing", 300);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 90);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set("combat_exp", 200000);

        set_skill("force", 90);
        set_skill("huntian-qigong", 95);
        set_skill("blade", 92);
        set_skill("liuhe-dao", 94);
        set_skill("hand", 95);
        set_skill("shexing-shou", 95);
        set_skill("dodge", 95);
        set_skill("xiaoyaoyou", 90);
        set_skill("parry", 93);
        set_skill("begging", 90);
        set_skill("stealing", 90);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
        map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "shexing-shou");

        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 21, "弟子");
        set("shen_type",1);set("score",1000);setup();
		carry_object("/d/gaibang/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
              command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob) + "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<5)
        {
               command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<500){
           command("shake"+ob->query("id"));
           command("say 我是不会收对本帮不忠之人的.");
           return;
           }
        if (ob->query("dai")== 5 )
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
                command("recruit " + ob->query("id"));
                if (this_player()->query("is_beggar"))
                  this_player()->set("title",MAG "丐帮" NOR + WHT + "污衣派" + YEL +"五袋" NOR + MAG "弟子" NOR);
                else    
                	this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"五袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, ob->query("title"));
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}


