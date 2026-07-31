// haoshou.c 号手

inherit NPC;

void create()
{
        set_name("星宿派号手", ({ "hao shou", "haoshou", "shou" }));
        set("long",
                "他是星宿派的吹鼓手。\n"
                "他手中拿着一只铜号，鼓足力气沉醉地吹着。\n");
        set("gender", "男性");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen", -150);
        set("str", 26);
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
        set_skill("unarmed", 35);
        set_skill("parry", 30);

        setup();
        set("chat_chance", 2);

        set("chat_msg", ({
		"号手吹了吹铜号，高声唱道，“星～宿～老～仙，威～震～寰～宇”。\n",
		"号手吹了吹铜号，高声唱道，“星～宿～老～仙，德～配～天～地”。\n",
		"号手吹了吹铜号，高声唱道，“星～宿～老～仙，古～今～无～比”。\n",
        }) );
        carry_object(BINGQI_D("tonghao"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
