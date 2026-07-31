 inherit NPC;
void create()
{
        set_name("商人", ({ "trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位从关外来的商人。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("unarmed", 30);
        set_skill("iron-cloth", 50);
        set_skill("bloodystrike", 70);
        map_skill("unarmed", "bloodystrike");
        set("chat_chance", 2);
        set("chat_msg", ({
                "商人心有余辜的说道：我几乎死在大漠的流沙中！\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "商人说道：我有幸从大漠生还，现在居然要死在路边！\n",
                (: random_move :),
        }) ); 
        
        setup();
        add_money("coin", 50);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/teablock");
        carry_object(__DIR__"obj/perfume");
}       
