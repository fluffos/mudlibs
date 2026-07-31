// lanlan.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("兰兰", ({ "lan lan", "lan" }));

	set("gender", "女性");
	set("age", 20);
	set("per", 30);
	set("con", 30);
	set("int", 30);
	set("level", 99);
	set("dex", 30);
	set("icon","02046");
	set("str", 30);
	set("long",
 "她是angelus的未婚妻，在这里帮忙搭理成衣铺，卖些自己设计的衣服。
有人说那都是angelus从2010年弄来的禁品。话这么说，生意照样红活的晕倒。\n");
	set_skill("unarmed", 600);
	set_temp("apply/damage", 150);
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"cloth/moon-dress",
		__DIR__"cloth/pink-dress",
		__DIR__"cloth/qi-dress",
		__DIR__"cloth/red-dress",
		__DIR__"cloth/scarf",
		__DIR__"cloth/sha-dress",
		__DIR__"cloth/shoes",
		__DIR__"cloth/xian-cloth",
		__DIR__"cloth/xiu-cloth",
		__DIR__"cloth/xiu-scarf",
		__DIR__"cloth/yan-dress",
		__DIR__"cloth/zi-dress",


	}));
	
	setup();
	carry_object(__DIR__"cloth/feature")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
