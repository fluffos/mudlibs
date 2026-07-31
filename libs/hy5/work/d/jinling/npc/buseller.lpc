// golder.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("方安", ({"fang an","seller"}));
	set("title","绸缎庄老板");
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 50);
	set("gender","男性");

	set("force",200);
	set("max_force",200);
	set("str",70);
	set("food",200);
	set("water",200);
	set("combat_exp",1000);

	set("age", 26);
	set("long", @LONG
他就是这家绸缎庄的老板。他看起来二十多岁，专门靠买卖
绸缎，布匹为生。听说他最近接了一笔大买卖。
LONG
);
	set("vendor_goods", ({
		__DIR__"obj/chouduan",
		__DIR__"obj/bu",
		}));


	setup();

	carry_object(__DIR__"obj/silk-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
