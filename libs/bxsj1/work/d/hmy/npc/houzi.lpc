// monkey.c 

inherit NPC;

void create()
{
	set_name("猴子", ({ "hou zi","hou" }) );
        set("race", "野兽");
	set("age", 8);
	set("long",
		"这只猴子在在桃树间跳上跳下，还不时津津有味地啃几口着蜜桃。\n");
	set("combat_exp", 500);
	set("attitude", "peaceful");
	
	set("water", 200);
	set("food", 200);

	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);

        set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
}
