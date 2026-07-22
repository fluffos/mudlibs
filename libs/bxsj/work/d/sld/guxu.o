// guxu.c 谷虚
// Update by caiji@SJ 8/27/2000

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_for(string name);

void create()
{
        set_name("谷虚道长", ({ "guxu daozhang", "guxu" }));
        set("long", 
                "他就是俞莲舟的弟子谷虚道长。\n"
                "他今年四十岁，主管武当派的俗事。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 1500);
        set("max_jing", 800);
        set("eff_jingli",800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 70);
        set("combat_exp", 450000);
        set("score", 3000);

        set_skill("force", 100);
        set_skill("yinyun-ziqi", 100);
        set_skill("dodge", 100);
        set_skill("tiyunzong", 100);
        set_skill("xuanxu-daofa", 100);
        set_skill("blade", 100);
        set_skill("wudang-quan", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("sword", 100);
        set_skill("taoism", 100);
        set_skill("literate", 100);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "wudang-quan");
        map_skill("parry", "xuanxu-daofa");
        map_skill("blade", "xuanxu-daofa");

        prepare_skill("cuff", "wudang-quan");

        create_family("武当派", 3, "弟子");
        set("class", "taoist");
        
        set("huju_count", 30);

        set("inquiry", ([
             "道德经" : (: ask_me :),
             "huwan" : (: ask_for, "huwan" :),//add by caiji
             "护腕" : (: ask_for, "huwan" :),//add by caiji
             "护胸" : (: ask_for, "huxiong" :),//add by caiji
             "huxiong" : (: ask_for, "huxiong" :),//add by caiji
             "护腰" : (: ask_for, "huyao" :),//add by caiji
             "huyao" : (: ask_for, "huyao" :),//add by caiji
        ]));
                                
        set("book_count", 1);

        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/d/wudang/obj/daolv")->wear();
}

void reset()
{
	this_object()->set("book_count", 1);
	this_object()->set("huju_count", 30);
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	 || fam["family_name"] != "武当派")
		return RANK_D->query_respect(this_player())+"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的道德真经不在此处。";
	add("book_count", -1);
	ob = new("/d/wudang/obj/ddj2");
	ob->move(this_player());
	return "好吧，这本「道德经」你拿回去好好钻研。";
}

string ask_for(string name)
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) + 
                "又不是武当弟子，我不能随便给你武当派的东西！";

        if (  present(name, this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你现在身上不是有这样防具吗，怎麽又来要了？ 真是贪得无餍！";

        if (query("huju_count") < 1)
                return "抱歉，你来得不是时候，我已经发完了，你下次再来领吧。";

        ob = new("/d/wudang/obj/" + name);
        ob->move(this_player());

        add("huju_count", -1);

        message_vision("$N给$n一件" + ob->query("name") + "。\n",this_object() ,this_player());

        return "这可是件好东西，别弄丢了。";
}
