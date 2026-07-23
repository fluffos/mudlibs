 inherit NPC;
void smart_fight(); 
void create()
{
        set_name("冤魂", ({ "crying ghost" }) );
        set("age", 45);
        set("env/wimpy", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("fle",50);
        set("max_neili", 800);
        set("neili", 800);
        set("force_factor", 20); 
        set("combat_exp", 2000000);
        set("score", 200);
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),              
        }) );
        
        set_skill("move", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set_skill("luoriquan",150);
        set_skill("fengyu-piaoxiang",200);
        
        map_skill("unarmed","luoriquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");    
           
        setup();
} 
int is_ghost() { return 1; } 
smart_fight()
{
        int i;
        object *enemy;
   enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->is_busy()) {
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.zonghengsihai");
        return;
}
smart_attack() {
        return;
}    
