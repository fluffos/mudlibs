// xian. 冼老板

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("欧阳老板", ({ "ouyang laoban", "ouyang" }));
        set("title", "云雪楼酒楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
        set("long", "欧阳老板经营祖传下来的云雪楼酒楼已有多年。\n");
        set("combat_exp", 20000);
        set("qi", 300);
        set("max_qi", 300);
        set("unique", 1);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
        (["name":__DIR__"obj/hdjiudai","number":20]),
        (["name":__DIR__"obj/yuebing","number":20]),
        (["name":__DIR__"obj/kaoya","number":15]),
	}));

	setup();
        add_money("silver", 40);
}

void init()
{	 
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
