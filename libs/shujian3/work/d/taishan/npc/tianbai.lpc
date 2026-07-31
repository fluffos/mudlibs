// tianbai.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("天柏道人", ({ "tianbai daoren", "daoren", "tianbai" }) );
        set("gender", "男性");
        set("class", "taoist");
        set("unique", 1);
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2200);
        set("max_neili", 2200);
        set("jiali", 20);
        set("max_qi",1800);
        set("max_jing",1100);
        set("combat_exp", 850000);
        set("shen_type", 1);

        set_skill("sword", 130);
        set_skill("force", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("cuff", 130);
        set_skill("taiji-shengong", 130);
        set_skill("taizu-quan", 130);
        set_skill("taishan-jianfa", 130);
        set_skill("qingmang-jian", 130);

        map_skill("sword", "taishan-jianfa");
        map_skill("parry", "taishan-jianfa");
        map_skill("dodge", "qingmang-jian");
        map_skill("force","taiji-shengong");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff", "taizu-quan");


        create_family("泰山派", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/daopao")->wear();
}

