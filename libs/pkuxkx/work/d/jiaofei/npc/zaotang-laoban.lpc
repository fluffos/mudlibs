// yaopu-laoban.c 药铺老板
// by skywolf 2009-2-5 for wuzhishan-yaopu

inherit NPC;
inherit F_DEALER;

int ask_cuozao();
void create()
{
	set_name("澡堂老板", ({ "zaotang laoban", "laoban" }));
	set("gender", "男性");
	set("long", "一位澡堂老板，凭着祖传的精油配方在这个土匪窝混饭吃。\n");
	set("age", 68);

	set("combat_exp", 5000);
	set("attitude", "friendly");

	set("vendor_goods", ({
	}));
       set("inquiry", ([
       "搓澡" :"五十两黄金一次，在我这里交钱。",
    ]));

	set("shen_type",1);set("score",500);setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
//add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
    if (ob->query("money_id") && ob->value() >= 500000)
    {
        who->set_temp("jiaofei/bath_paid",1);
        return 1;
    }
    return 0;
}
