// bangshou.c

inherit NPC;

int is_rain_quest() { return 1;}

void create()
{
	set_name("黑脸大汉", ({"black man"}));
        set("long", "这是一位眼露凶光的黑脸大汉。\n");
        set("gender","男性");

        set("age",50);
        set("con",30);
        set("str",30);
	set("kar",30);
	set("cor",35);

	set("max_atman",2000);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",2000);
	set("max_kee",1200);
	set("max_gin",1200);
	set("max_sen",1200);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",40);

	set("attitude","peaceful");
	set("no_exp_gain",1);

	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("unarmed",150);
	set_skill("force",150);

	set_skill("sword",120);


        set("combat_exp",1500000);

        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

void die()
{
	if(environment())
		environment()->do_check();
	::die();
}

private void leave()
{
	if(living(this_object()) && !is_fighting())
		destruct(this_object());
}

int heal_up()
{
	if(living(this_object()) && !is_fighting())
        {
                call_out("leave",2);
                return 1;
        }

        return ::heal_up() + 1;
}
