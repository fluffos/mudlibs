// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"
#include <title.h>
inherit NPC;
inherit F_MASTER;
void do_answer(string);
void get_class(string arg,object ob);

void create()
{
        set_name("裘万家", ({"qiu wanjia", "qiu", "wanjia"}));
        set("title",MAG "丐帮" NOR + YEL "二袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 27);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮二袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 20);
        set("chat_msg", ({
              (: heal :),
        }));

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 50);
        set("dai",2);

        set("combat_exp", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set_skill("force", 45);
        set_skill("huntian-qigong", 45);
        set_skill("blade", 45);
        set_skill("liuhe-dao", 45);
        set_skill("hand", 45);
        set_skill("shexing-shou", 45);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 45);
        set_skill("parry", 43);
        set_skill("begging", 50);
        set_skill("stealing", 40);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
        map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");

        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 25, "弟子");
        set("shen_type",1);set("score",1000);setup();
		carry_object("/d/gaibang/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        object obj;
        if((int)ob->query("betrayer")>=3)
        {
                command("say 你多次背信弃义，我怎可信你!\n");
                return;
        }
        if ((string)ob->query("family/family_name")=="丐帮")
        {
                command("say 岂敢！岂敢！！");
                return;
        }
        if ((ob->query("is_beggar2")) && !(ob->query("is_beggar")))
        {
        	      command("say "+RANK_D->query_respect(ob)+"居然判出丐帮，怎么又回头了呢？");
                return;
        }	
        if( (ob->query("combat_exp") < 2000 || ob->query("reborn/chushi")>=1))
        {
                command("say 本帮弟子分为「污衣派」和「净衣派」，不知" + RANK_D->query_respect(ob) + "愿意加入哪一派呢？\n");
                input_to("get_class",ob);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;


}

void get_class(string arg,object ob)
{
        if (arg == "污衣派")
        {
                ob->set_temp("bai_qiu/污衣派",1);
                call_out("recruit_id",1,ob);
        }
        else    if (arg == "净衣派")
                {
                        ob->set_temp("bai_qiu/净衣派",1);
                        call_out("recruit_id",1,ob);
                }
                else
                {
                        write("请选择 污衣派 或者 净衣派\n");
                        input_to("get_class",ob);
                }
        return;
}

void recruit_id(object ob)
{
        object obj;
        
        if (ob->query_temp("bai_qiu/净衣派"))
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你作「净衣派」弟子了。");
                ob->set("dai", 1);
                ob->set("is_beggar2", 1);
                command("recruit " + ob->query("id"));
                this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"一袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
        }
        else
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你作「污衣派」弟子了。");
                ob->set("dai", 1);
                ob->set("is_beggar", 1);
                if (ob->query("class")!="bonze")
                ob->set("class", "beggar");
                command("recruit " + ob->query("id"));
                if(!present("budai", this_player()))
                {
                      obj=new("/d/gaibang/obj/gaibang-bag");
                      obj->move(ob);
                }
                this_player()->set("title",MAG "丐帮" NOR + WHT + "污衣派" + YEL +"一袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
        }
        return;
}       

