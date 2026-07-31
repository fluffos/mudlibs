// taijian.c
inherit NPC;

void create()
{
	set_name("Ì«¼à", ({ "tai jian", "tai" ,"jian"}));
	set("gender", "ÎŞĞÔ");
	set("age", 15+random(60));

	set("combat_exp", 5000);
	set("shen_type", 0);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	add_money("silver", random(10));
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}

