inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("建除道人", ({ "jianchu daoren", "daoren", "jianchu" }) );
        set("gender", "男性");
        set("class", "taoist");
        set("age", 45);
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 20);
        set("max_qi",2200);
        set("max_jing",1300);
        set("combat_exp", 750000);
        set("shen_type", 1);

        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("cuff", 120);
        set_skill("taiji-shengong", 120);
        set_skill("taizu-quan", 120);
        set_skill("taishan-jianfa", 120);
        set_skill("qingmang-jian", 120);

        map_skill("sword", "taishan-jianfa");
        map_skill("parry", "taishan-jianfa");
        map_skill("dodge", "qingmang-jian");
        map_skill("force","taiji-shengong");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff", "taizu-quan");


        create_family("泰山派", 14, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/daopao")->wear();
}

