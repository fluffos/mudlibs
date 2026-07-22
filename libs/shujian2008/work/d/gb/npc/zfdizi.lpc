// /d/gb/npc/zfdizi.c 执法弟子

inherit NPC;

void create()
{
        set_name("执法弟子", ({ "zhifa dizi", "dizi", "di zi" }));
        set("long","这是一个听命执法长老的丐帮弟子, 负责用刑。\n");

        set("gender", "男性");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 24);
        set("int", 18);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 20);
        set("combat_exp", 5000);

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

        set("chat_chance", 5);
        set("chat_msg", ({
		"执法弟子叫道：“这般没用，亏你在丐帮中耽了这么久。”\n",
        }) );
	create_family("丐帮", 20, "弟子");
        setup();

        carry_object(CLASS_D("gaibang/obj/gb_budai2"))->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}