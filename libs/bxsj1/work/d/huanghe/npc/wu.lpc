// wu.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("吴青烈", ({ "wu qinglie", "wu", "qinglie" }));
        set("gender", "男性");
        set("title", HIY"黄河四鬼老二"NOR);
        set("nickname", HIC"追命枪"NOR);
        set("age", 32);
        set("str", 25);
        set("dex", 16);
        set("per", 21);
        set("long", "吴青烈是黄河四鬼的老二，是鬼门龙王沙通天的二弟子，擅
使长枪。\n");
        set("combat_exp", 300000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set_skill("force", 120);
        set_skill("xuantian-wuji", 120);
        set_skill("spear", 120);
        set_skill("bawang-qiang", 120);
        set_skill("dodge", 90);
        set_skill("kunlun-shenfa", 100);
        set_skill("strike", 90);
        set_skill("parry", 90);
        set_skill("kunlun-zhang", 80);
        set_skill("literate", 60);

        map_skill("spear", "bawang-qiang");
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "bawang-qiang");
        prepare_skill("strike", "kunlun-zhang");

        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);

        setup();
        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


