// 杀人鬼

inherit NPC;

void create()
{
	set_name(HIB"幽冥鬼将"NOR, ({ "killplayer" }));
	set("age", 999999);
	set("gender", "无性");
	set("long", "。\n");
	set("attitude", "peaceful");

	set("con", 100);
	set("int", 100);
	set("str", 100);
	set("dex", 100);

	set("qi", 100000);
	set("max_qi", 100000);
	set("jing", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	
	
	set("jiali", 350);
    set("score", 350);
	
	
	set("combat_exp", 100000000);
	set("shen_type", -1);

	set_skill("unarmed", 1500);
	set_skill("dodge", 1500);
	set_skill("parry", 1500);
	set_skill("force", 1500);
	set_skill("xuehai-mogong", 1500);
	set_skill("bianfu-bu", 1500);
	set_skill("cuixin-zhang", 1500);
	set_skill("strike", 1500);
	set_skill("cuff", 1500);
	set_skill("claw", 1500);

	map_skill("force", "xuehai-mogong");
    map_skill("dodge", "bianfu-bu");
    map_skill("strike","cuixin-zhang");
    map_skill("parry","cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");

	set_temp("apply/attack", 10000);
	set_temp("apply/defense", 500);
	set_temp("apply/damage", 10000);
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
		exp = this_object()->query_skill("force",1)*query_skill("force",1)*1/100;
		killer->add("combat_exp",exp);
		killer->add("jifeng",5000);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点修为。"ZJBR+ZJBR"5000点券""\n");
	}
	
	::die();
}