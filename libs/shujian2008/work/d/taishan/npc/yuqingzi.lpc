// yuqingzi.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("玉磬子", ({ "yuqing zi", "zi", "yuqing" }) );
        set("gender", "男性");
        set("class", "taoist");
        set("age", 45);
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("gender", "男性");
        set("class", "taoist");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 20);
        set("max_qi",2200);
        set("max_jing",1300);
        set("combat_exp", 100000);
        set("shen_type", 1);

        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("cuff", 150);
        set_skill("taiji-shengong", 150);
        set_skill("taizu-quan", 150);
        set_skill("taishan-jianfa", 150);
        set_skill("qingmang-jian", 150);

        map_skill("sword", "taishan-jianfa");
        map_skill("parry", "taishan-jianfa");
        map_skill("dodge", "qingmang-jian");
        map_skill("force","taiji-shengong");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff", "taizu-quan");


        create_family("泰山派", 12, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/daopao")->wear();
}
