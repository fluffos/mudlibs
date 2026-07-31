#include <ansi.h>
// song.c 宋远桥

inherit NPC;
inherit F_MASTER;

string ask_me();
void heal();

void create()
{
        set_name("宋远桥", ({ "song yuanqiao", "song" }));
       set("nickname", RED "武当首侠" NOR);

        set("long",
                "他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
                "身穿一件干干净净的灰色道袍。\n"
                "他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 150000);
        set("score", 60000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.zhen" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 100);
        set_skill("taiji-shengong", 80);
	set_skill("move", 80);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 60);
           set_skill("cuff", 100);
        set_skill("taiji-quan", 80);
        set_skill("parry", 80);
        set_skill("sword", 80);
      set_skill("taiji-jian", 60);
      set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
           map_skill("cuff", "taiji-quan");
      map_skill("parry", "taiji-jian");
      map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        set("inquiry", ([
                "秘籍" : (: ask_me :),
        ]));

        set("book_count", 1);

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "武当派")
	{
		command("say 我只收本门弟子，"+ RANK_D->query_respect(ob) + "可先拜谷虚师侄");
		return;
	}
        if ((int)ob->query("shen") <5000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "武当派" NOR + GRN +"道长" NOR);
        else
	        this_player()->set("title",RED "武当派" NOR + GRN +"女道长" NOR);
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的内功心法不在此处。";
        add("book_count", -1);
        ob = new(__DIR__"force_book");
        ob->move(this_player());
        return "好吧，这本「太极十三式」你拿回去好好钻研。";
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <0 && ((fam = ob->query("family")) && fam["master_id"] == "song yuanqiao"))
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 50");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
