// huoji.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小伙计", ({"huo ji"}));
	set("long", @TEXT
一个二十多岁的小伙计正忙着给客人称药。
TEXT
        );
	set("gender","男性");
	set("age",25);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	// 药铺昼夜营业。
	set("sell_all_day",1);

	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/clone/misc/yaodan",
                "/clone/misc/neilidan",
		"/d/shenlong/obj/xionghuang",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");


}