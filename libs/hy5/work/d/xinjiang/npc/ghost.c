 inherit NPC;
void create()
{
        set_name("¹Â»ê", ({ "ghost", " wandering ghost" }) );
        set("age", 45);
        set("env/wimpy", 70);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set("chat_chance", 10);
        set("combat_exp",random(10000));
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
} 
int is_ghost() { return 1; }      
