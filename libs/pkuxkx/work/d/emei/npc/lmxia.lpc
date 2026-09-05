//
//create bye cuer
inherit NPC;
#include "/d/emei/npc/jing.h"
void create()
{
        set_name("李明霞", ({
                "li mingxia",
                "li",
                "mingxia",
        }));
        set("long",
                "她是一位还算年轻的女侠。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");    
        set("age", 30);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set("score", 100);
        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        set_skill("throwing",100);
        set_skill("pili-dan",100);
        map_skill("throwing","pili-dan");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "tiangang-zhi");
        prepare_skill("finger", "tiangang-zhi");
        
        create_family("峨嵋派", 4, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
