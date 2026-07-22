// /d/gb/npc/qnqigai.c 青年乞丐
// Lklv 2001.9.27

inherit NPC;
#include "/d/gb/begger.h";

void create()
{
        set_name("青年乞丐", ({ "qingnian qigai", "qigai" }));
        set("long","这是一个青年乞丐，目光炯炯有神。\n");

        set("gender", "男性");
        set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 25);
        set("int", 16);
        set("con", 25);
        set("dex", 24);

        set("max_qi", 600);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 50000);

        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("strike", 60);
        set_skill("parry", 60);
        set_skill("huntian-qigong", 60);
        set_skill("xiaoyaoyou", 60);
        set_skill("lianhua-zhang", 60);
        set_skill("begging", 60);

	map_skill("force", "huntian-qigong");
        map_skill("strike","lianhua-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "lianhua-zhang");
	prepare_skill("strike", "lianhua-zhang");

        setup();
        carry_object(CLASS_D("gaibang/obj/gb_budai1"))->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
