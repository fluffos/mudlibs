// dashou.c 打手
// Lklv 2001.9.27 update

inherit NPC;

void create()
{
        set_name("打手", ({"da shou", "dashou", "shou" }) );
        set("gender", "男性" );
        set("age", 20+random(10));
        set("long", "他是个跟在主人后面专门做恶的打手。\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set("combat_exp", 8000);
	set("shen", -300);
	set("shen_type", -1);
        set("str", 30);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");

	set("chat_chance", 5);
	set("chat_msg", ({
		"打手向钱庄老板鞠了个躬：要不要小的教训这家伙一顿？\n",
 		"打手搬着双手的手指，发出咔~咔~的声音。\n",
        }) );
	setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

