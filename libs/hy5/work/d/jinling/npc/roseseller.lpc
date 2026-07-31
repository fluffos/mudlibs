// golder.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("江琴", ({"jiang qin","seller"}));
	set("title","花店老板");
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 50);
	set("gender","女性");

	set("force",200);
	set("max_force",200);
	set("per",70);
	set("food",200);
	set("water",200);
	set("combat_exp",1000);

	set("age", 26);
	set("long", @LONG
她就是这家花店的老板。她看起来二十多岁，
长得美丽动人，专门靠买卖鲜花为生。
LONG
);
	set("vendor_goods", ({
		__DIR__"obj/redrose",
		__DIR__"obj/whiterose",
	}));

	setup();

	carry_object(__DIR__"obj/color_cloth")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
