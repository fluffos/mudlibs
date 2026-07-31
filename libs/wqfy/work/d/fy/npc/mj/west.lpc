
inherit NPC;

void create()
{
	set_name("张飞", ({ "west com"}));
	set("age", 38);
	set("gender", "男性");
	set("long", "他就是张飞，虽然被人切了头，但打麻将还凑和。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}

        
	setup();
	
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) )
		
		command( "addin" );
	
}

