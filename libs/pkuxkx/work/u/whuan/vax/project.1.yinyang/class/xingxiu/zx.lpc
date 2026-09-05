inherit NPC;
inherit F_MASTER;
string ask_me();
void consider();
void create()
{
        set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
        set("nickname", "星宿派大师兄");
        set("long",
                "他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
                "他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);
        set("max_qi", 700);
        set("max_jing", 700);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 300000);
        set("score", 40000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
        set_skill("force", 70);
        set_skill("huagong-dafa", 50);
        set_skill("handu-xinfa", 100);
        set_skill("dodge", 70);
        set_skill("zhaixinggong", 100);
        set_skill("strike", 80);
        set_skill("xingxiu-duzhang", 80);
        set_skill("parry", 70);
        set_skill("staff", 70);
//      set_skill("tianshan-zhang", 60);
//      set_skill("literate", 50);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
//      map_skill("parry", "tianshan-zhang");
//      map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
       set("inquiry",
                ([
                        "秘籍" : (: ask_me :),
                        "天山器法" : (: ask_me :),
                     ]));
        create_family("星宿派", 2, "弟子");
        setup();
//      carry_object("/clone/weapon/gangzhang")->wield();
}
void attempt_apprentice(object ob)
{
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        if (random(2))
                command("exert qisuck " + target->query("id"));
        else
      command("exert jingsuck " + target->query("id"));
}
string ask_me()
{
        mapping fam;
        object ob;
        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (this_player()->query("combat_exp")<3000)
             return RANK_D->query_respect(this_player()) +
            "初来乍到，还不能给你我派秘籍。";
        if (query("book_count") < 1)
                return "你来晚了，我派的秘籍不在此处。";
        add("book_count", -1);
        ob = new("/d/xingxiu/npc/obj/throwing_book");
        ob->move(this_player());
        return "好吧，我派的「天山器法」就给你拿回去好好钻研。";
}
          
