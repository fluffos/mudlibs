// dog.c

inherit NPC;

void create()
{
	set_name("大黑", ({ "dog" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", "一只大狼狗，是主人养来看门的。\n");
	
	set("str", 32);
	set("dex", 36);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		"大黑用鼻子闻了闻你的脚。\n",
		"大黑在你的脚边挨挨擦擦的，想讨东西吃。\n",
		"大黑对著你摇了摇尾巴。\n",
		"大黑对你「汪汪」叫了几声。\n" }) );
		
        set_temp("apply/attack",500);
        set_temp("apply/armor",500);

	set("shen_type",1);set("score",200);setup();
}

void init()
{
	object ob;
	ob = this_player();
	if (interactive(ob) && !is_fighting()) 
	{
		if (present("xiao ji",ob))
		{
			command("follow " + ob->query("id"));
			kill_ob(ob);
		}
	}
}


int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		message("vision", name() + "高兴地汪汪叫了起来，叼着骨头跑远了。\n", environment());
		call_out("destroying",0);
		return 1;
	}
}

void destroying()
{
	object obj = this_object();
	destruct(obj);
}
