// scholar.c

inherit NPC;

void create()
{
        set_name("书生", ({ "scholar" }) );
        set("long", "一个看起来相当斯文的书生，正拿著一本书摇头晃脑地读著。\n");
        set("age", 23);
        set("attitude", "peaceful");
        set("combat_exp", 10);
        set("env/wimpy", 60);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );
	set("donkey",0);
        setup();
        carry_object(__DIR__"obj/book");
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        if( !query("donkey") )
	{
                call_out("do_ride", 1);
		set("donkey", 1);
	}
	else if (!query_temp("on_rided"))
		call_out("ride",1);
}

void ride()
{
	object donkey;

	if( (donkey = present("donkey",environment()))
	&& donkey->query("ride")
	&& living(donkey)
	&& !donkey->query_temp("have_been_rided"))
	command("ride donkey");
}

void do_ride()
{
        object ob;
	ob = new(__DIR__"donkey");
	ob->move( environment(this_object()) );
        command("ride donkey");
        return; 
}