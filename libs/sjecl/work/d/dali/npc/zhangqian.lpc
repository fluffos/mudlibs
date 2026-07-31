// NPC zhangqian.c 张千

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("张千", ({ "zhang qian", "zhang","qian" }));
	set("title", "风味店老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long","这位老板正忙的满头大汗。\n");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/damage", 25);
        set("unique", 1);

	set("combat_exp", 8000);
	set("attitude", "friendly");
        set("vendor_goods", ({
        (["name":__DIR__"obj/baozi1","number":20]),
        (["name":__DIR__"obj/yang","number":20]),
        (["name":__DIR__"obj/chaoshou","number":20]),
        (["name":__DIR__"obj/mo","number":15]),
        }));
	
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
