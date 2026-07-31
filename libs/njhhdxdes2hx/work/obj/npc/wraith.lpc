// wraith.c

inherit NPC;

int is_ghost() { return 1; }

void create()
{
	set_name("厉鬼", ({ "wraith" }) );
	set("long",
		"一个披头散发，浑身是血的厉鬼，正在这里飘来飘去。\n" );
	set("pursuer", 1);
	set("max_gin", 400);
	set("max_kee", 400);
	set("max_sen", 400);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("move", 200);
	set("shen_type",-1);
	setup();

	if( clonep() ) call_out("disappear", 1440);
}

void disappear()
{
	destruct(this_object());
}
