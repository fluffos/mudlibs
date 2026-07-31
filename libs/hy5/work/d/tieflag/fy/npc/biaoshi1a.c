 inherit NPC;
void create()
{
        set_name("趟子手", ({ "tang", "tang zishou"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位体态轻盈的趟子手。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move",800);
        set_skill("changquan",100);
        map_skill("unarmed","changquan");
        set("chat_chance", 1);
        set("chat_msg", ({
                "趟子手说：“唉，整天过这刀头上舔血的日子。“\n",
                "趟子手说：“这几天路上不太平，千万不要出事才好。“\n",
                "趟子手说：“老子保镖这么多年，还没杀过人呢。“\n",
        }) );
        
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
}   
