inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("小二儿", ({ "xiao er", "waiter" }) );
        set("gender", "男性" );
        set("per",66 );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
                __DIR__"obj/shanlw",
                __DIR__"obj/qiankun-dai",
        }));
        setup();
}

void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
}
