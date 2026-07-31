
// snake.c

inherit NPC;

void create()
{
        set_name("毒蛇", ({ "snake" }) );
	set("race", "野兽");
	set("age", 4);
        set("long", "一条巨蛇横在路中，它已注意到了你这不速之客。\n");
	set("attitude", "aggressive");
	
	set("str", 26);
	set("cor", 30);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 400);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
                "蛇突然立起身子，盯着你嘴里吐着血红的舌头\n",
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}
