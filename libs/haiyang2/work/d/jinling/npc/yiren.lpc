// yahuan.c
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("艺人", ({ "yiren","yi","ren" }) );
       set("str", 19);
	set("per", 26);
	set("age", 16);

	set("long",
		"一个中年艺人，他在路边收拾东西。\n"
		"他好象现在不卖艺。\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"艺人说道：赚钱难呀。\n",
		"艺人一点点数着包袱里的辛苦钱。\n",
		"艺人说道：我要能做个商人多好呀。\n",
	}));
	setup();
	carry_object(__DIR__"obj/linen")->wear();
       add_money("silver", 10);
}

 
