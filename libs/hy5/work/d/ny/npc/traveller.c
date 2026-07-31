
//traveller.c
inherit NPC;

void create()
{
        set_name("旅客", ({ "traveller"}));
        if(random(10)<7)
            set("gender", "男性" );
        else
            set("gender", "女性" );
        set("age", 15+random(50));
        set("long",
                "这是一位来雪亭镇的外地旅客.\n");
        set("chat_chance", 0);
        set("chat_msg", ({
(:command("get all"):),
(:random_move:)
 }));
        set("combat_exp", 600+random(400));
        set("attitude", "friendly");
        set_skill("dodge", 50);
	set_skill("throwing",30);
        set_skill("unarmed", 40);
        setup();
        carry_object(__DIR__"obj/throwing_knife")->wield();
	carry_object("/clone/misc/cloth")->wear();
        add_money("coin",30);
        set("score",5-random(10));
}
