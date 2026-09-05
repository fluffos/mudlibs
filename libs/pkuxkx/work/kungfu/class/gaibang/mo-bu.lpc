// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"
#include <title.h>
inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("莫不收", ({"mo bushou", "mo", "bushou"}));
        set("title",MAG "丐帮" NOR + YEL "三袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 27);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮三袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: heal :),
        }));
        set("dai",3);
        set("max_qi", 720);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 34);

        set("combat_exp", 20000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set_skill("force", 50);
        set_skill("huntian-qigong", 55);
        set_skill("blade", 55);
        set_skill("liuhe-dao", 55);
        set_skill("hand", 55);
        set_skill("shexing-shou", 55);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 55);
        set_skill("parry", 63);
        set_skill("begging", 50);
        set_skill("stealing", 60);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
        map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");
        
        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 24, "弟子");
        set("shen_type",1);set("score",1000);setup();
        carry_object("/d/city/obj/gangdao")->wield();
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
        if ((int)ob->query("score")<200){
           command("say 不行.本帮弟子都是忠心为帮的,我看你对本帮还不够忠心.");
           return;}  
        if (ob->query("dai")<2)
        {
               command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if (ob->query("dai")== 2 )
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
                command("recruit " + ob->query("id"));
                if (this_player()->query("is_beggar"))
                  this_player()->set("title",MAG "丐帮" NOR + WHT + "污衣派" + YEL +"二袋" NOR + MAG "弟子" NOR);
                else    
                	this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"二袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}

