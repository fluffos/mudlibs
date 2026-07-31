inherit NPC;

void create()
{
	set_name("¹Ù±ø", ({ "guan bing" }));
	set("long", "ÕâÊÇ³¯Í¢µÄ¹Ù±ø¡£\n");
	set("gander", "ÄÐÐÔ");
	set("combat_exp", 100000);

	setup();
}

void die()
{
	object mem = this_object()->query("mem");

	mem->npc_die();
	::die();
}