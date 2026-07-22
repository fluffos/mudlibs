// d/tangmen/npc/tangjing.c


inherit NPC;

void greeting(object);
void init();
void serve_tea(object);
void delete_served();

void create()
{
	set_name("唐晶", ({"tang jing", "jing"}) );
	set("nickname", "小机灵鬼");
	set("gender", "女性" );
	set("age", 12+random(6));
	set("long",
	   "她是唐门弟子中年龄最小的一个，看起来只有十二三岁。\n"
	  "她聪明伶俐，很讨人喜爱，唐老太太派她专门在这儿招呼来访的客人。\n");
	set("attitude", "friendly");
    set("shen_type", 1);

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

		set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("唐门", 9, "弟子");

        setup();
        
		carry_object("/d/tangmen/obj/shujin")->wear();
		
}

void init()
{	
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	say("唐晶笑吟吟地说道：这位" + RANK_D->query_respect(ob)
	     + "请先入座，" + "我这就给您上茶。\n");
}


void serve_tea(object who)
{
	object obt, obc, obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

	if ( (int)who->query_temp("tea_cup") <= 0 )
	{
	 	obn = new("d/tangmen/obj/dawancha");
		obn->move(room);
		message_vision("唐晶搬出个大茶壶来，将桌上的大碗茶倒满．\n",
			who);
	} else 
	{
		who->add_temp("tea_cup", -1);
	 	obn = new("d/tangmen/obj/tea");
		obn->move(room);
		message_vision("唐晶拿出个精致的紫砂壶，沏了杯香茶，放在桌上．\n",
			who);
	}

 	obn = new("d/tangmen/obj/shuimitao");
	obn->move(room);
	message_vision("唐晶拿出一碟水蜜桃，放在桌上．\n", who);
	
	return;
}
