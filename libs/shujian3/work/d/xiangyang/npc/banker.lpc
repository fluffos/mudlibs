// banker.c
// Looklove y2k/4/9

inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("钱善人", ({"qian shanren", "qian", "banker"}));
        set("title", "钱庄老板");
        set("gender", "男性");
        set("age", 34);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100);
        set("shen", 0);
        set("no_get", 1);

        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
		"钱善人骄傲的说道：本银号已经有上百年的历史，在襄阳城可以说是第一家。\n",
		"钱善人愉快的说：在本店存钱免费，取钱收百分之五手续费，客官您看着办吧。\n",
		"钱善人小声说道：最近城里来了不少武林人士，有你认识的吗？\n"
        }));

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(MISC_D("denglong2"));
	add_money("gold", 1);
}

void init()
{
	::init();
        add_action("do_check", ({"check", "chazhang", "查帐"}));
        add_action("do_convert", ({"convert", "duihuan", "兑换"}));
        add_action("do_deposit", ({"deposit", "cun", "存"}));
        add_action("do_withdraw", ({"withdraw", "qu", "取"}));
}
