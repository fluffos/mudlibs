//menwei.c
inherit NPC;
inherit F_GUARDER;

void greeting(object);
void init();
void create()
{
	set_name("门卫", ({ "men wei", "wei"}) );
	set("nickname", "铁狮子");
	set("gender", "男性" );
	set("age", 22);
	set("long", "这是个年富力强的卫兵，样子十分威严。虽然他们武艺不高，但是\n"
		    "经过欧阳锋的训练，决非常人可敌。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1200);
	set("max_jing", 600);
	set("neili", 1700);
	set("max_neili", 200);
	set("combat_exp", 50000 + random(50000));
	set("score", 10000);

	set_skill("force", 100);
	set_skill("dodge", 80);
	set_skill("unarmed", 80+random(10));
	set_skill("parry", 90);
	set_temp("apply/attack", 45);
	set_temp("apply/defense", 45);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);

	set("coagents", ({
	    ([ "startroom" : "/d/baituo/dating",
	       "id"	: "ouyang feng" ]),
	}));

	create_family("欧阳世家", 0, "侍卫");

	setup();
	add_money("silver",20);
	carry_object("/d/baituo/obj/dadao")->wield();
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

	if(check_family(ob, "欧阳世家"))
	{
		say("门卫笑吟吟地说道：这位" + RANK_D->query_respect(ob) +
		    "您辛苦了，快请进吧　。\n");
		return;
	}

	if((int)ob->query("shen") > 200)
	{
		say("门卫两眼一瞪，说道：这位" + RANK_D->query_respect(ob) +
		    "你是来找麻烦的吧。\n我们庄主神功盖世，劝你不要轻举妄动！\n");
		return;
	}
}
