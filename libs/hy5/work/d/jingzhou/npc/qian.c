
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
// congw 980829 modify
// jackyboy @cctx modify 98/12/29 for inherit F_BANKER;
inherit NPC;
inherit F_BANKER;


void create()
{
    set_name("钱得发", ({"qian defa","qian", "defa"}));
    set("title", "钱庄老板");
    set("nickname", "钱拔皮");
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

    set("combat_exp", 50000);
    set("shen_type", 1);
    set("attitude", "friendly");
    set("env/wimpy", 50);
    set("chat_chance", 2);
    set("chat_msg", ({
	"钱得发骄傲的说道：本银号已经有上百年的历史，在江南可以说是第一家。\n",
	"钱得发笑着说道：在本店存钱无利息，取钱收十分之二的手续费，客官您看着办吧。\n"
	"钱得发微微一笑，说道：本店还办理不同面额货币的兑换业务，但每次要收十分之一的手续费。\n"
      }));

    set_skill("unarmed", 50);
    set_skill("dodge", 50);
    set_temp("apply/attack", 100);
    set_temp("apply/defense", 100);
    set_temp("apply/damage", 40);

    setup();
    add_money("silver", 10);
    carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}

