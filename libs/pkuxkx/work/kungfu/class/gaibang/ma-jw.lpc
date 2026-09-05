// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("马俱为", ({"ma juwei", "ma", "juwei"}));
        set("title",MAG "丐帮" NOR + YEL "七袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 35);
        set("long",
                "这是位武艺精强，却沉默寡言的丐帮七袋弟子。\n");
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 22);
        set("con", 18);
        set("dex", 25);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: heal :),
        }));
        set("dai",7);
        set("max_qi", 1500);
        set("max_jing", 300);
        set("neili", 1210);
        set("max_neili", 1210);
        set("jiali", 116);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set("combat_exp", 509000);

        set_skill("force", 115);
        set_skill("huntian-qigong", 112);
        set_skill("hand", 115);
        set_skill("shexing-shou", 105);
        set_skill("dodge", 108);
        set_skill("xiaoyaoyou", 120);
        set_skill("parry", 120);
        set_skill("staff", 115);
        set_skill("begging", 110);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "shexing-shou");

        prepare_skill("hand", "shexing-shou");

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
        if (ob->query("dai")<6)
        {
                command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<600){
            command("shake"+ob->query("id"));
            command("say 小兄弟如果对本帮做出点功劳来,我一定收你!");
            return;
           }
        if (ob->query("dai")== 6 )
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
                command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
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


