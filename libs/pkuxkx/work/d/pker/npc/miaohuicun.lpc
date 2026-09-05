// ping.c 平一指

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("妙回春", ({ "miao huichun", "miao", "chun" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他面目和善，一向以医治人命为己任，从来不管江湖上的是是非非，
所以较之一些医术高明却性格古怪的人更加受人敬重\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
set("vendor_goods", ({
		"/d/city/obj/jinchuang",
		"/d/city/obj/yangjing",
	}));
	setup();
        //add_money("gold", 1);
        add_money("silver", 10);
	carry_object("/clone/misc/cloth")->wear();
}


void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

