//
//create bye cuer
inherit NPC;
#include "/d/emei/npc/jing.h"
void create()
{
        set_name("苏梦清", ({
                "su mengqing",
                "su",
                "mengqing",
        }));
        set("long",
                "她是一位年轻的女侠。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");       
        set("age", 28);
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
        set_skill("jinding-xinfa", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("jinding-mianzhang", 100);
        set_skill("strike", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("parry", "jinding-mianzhang");
        prepare_skill("strike", "jinding-mianzhang");
        
        create_family("峨嵋派", 4, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        
}
