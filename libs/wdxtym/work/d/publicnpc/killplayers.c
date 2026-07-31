// 杀人鬼

inherit NPC;

void create()
{
	set_name(HIG"幽冥鬼王"NOR, ({ "killplayers" }));
	set("age", 999999);
	set("gender", "无性");
	set("long", "。\n");
	set("attitude", "peaceful");

	set("con", 150);
	set("int", 150);
	set("str", 150);
	set("dex", 150);

	set("qi", 2000000);
	set("max_qi", 2000000);
	set("jing", 2000000);
	set("max_jing", 2000000);
	set("neili", 2000000);
	set("max_neili", 2000000);
	
	
	set("jiali", 2000);
    set("score", 500);
	
	
	set("combat_exp", 200000000);
	set("shen_type", -1);

	set_skill("unarmed", 2000);
	set_skill("dodge", 2000);
	set_skill("parry", 2000);
	set_skill("force", 2000);
	set_skill("xuehai-mogong", 2000);
	set_skill("bianfu-bu", 2000);
	set_skill("cuixin-zhang", 2000);
	set_skill("strike", 2000);
	set_skill("cuff", 2000);
	set_skill("claw", 2000);

	map_skill("force", "xuehai-mogong");
    map_skill("dodge", "bianfu-bu");
    map_skill("strike","cuixin-zhang");
    map_skill("parry","cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");

	set_temp("apply/attack", 15000);
	set_temp("apply/defense", 500);
	set_temp("apply/damage", 15000);
	set_temp("apply/armor", 500);

	set("chat_chance_combat", 120);
    set("chat_msg_combat", ({
                (: command("perform strike.cuixin") :),
                (: command("exert force.jixue") :),
                (: command("exert force.powerup") :),
        }) );

	
	setup();
	
	
	if (clonep()) 
	{
		set("chat_chance", 50);
		set("chat_msg", ({
			(:NPC_D->random_move(this_object()):),
        }) );
		
		keep_heart_beat();
	}
	
}

void init()
{
        object me,ob;
        ::init();
        if ( interactive(me = this_player()) && living(this_object()) )
        {
	if (!(ob = present("killpalyerling", this_player())))          
               {
	       remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
		}
        }
}

void die()
{
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		exp = this_object()->query_skill("force",1)*query_skill("force",1)*1/75;
		killer->add("combat_exp",exp);
		killer->add("yuanbao",1500);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点修为，"ZJBR+ZJBR"1500灵石""\n");
	}
	
	::die();
}