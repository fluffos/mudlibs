// cuicui.c 崔老板

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("崔老板", ({ "cui laoban", "laoban", "cui", "cuicui" }));
        set("shen_type", 0);
        set("gender", "男性");
        set_max_encumbrance(100000000);
        set("age", 24);
        set("long",
                "这个当铺老板正眯缝着眼睛在盯着你看来看去。\n");
        set("no_get_from", 1);

        set("no_clean_up", 0);
        set_skill("unarmed", 600);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 2000000);
        set("attitude", "friendly");
	set("inquiry", ([
		"name" : "在下姓崔名吹，不过大家都习惯叫我老崔。\n",
		"崔吹" : "啊？找我啊，你有话就说嘛，你不说我怎么知道呢。\n",
		"rumors" : "听说最近辽东有几个高手进关了。\n",
		"cs" : "ｐｌａｙｃｓ！ｃｏｍｅｏｎｂａｂｙ！\n",
		"name" : "在下姓崔名吹，不过大家都习惯叫我老崔。\n",
	]));

        setup();
        carry_object(ARMOR_D("changshan"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
}
