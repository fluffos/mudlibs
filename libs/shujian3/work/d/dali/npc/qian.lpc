// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem

inherit NPC;
inherit F_BANKER;

void create()
{
         set_name("严掌柜", ({"yan zhanggui", "yan", "zhanggui"}));
         set("title", "大理钱庄老板");
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

        set("combat_exp", 100000);
        set("unique", 1);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 2);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        add_money("silver", 35);
}

void init()
{
        ::init();
        add_action("do_check", ({"check", "chazhang", "查帐"}));
        add_action("do_convert", ({"convert", "duihuan", "兑换"}));
        add_action("do_deposit", ({"deposit", "cun", "存"}));
        add_action("do_withdraw", ({"withdraw", "qu", "取"}));
}
