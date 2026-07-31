// duke.c

inherit NPC;

void create()
{
        set_name("大理赌客", ({"dali duke", "duke" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "这是个手气不好的大理赌客。\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 1000);
	set("shen_type", 0);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
		"赌客掏了掏口袋，摸出几个铜板来。\n",
        }) );
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);
}

