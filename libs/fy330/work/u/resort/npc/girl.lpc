// girl.c

inherit NPC;

void create()
{
        set_name("小翠", ({ "xiao cui", "cui", "xiao" }) );
        set("gender", "女性" );
        set("age", 15);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "peaceful");

        set("max_force", 200);
        set("force", 200);
        set("force_factor", 2);

        set("long",     "小翠是铁雪山庄的丫环。\n");


        set("combat_exp", 10000);

        set_skill("unarmed", 20);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 40);
        set_skill("force", 30);
        set_skill("literate", 70);

        set_skill("qidaoforce", 40);
        set_skill("deisword", 20);
        set_skill("meihua-shou", 40);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("sword", "deisword");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object(__DIR__"obj/thin_sword")->wield();
        carry_object(__DIR__"obj/pink_cloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}

 
