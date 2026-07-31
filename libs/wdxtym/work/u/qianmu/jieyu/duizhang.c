inherit NPC;

void npc_pfm();

void create()
{
	set_name("朝廷高手", ({ "chaoting gaoshou" }));
	set("long", "这是朝廷的高手。\n");
	set("gander", "男性");
	set("combat_exp", 100000);

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: npc_pfm :),
	}));

	setup();
}

void die()
{
	object mem = this_object()->query("mem");

	mem->npc_die();
	::die();
}

void npc_pfm()
{
	object me = this_object();

	__DIR__"pfm"->perform(me);
}