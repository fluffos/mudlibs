// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem

inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("言达平", ({"yan daping", "yan", "daping"}));
        set("title", "襄阳武馆帐房");
        set("long","身形消瘦，双目炯炯有神，看起来象一个衣饰华贵的大财主。\n");
        set("gender", "男性");
        set("age", 54);    
        set("combat_exp",90000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("eff_jingli", 600);

        set_skill("force", 80);
        set_skill("strike", 80);  
        set_skill("dodge", 80);
        set_skill("parry", 80);     
        set_skill("shenzhao-jing", 80);
        map_skill("force","shenzhao-jing");

        setup();
        add_money("gold", 1);
        carry_object(ARMOR_D("jinduan"))->wear();
}

void init()
{
        ::init();
        add_action("do_check", ({"check", "chazhang", "查帐"}));
        add_action("do_convert", ({"convert", "duihuan", "兑换"}));
        add_action("do_deposit", ({"deposit", "cun", "存"}));
        add_action("do_withdraw", ({"withdraw", "qu", "取"}));
}
