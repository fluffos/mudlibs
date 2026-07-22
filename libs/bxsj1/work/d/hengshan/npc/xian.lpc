// xian.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("定闲师太", ({ "dingxian shitai", "shitai", "dingxian" }) );
        set("gender", "女性");
        set("title", HIY"恒山派第十三代掌门"NOR);
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 31);
        set("str", 31);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 3400);
        set("max_neili", 3400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1700000);
        set("shen_type", 1);

        set_skill("sword", 190);
        set_skill("force", 190);
        set_skill("parry", 190);
        set_skill("dodge", 190);
        set_skill("strike", 190);
        set_skill("sixiang-zhang" ,190);
        set_skill("linji-zhuang", 190);
        set_skill("hengshan-jian", 190);
        set_skill("qingmang-jian", 190);

        map_skill("sword", "hengshan-jian");
        map_skill("force", "linji-zhuang");
        map_skill("strike", "sixiang-zhang");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "qingmang-jian");
        prepare_skill("strike", "sixiang-zhang");

        create_family("恒山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();

}

void attempt_apprentice(object ob)
{
    command("sign");
    command("say 贫尼近日不想收徒, 你还是去别派看看吧。”\n");
    return;
}

