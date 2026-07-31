// 杀人鬼

inherit NPC;

void create()
{
	set_name(HIY"妖魔"NOR, ({ "yaomo sv1" }));
	set("age", 999999);
	set("gender", "无性");
	set("long", "。\n");
	set("attitude", "peaceful");

	set("con", 350);
	set("int", 350);
	set("str", 350);
	set("dex", 350);

	set("qi", 50000000);
	set("max_qi", 50000000);
	set("jing", 50000000);
	set("max_jing", 50000000);
	set("neili", 50000000);
	set("max_neili", 50000000);
	
	
	set("jiali", 3500);
    set("score", 1500);
	
	
	set("combat_exp", 100000000);
	set("shen_type", -1);

	set_skill("unarmed", 15000);
	set_skill("dodge", 15000);
	set_skill("parry", 15000);
	set_skill("force", 15000);
	set_skill("xuehai-mogong", 15000);
	set_skill("bianfu-bu", 15000);
	set_skill("cuixin-zhang", 15000);
	set_skill("strike", 15000);
	set_skill("cuff", 15000);
	set_skill("claw", 15000);

	map_skill("force", "xuehai-mogong");
    map_skill("dodge", "bianfu-bu");
    map_skill("strike","cuixin-zhang");
    map_skill("parry","cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");

	set_temp("apply/attack", 100000);
	set_temp("apply/defense", 50000);
	set_temp("apply/damage", 100000);
	set_temp("apply/armor", 50000);

	set("chat_chance_combat", 120);
    set("chat_msg_combat", ({
                (: command("strike.cuixin") :),
                (: command("force.jixue") :),
                (: command("force.powerup") :),
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
		exp = this_object()->query_skill("force",1)*query_skill("force",1)*1/25;
		killer->add("combat_exp",exp);
		killer->add("yuanbao",100);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点修为，"ZJBR+ZJBR"100灵石""\n");
	}
	
	::die();
}