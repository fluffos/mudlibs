// Write By Yanyang@SJ 2001.10.2
// NPC: /d/changan/zhplaoban.c

inherit NPC;
inherit F_VENDOR;


void create()
{
        set_name("刘老实", ({ "liu laoshi", "laoshi", "liu" }));
        set("title","杂货铺老板");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 43);
        set("long", "刘老实正盯着你看，不知道打些什么主意。\n");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/damage", 100);

        set("combat_exp",40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                (["name": MISC_D("denglong"),"number":5]),
                (["name": MISC_D("mabudai"),"number":5]),
                (["name": BINGQI_D("txs"),"number": 5]), 
                (["name": BINGQI_D("xiuhua"),"number":5]),
                (["name": MISC_D("paper"),"number":50]),
                (["name": MISC_D("fire"),"number":5]),
        }));

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 2);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
