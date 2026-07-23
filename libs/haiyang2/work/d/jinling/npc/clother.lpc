// golder.c
inherit NPC;
inherit F_DEALER;
int do_make(string arg);

void create()
{
	set_name("孙大娘", ({"clother","sen"}));
	set("title","裁缝店老板娘");
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	set("gender","女性");

	set("force",100);
	set("max_force",100);
	set("str",70);
	set("food",200);
	set("water",200);
	set("combat_exp",1000);

	set("age", 37);
	set("long", @LONG
孙大娘是最近才来到金陵的，她看起来四十岁左右，身材已
经不是很好，但是丰韵由存，她年轻是时候一定是个美人。
LONG
);
	set("vendor_goods", ({
		__DIR__"obj/color_cloth",
		__DIR__"obj/color_pants",
		__DIR__"obj/silk_bra",
		__DIR__"obj/silk-cloth",
		__DIR__"obj/pink_cloth",
		__DIR__"obj/linen",
		__DIR__"obj/flower-shoes",
		__DIR__"obj/shoes",
		__DIR__"obj/color_head",												
		__DIR__"obj/headband",													
	}));


	setup();

	carry_object(__DIR__"obj/color_cloth")->wear();
	carry_object(__DIR__"obj/jiandao")->wield();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

