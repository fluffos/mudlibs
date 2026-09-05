// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("何不净", ({"he bujing", "he", "bujing"}));
        set("title",MAG "丐帮" NOR + YEL "七袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 30);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮七袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: heal :),
        }));
        set("dai",7);
        set("max_qi", 1200);
        set("max_jing", 300);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set("combat_exp", 400000);

        set_skill("force", 100);
        set_skill("huntian-qigong", 105);
        set_skill("jiaohua-xinfa", 105);
        set_skill("strike", 105);
        set_skill("xianglong-zhang", 105);
        set_skill("hand",100);
        set_skill("shexing-shou", 100);
        set_skill("blade", 100);
        set_skill("liuhe-dao", 100);
        set_skill("dodge", 95);
        set_skill("xiaoyaoyou", 100);
        set_skill("parry", 103);
        set_skill("begging", 90);
        set_skill("stealing", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("hand", "shexing-shou");
//      map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");
        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 19, "弟子");

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
        if ((int)ob->query("score")<500){
             command("sigh"+ob->query("id"));
             command("say 你不能忠于本帮,我怎能收你呢?");
             return;
          }        
        if (ob->query("dai")== 6 )
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
                command("say 你很爱打架吧？ 哈哈哈，好吧，我就收下你了！");
                command("recruit " + ob->query("id"));
                if (this_player()->query("is_beggar"))
                        this_player()->set("title",MAG "丐帮" NOR + BLK + "污衣派" + YEL +"六袋" NOR + MAG "弟子" NOR);
                else    this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"六袋" NOR + MAG "弟子" NOR);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}


