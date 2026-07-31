 inherit NPC;
void create()
{
        set_name("司马镖师", ({ "biaotou sima","biaotou"}) );
        set("gender", "男性" );
        set("age", 42);
        
        set("long", "这是一位金狮镖局的镖师。\n");
        set("combat_exp", 2800000);
        set("attitude", "friendly");
        
        set("max_neili",500);
        set("neili",500);
        set("force_factor",30);
        
        set_skill("unarmed", 150);
        set_skill("xianglong-zhang",150);
        set_skill("dodge", 150);
        set_skill("move",200);
        set_skill("parry",150);
        set_skill("wuxing-dun",150);
        
        map_skill("dodge","wuxing-dun");
        map_skill("unarmed","xianglong-zhang");
        
        switch (random(3)) {
                case 0: set("resistance/kee",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/sen",30);
                }
                        
        set("chat_chance", 1);
        set("chat_msg", ({
                "司马镖师打了个哈欠说，该睡觉了。\n",
        }) );
        
        setup();
        add_money("silver", 5);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        if (!random(2))
        carry_object(__DIR__"obj/hongbao"); 
}        
