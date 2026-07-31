// dizi4.c

inherit NPC;
#include "/kungfu/class/gaibang/begger.h";

void create()
{
        set_name("老乞丐", ({ "lao qigai", "qigai", "lao" }) );
        set("long","这是一个老年乞丐。他满面皱纹，两鬓苍苍，显然经历过不少风霜。\n");

        set("gender", "男性");
        set("age", 60);
        set("attitude", "peaceful");

        set("shen_type", 0);
        set("str", 20);
        set("int", 16);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);
        set("combat_exp", 4000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("begging", 40);

        setup();

	carry_object(ARMOR_D("caoxie"))->wear();
	carry_object(ARMOR_D("bainayi"))->wear();
	carry_object(CLASS_D("gaibang/obj/gb_budai1"))->wear();
}

