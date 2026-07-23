// yahuan.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("商人", ({ "shangren","shopper","shang" }) );
       set("str", 19);
	set("per", 26);
	set("age", 30);

	set("long",
		"一个中年商人，他背着个沉甸甸的包袱。\n"
		"他不停的四出张望着。\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"商人说道：赚钱不容易呀。\n",
		"商人一点点数着包袱里的银子。\n",
	}));
	setup();
	carry_object(__DIR__"obj/silk-cloth")->wear();
       add_money("silver", 80);
}

 
