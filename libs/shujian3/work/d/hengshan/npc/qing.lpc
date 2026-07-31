// qing.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("仪清", ({ "yi qing", "qing" }) );
        set("gender", "女性");
        set("class", "bonze");
        set("age", 35);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 20);
        set("max_qi", 1000);
        set("max_jing", 800);
        set("combat_exp", 500000);
        set("shen_type", 1);

        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("strike", 100);
        set_skill("sixiang-zhang" ,100);
        set_skill("linji-zhuang", 100);
        set_skill("hengshan-jian", 100);
        set_skill("qingmang-jian", 100);

        map_skill("sword", "hengshan-jian");
        map_skill("force", "linji-zhuang");
        map_skill("strike", "sixiang-zhang");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "qingmang-jian");
        prepare_skill("strike", "sixiang-zhang");

        create_family("恒山派", 14, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();

}
