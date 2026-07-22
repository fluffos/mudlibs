inherit NPC;
void create()
{
        set_name("游客", ({ "you ke",  "ke" }) );
        if(random(10)<6) set("gender","男性");
        else set("gender","女性");
        set("age", 20+random(40));
        set("str", 16);
        set("per", 13+random(20));
        set("attitude", "peaceful");
        set("long", "这是位来此游玩的人家。\n");
        set("combat_exp", 1000);
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 60);
        set("chat_chance",5);
        set("chat_msg",({
        	(: random_move :),
                "游客到：“这里一片山青水秀，倒是个好地方。”\n",
                (: random_move :),
                "游客看着你说到：“你也是来游山玩水的？来，来，我们结伴而行吧。”\n",
                (: random_move :),
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 10+random(20));
}

 
