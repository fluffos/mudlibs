// shi.c

inherit NPC;
int ask_me();

void create()
{
	set_name("史镖头", ({ "shi biaotou", "shi" }));
	set("gender", "男性");
	set("age", 45);

	set("combat_exp", 7000);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);

	set("inquiry", ([
	     "林平之": (: ask_me :),
       ]) );
       
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_me()
{
	if((int)this_player()->query("jinyong/book8")!=1)
	{
		message_vision("$N对$n说道： 林平之就是我们少镖头了。\n",this_object(),this_player());
		return 1;
	}
	message_vision("$N对$n说道： 林平之就是我们少镖头了，这回他路见不平杀了青城派掌门余沧海的儿子。\n",this_object(),this_player());
	message_vision("余沧海派出青城派好手前来寻仇，总镖头为了保住林家血脉，已经派人将少镖头送出城外。 \n",this_object(),this_player());
	this_player()->set_temp("jinyong/book8/biaoju_ask",1);
	return 1;
}
