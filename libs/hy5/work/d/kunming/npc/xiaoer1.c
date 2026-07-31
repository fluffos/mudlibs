// xiaoer2.c 酒店小二


inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/baozi",
		__DIR__"obj/niurou",
		__DIR__"obj/huasheng"
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int init()
{	add_action("do_buy","buy");
	add_action("do_list","list");
}