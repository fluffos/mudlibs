// dizi3.c

inherit NPC;
#include "/d/gb/begger.h";

void create()
{
        set_name("壮年乞丐", ({ "qi gai", "di zi", "qigai" }));
        set("long","这是一个中年乞丐，脸上已有不少皱纹。\n");

        set("gender", "男性");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);

	create_family("丐帮", 20, "弟子");
        setup();
        carry_object(CLASS_D("gaibang/obj/gb_budai2"))->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

