 inherit NPC;
void smart_fight(); 
void create()
{
        set_name("¶ÏËþÔ©»ê", ({ "ghost", "wandering ghost" }) );
        set("age", 35);
        set("env/wimpy", 60);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30); 
        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor", 30); 
        set("combat_exp", 2400000);
        set("score", 200);
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),              
        }) );
        
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 150);
        set_skill("unarmed",200);
        set_skill("luoriquan",180);
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
