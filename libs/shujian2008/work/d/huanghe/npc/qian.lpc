// qian.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("钱青健", ({ "qian qingjian", "qian", "qingjian" }));
        set("gender", "男性");
        set("title", HIY"黄河四鬼老四"NOR);
        set("nickname", HIC"丧门斧"NOR);
        set("age", 32);
        set("str", 25);
        set("dex", 16);
        set("per", 16);
        set("long", "钱青健是黄河四鬼的老四，是鬼门龙王沙通天的四弟子，擅
于斧法。\n");
        set("combat_exp", 290000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set_skill("force", 90);
        set_skill("xuantian-wuji", 100);
        set_skill("axe", 100);
        set_skill("pangen-cuojie", 120);
        set_skill("dodge", 90);

        set_skill("kunlun-shenfa", 100);
        set_skill("strike", 90);
        set_skill("parry", 90);
        set_skill("kunlun-zhang", 80);
        set_skill("literate", 60);
        map_skill("axe", "pangen-cuojie");
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        prepare_skill("strike", "kunlun-zhang");

        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 10);

        setup();
        carry_object(__DIR__"obj/axe")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

