// doctor_li.c
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("李德志", ({"li dezi","li","doctor"}));
	set("long", @TEXT
李德志是雪亭镇药房的老板。雪亭没有专职的医生，
据说他略通医术，人们有一些小病小灾的都来找他。
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
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
