// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"

inherit NPC;
inherit F_MASTER;

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

        set("combat_exp", 408000);

        set_skill("force", 103);
        set_skill("huntian-qigong", 100);
        set_skill("jiaohua-xinfa", 100);
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
        setup();
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
                        this_player()->set("title",MAG "丐帮" NOR + BLK + "污衣派" + YEL +"六袋" NOR + MAG "弟子" NOR);
                else    this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"六袋" NOR + MAG "弟子" NOR);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}

