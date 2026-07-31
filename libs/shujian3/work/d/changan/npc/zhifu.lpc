// Write By Yanyang@SJ 2001.9.28
// NPC: /d/changan/zhifu.c

inherit NPC;

void create()
{
        set_name("知府大人", ({"zhifu daren", "zhifu","daren"}) );
        set("gender", "男性" );
        set("age", 55);
        set("long", "他是长安城的知府，正低着头批阅着文书。\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 5000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude","heroism");
        setup();

        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver", 100);
}
