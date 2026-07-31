// jishi.c


inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("王济世", ({ "wang jishi","wang" }) );
        set("title", "药铺老板");
        set("gender", "男性" );
        set("age", 55);
        set("long", "他就是药铺的老板王济世，一位忠厚长者。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
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
        set("inquiry", ([
                "抓药" : "这里是附近最好的药店，您要什么？",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");


}