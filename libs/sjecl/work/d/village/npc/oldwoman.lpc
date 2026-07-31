// /d/village/npc/oldwoman.c

inherit NPC;

void create()
{
        set_name("老大娘", ({ "lao daniang", "woman" }) );
        set("gender", "女性" );
        set("age", 60+random(20));
        set("long", "一个满脸风霜之色的老婆婆。\n");
	set("shen_type", 1);
	set("combat_exp", 1500);
        set("str", 13);
        set("dex", 12);
        set("con", 14);
	set("int", 13);
	set("attitude", "friendly");
	setup();
	set("chat_chance", 3);
	set("chat_msg", ({
		"老大娘伤心的说道：那个天杀的，偷了我的老母鸡。\n",
		"老大娘叹了口气，说道：这是个什麽世道啊。\n",
		"老大娘呆呆的望着鸡笼，发起愣来了。\n",
	}));
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin", random(100));
}
