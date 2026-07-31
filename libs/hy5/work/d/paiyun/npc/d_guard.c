// d_guard.c

inherit NPC;

int is_paiyun() { return 1;}

void create()
{
	set_name("山匪", ({ "shan fei" }) );
	set("long", "这是一位满脸凶残之样的山匪。\n");
	set("attitude", "friendly");

	set("max_qi", 1000);
	set("max_jing", 900);
	set("max_sen", 1000);
	set("max_neili",2500);
	set("force",2500);
	set("force_factor",20);
	set("str", 30);
	set("cor", 30);
	set("kar", 35);
	set("combat_exp", 250000);

	set_skill("club", 90);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("unarmed", 100);

	setup();

	carry_object(__DIR__"obj/armor")->wear();
	carry_object(__DIR__"obj/spear")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	if(living(this_object()))
	{
		if(environment())
			tell_room(environment(),sprintf("%s走了。\n",name()));
		destruct(this_object());
	}
}
