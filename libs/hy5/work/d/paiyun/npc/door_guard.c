// door_guard.c

inherit NPC;

private int zhao;

int is_paiyun() { return 1;}
void create()
{
	set_name("小山匪", ({ "shan fei" }) );

	set("gender", "男性");
	set("age", 33);
	set("long", "这家伙满脸横肉小山匪，总是翻着眼睛看人。\n");
	set("combat_exp", 150000);
	set("attitude", "peaceful");

	set("max_neili",600);
	set("force",600);
	set("force_factor",30);
	set("str",30);
	set("cor",60);
	set("kar",35);
	set("mak_qi",1000);
	set("mak_jing",1000);
	set("mak_sen",1000);

	set_skill("unarmed", 70);
	set_skill("club", 70);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();
	carry_object(__DIR__"obj/spear")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_fight(object me)
{
	command("say 不想活啦！\n");
	return 0;
}

int accept_kill(object me)
{
	if(base_name(environment()) != query("startroom"))
		return 1;

	if(!is_fighting())
		call_out("do_yell",1);
	return 1;
}

void do_yell()
{
	say("小山匪喊到：好家伙！快来人呀！有人闯寨啦！\n");
	call_out("do_zhao",1);
}

void do_zhao()
{
	object ob,*ens;

	if(!is_fighting())
	{
		zhao = 0;
		return;
	}

	if(zhao >= 6)
	{
		zhao = 0;
		return;
	}

	ob = new(__DIR__"d_guard");
	if(!ob)
		return;

	ob->move(environment());
	tell_room(environment(),sprintf("%s跑了过来。\n",ob->name()));
	ens = query_enemy();
	for(int i=0;i<sizeof(ens);i++)
		if(ens[i])
		{
			ob->kill_ob(ens[i]);
			ens[i]->fight_ob(ob);
		}
	zhao++;
	call_out("do_zhao",3);
}
