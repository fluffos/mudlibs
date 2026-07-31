// huiboss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("ÒÀ²»ËÀ", ({"yi busi"}));

	set("title","»Ø´ºÌÃÕÆ¹ñ");

	set("long", @TEXT
Ëû¾ÍÊÇ»Ø´ºÌÃÕÆ¹ñ¡£
TEXT
        );
	set("gender","ÄÐÐÔ");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	// Ò©ÆÌÖçÒ¹ÓªÒµ¡£
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