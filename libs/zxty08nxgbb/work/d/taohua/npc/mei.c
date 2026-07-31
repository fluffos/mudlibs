#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
        set_name("梅超风", ({"mei chaofeng", "mei"}));
        set("nickname", RED "铁尸" NOR ); 
        set("gender","女性") ;
        set("age", 34);
        set("long", 
        "这是桃花岛主的早期弟子之一。也是唯一的女弟子。\n"
        "她皮肤稍微黑了一点，但容貌甚是娇美。\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 29);
        set("con", 20);
        set("dex", 25);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("combat_exp", 300000);
        set("shen", -50000);
        
        set_skill("force", 30);
        set_skill("bibo-shengong", 30);
        set_skill("unarmed", 90);
        set_skill("luoying-zhang",50) ;
        set_skill("jiuyin-baiguzhao", 90);
        set_skill("dodge", 70);
        set_skill("literate",50);
        set_skill("anying-fuxiang", 70);
        set_skill("parry", 60);
        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed",   "jiuyin-baiguzhao");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "jiuyin-baiguzhao") ;
        map_skill("unarmed","luoying-zhang") ;
        create_family("桃花岛", 2, "弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if (ob->query_int() >= 25) 
        {
                command("hmm") ;
                command("say 我是桃花岛的不肖弟子，本不应收徒。但你既然诚心拜我，我就成全你吧。\n");
                command("say 桃花影落飞神剑，碧海潮生按玉箫！\n");
                command("recruit "+ob->query("id"));
                if((string)ob->query("class") != "scholar")
                        ob->set("class", "scholar");
                return;
        }
        command("say 嗯......我桃花岛的弟子必须天资聪明，我看你的资质似乎不适合"
            "练我桃花岛的武功？\n") ;
}
