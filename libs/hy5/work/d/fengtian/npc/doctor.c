// doctor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("胡大夫", ({"doctor hu"}));
	set("long", @TEXT
胡大夫的医术在盛京小有名气。
TEXT
        );
	set("gender","男性");
	set("age",55);
	set("con",20);
	set("str",20);
	set("combat_exp",200);
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