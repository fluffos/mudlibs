inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
        set_name("冯默风", ({"feng mofeng", "feng", "mofeng"}));
        set("gender", "男性");
        set("age", 27);
        set("long", 
        "这是桃花岛主的早期弟子之一。由于以前桃花岛曾有两个弟子。\n"
        "判逃，黄药师一怒之下累及无辜，将众弟子的脚筋全部挑断！\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 29);
        set("con", 29);
        set("dex", 25);
        set("qi", 800);
        set("max_qi", 800);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 20);
        
        set("combat_exp", 100000);
        
        set_skill("force", 70);
        set_skill("bibo-shengong", 70);
        set_skill("unarmed", 80);
        set_skill("luoying-zhang", 80);
        set_skill("dodge", 60);
        set_skill("literate",70);
        set_skill("anying-fuxiang", 70);
        set_skill("parry", 80);
        set_skill("qimen-wuxing",50) ;
        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-zhang") ;
        
        create_family("桃花岛", 2, "弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if (ob->query_int() >= 25) 
        {
                command("say 好吧，我就收了你。以后不要给桃花岛丢脸呀！\n" ) ;
                command("say 桃花影落飞神剑，碧海潮生按玉箫！\n");
                command("recruit "+ob->query("id"));
                if((string)ob->query("class") != "scholar")
                        ob->set("class", "scholar");
                return;
        }
        command("say 嗯......我桃花岛的弟子必须天资聪明，我看你的资质似乎不适合"
            "练我桃花岛的武功？\n") ;
}
