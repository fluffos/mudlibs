// dizi1.c
//by dicky

inherit NPC;

void create()
{
        set_name("中年乞丐", ({ "qigai", "beggar" }) );
        set("long","这是一个中年乞丐，脸上已有不少皱纹。\n");
	
        set("gender", "男性");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 20);
        set("combat_exp", 10000);

        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        set_skill("parry", 60);


        setup();

}

