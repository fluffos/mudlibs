// boshou.c 钹手

inherit NPC;

void create()
{
        set_name("星宿派钹手", ({ "bo shou", "boshou", "shou"}));
        set("long",
                "他是星宿派的吹鼓手。\n"
                "他手中拿着一对铜钹，一边敲一边扯着嗓子唱些肉麻的话。\n");
        set("gender", "男性");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen", -100);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 2000);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("unarmed", 25);
        set_skill("parry", 20);

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
		"钹手敲着铜钹，高声唱道，“星～宿～老～仙，威～震～寰～宇”。\n",
		"钹手敲着铜钹，高声唱道，“星～宿～老～仙，德～配～天～地”。\n",
		"钹手敲着铜钹，高声唱道，“星～宿～老～仙，古～今～无～比”。\n",
        }) );
        carry_object(BINGQI_D("tongbo"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}

