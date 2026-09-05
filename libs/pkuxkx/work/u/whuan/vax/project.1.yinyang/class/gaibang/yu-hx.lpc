// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("余洪兴", ({"yu hongxing", "yu", "hongxing"}));
        set("title",MAG "丐帮" NOR + YEL "八袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 30);
        set("long",
                "这是位笑眯眯的丐帮八袋弟子，生性多智，外号小吴用。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 30);
        set("con", 22);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: heal :),
        }));
        set("dai",8);
        set("max_qi", 1520);
        set("max_jing", 330);
        set("neili", 1280);
        set("max_neili", 1280);
        set("jiali", 112);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set("combat_exp", 820000);

        set_skill("force", 118);
        set_skill("huntian-qigong", 116);
        set_skill("jiaohua-xinfa", 105);
        set_skill("strike", 118);
        set_skill("xianglong-zhang", 110);
        set_skill("dodge", 110);
        set_skill("xiaoyaoyou", 112);
        set_skill("parry", 111);
        set_skill("begging", 110);
        set_skill("stealing", 120);
        set_skill("checking", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

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
        if (ob->query("dai")<7)
        {
                command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<700){
            command("say 我可不收不忠于本帮之人.");
            return;
         }
        if (ob->query("dai")== 7 )
        {
                if( ob->query("int") < 25 ) return;
                command("say 唉，本帮诚信为本，只有七公他老人家和我才特别收些聪明徒儿，");
                command("say 大家都要为长远着想啊！");
                command("recruit " + ob->query("id"));
                if (this_player()->query("is_beggar"))
                        this_player()->set("title",MAG "丐帮" NOR + BLK + "污衣派" + YEL +"七袋" NOR + MAG "弟子" NOR);
                else    this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"七袋" NOR + MAG "弟子" NOR);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}


