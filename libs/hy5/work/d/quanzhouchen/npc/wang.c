// wang.c
// Last Modified by winder on May. 29 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("王通治", ({ "wang tongzhi", "wang", "tongzhi" }));
	set("title", "药铺掌柜");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 35);
	set("long", "王通治号称通治，医术如何不知道，药倒是蛮齐全的。\n");
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
	set("combat_exp", 40000);
	set("vendor_goods", ({
		__DIR__"vegetable/badou",
		__DIR__"vegetable/baiwei",
		__DIR__"vegetable/baizhi",
		__DIR__"vegetable/baotai",
		__DIR__"vegetable/chaihu",
		__DIR__"vegetable/chantui",
		__DIR__"vegetable/fangfeng",
		__DIR__"vegetable/fuling",
		__DIR__"vegetable/gancao",
		__DIR__"vegetable/gouzhizi",
		__DIR__"vegetable/heye",
		__DIR__"vegetable/hugu",
		__DIR__"vegetable/huoxiang",
		__DIR__"vegetable/jinyinhua",
		__DIR__"vegetable/jugeng",
		__DIR__"vegetable/lurong",
		__DIR__"vegetable/mahuang",
		__DIR__"vegetable/moyao",
		__DIR__"vegetable/niuhuang",
		__DIR__"vegetable/sangye",
		__DIR__"vegetable/sanqi",
		__DIR__"vegetable/shengdi",
		__DIR__"vegetable/shexiang",
		__DIR__"vegetable/taohuaban",
		__DIR__"vegetable/tenghuang",
		__DIR__"vegetable/tianqi",
		__DIR__"vegetable/xionghuang",
		__DIR__"vegetable/xuejie",
		__DIR__"vegetable/zanghonghua",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
