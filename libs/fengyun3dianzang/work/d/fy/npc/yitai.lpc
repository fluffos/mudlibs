// yitai.c

inherit NPC;

void create()
{
        set_name("姨太太", ({ "yitai" }) );
        set("gender", "女性" );
        set("age", 22);
        set("long", "妖艳的姨太太\n");

        set("combat_exp", 100);
        set("attitude", "heroism");
        set_skill("unarmed", 10);
        set_skill("parry", 10);
	set_skill("dodge", 10);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
	setup();
	add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}
