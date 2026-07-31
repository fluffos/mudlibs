//inherit NPC;
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
        set_name("曲灵风", ({"qu lingfeng", "qu", "lingfeng"}));
        set("gender", "男性");
        set("age", 30);
        set("long", 
        "这是桃花岛主的早期弟子之一。由于以前桃花岛曾有两个弟子。\n"
        "判逃，黄药师一怒之下累及无辜，将众弟子的脚筋全部挑断！\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 30);
        set("con", 29);
        set("dex", 20);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 150000);
        
        set_skill("force", 60);
        set_skill("bibo-shengong", 60);
        set_skill("unarmed", 90);
        set_skill("luoying-zhang", 90);
        set_skill("dodge", 50);
        set_skill("literate",80);
        set_skill("anying-fuxiang", 80);
        set_skill("parry", 90);
        set_skill("sword", 70);
        set_skill("luoying-shenjian",70);
        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("sword"  , "luoying-shenjian") ;
        map_skill("parry"  , "luoying-zhang") ;
        create_family("桃花岛", 2, "弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if (ob->query_int() >= 25) 
        {
                command("pat " + ob -> query("id") ) ;
                command("say 桃花影落飞神剑，碧海潮生按玉箫！\n");
                command("recruit "+ob->query("id"));
                if((string)ob->query("class") != "scholar")
                        ob->set("class", "scholar");
                return;
        }
        command("say 嗯......我桃花岛的弟子必须天资聪明，我看你的资质似乎不适合"
            "练我桃花岛的武功？\n") ;
}
