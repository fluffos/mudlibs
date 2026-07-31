 inherit NPC;
void create()
{
        set_name("菜花蛇", ({ "snake" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一条普通的菜花蛇，在乡间很常见，没有什么毒性。\n"); 
        set("limbs", ({ "头部", "身体", "尾巴", "七寸" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 10);
        set("combat_exp", 10000);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: random_move :),
        }) );
        setup();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}   
