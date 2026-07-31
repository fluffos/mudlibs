 inherit NPC;
void create()
{
        set_name("风骚雅人", ({ "yaren", "ren"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是一位小有才华的雅人，正在追求灵感。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("intellgent",1);
        
        set_skill("dagger", 100);
        set_skill("dodge", 100);   
        set_skill("iron-cloth", 200);
        set_skill("unarmed",100);
        set_skill("parry",100);
        
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "风骚雅人吟唱，「银烛秋光冷画屏，轻罗小扇扑流萤。天街夜色亮如水，卧看牛郎织女星。」\n",
                "风骚雅人踱来踱去，似乎正在打腹稿。\n",
        }) );
        
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/fycloth")->wear();
        carry_object(__DIR__"obj/ironpen")->wield();
}     
