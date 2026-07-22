// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/duke.c

inherit NPC;

void create()
{
        set_name("赌客", ({"du ke", "ke" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "这是个手气不太好的赌客，看样子是输红了眼！\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 2000);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");
        setup();

        set("chat_chance", 5);
        set("chat_msg", ({
                "赌客不怀好意的上下打量着你。\n",
                "赌客不怀好意的围着你转来转去。\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 100);
}
