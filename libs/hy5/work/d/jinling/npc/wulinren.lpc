// yahuan.c

inherit NPC;

void create()
{
	set_name("武林中人", ({ "man" }) );
       set("str", 59);
	set("per", 26);
	set("age", 30);

	set("long",
		"一个中年人，看起来好象会点武功。\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"武林中人说道：这次来这里......\n",
		"武林中人注视着四周的一切。\n",
	}));
	setup();
	carry_object(__DIR__"obj/silk-cloth")->wear();
       carry_object(__DIR__"obj/longsword")->wield();
       add_money("silver", 10);
}

 
