//
//create bye cuer
inherit NPC;
#include "/d/emei/npc/wen.h"
void create()
{
        set_name("文闲师太", ({
                "wenxian shitai",
                "wenxian",
                "shitai",
        }));
        set("long",
                "她是一位年轻师太。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 200);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 40);
        set("combat_exp", 10000);
        set("score", 100);
        set_skill("force", 60);
        set_skill("jinding-xinfa", 60);
        set_skill("dodge", 70);
        set_skill("zhutian", 70);
        set_skill("jinding-mianzhang", 70);
        set_skill("strike", 70);
        set_skill("parry", 60);
        set_skill("mahayana", 70);
        set_skill("literate", 60);
        map_skill("force", "jinding-xinfa");
        map_skill("dodge", "zhutian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("parry", "jinding-mianzhang");
        prepare_skill("strike", "jinding-mianzhang");
        
        create_family("峨嵋派", 5, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
