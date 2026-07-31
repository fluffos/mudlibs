// chibaicheng.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("迟百城", ({ "chi baicheng", "baicheng", "chi" }) );
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 25);
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 10);
        set("max_qi",1200);
        set("max_jing",800);
        set("combat_exp", 600000);
        set("shen_type", 1);

        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("taiji-shengong",100);
        set_skill("taishan-jianfa", 100);
        set_skill("qingmang-jian", 100);

        map_skill("sword", "taishan-jianfa");
        map_skill("force", "taiji-shengong");
        map_skill("cuff", "taizu-quan");
        map_skill("parry", "taishan-jianfa");
        map_skill("dodge", "qingmang-jian");

        create_family("泰山派", 14, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
