// Modified by iszt@pkuxkx, 2007-04-03, fixed a small bug

inherit NPC;

void create()
{
	set_name("蒙古亲兵", ({ "qin bing","bing" }) );
	set("gender", "男性" );
	set("age", 48);
	set("long", 
	    "他们个个盔甲鲜明，训练有素。\n");
	set("str", 20);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 50);
	set_skill("blade", 55);    
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set("combat_exp", 20000);

	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/junfu")->wear();
	carry_object(__DIR__"obj/gangdao")->wield();
}

void init()
{
	int i;
	object me = this_player();
	mapping armor = me->query_temp("armor");
	string *pname;

	if(armor)
	{
		pname=keys(armor);
		for(i=0;i<sizeof(armor);i++)
			if ((armor[pname[i]])->query("id")=="menggu cloth"&&me->query_temp("citan"))
			{
				command("hi "+me->query("id"));
				return ;
			}
	}
	command("say 嗯？你是哪里来的？大胆，竟敢私闯蒙古大帐？");
	//kill_ob(me);
	return;
}