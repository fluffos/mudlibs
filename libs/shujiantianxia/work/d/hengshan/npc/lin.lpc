// lin.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("仪琳", ({ "yi lin", "lin" }) );
        set("gender", "女性");
        set("class", "bonze");
        set("age", 16);
        set("attitude", "peaceful");
        set("per", 30);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 30);
        set("max_qi", 1000);
        set("max_jing", 800);
        set("combat_exp", 280000);
        set("shen_type", 1);

        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("strike", 120);
        set_skill("sixiang-zhang" ,120);
        set_skill("linji-zhuang", 120);
        set_skill("hengshan-jian", 120);
        set_skill("qingmang-jian", 120);

        map_skill("sword", "hengshan-jian");
        map_skill("force", "linji-zhuang");
        map_skill("strike", "sixiang-zhang");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "qingmang-jian");
        prepare_skill("strike", "sixiang-zhang");

        create_family("恒山派", 14, "弟子");
        set("inquiry", ([
        "令狐冲" : "仪琳的脸「唰」的一下红了起来说道：你找令狐大哥有事吗？\n",
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();
}
