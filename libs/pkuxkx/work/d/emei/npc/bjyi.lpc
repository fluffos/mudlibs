//
//create bye cuer
inherit NPC;
#include "/d/emei/npc/jing.h"
void create()
{
        set_name("贝锦仪", ({
                "bei jinyi",
                "bei",
                "jinyi",
        }));
        set("long",
                "她是一位稳重的中年女侠。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("age", 40);
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
        set_skill("yanxing-dao", 100);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "yanxing-dao");
        prepare_skill("blade", "yanxing-dao");
        
        create_family("峨嵋派", 4, "弟子");
        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/cloth")->wear(); 
}
