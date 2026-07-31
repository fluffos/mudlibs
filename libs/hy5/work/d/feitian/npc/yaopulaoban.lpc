// npc: 药铺老板

inherit NPC;

void create()
{
        set_name("药铺老板", ({ "lao ban", "lao", "boss" }) );
        set("gender", "男性" );
	set("title", "大理名医");
        set("age", 50);
        set("long",
	    "他正盯着一本药谱在看。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "行医" : "老夫一生，医人无数，也算行了件大善事。",
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();

}

