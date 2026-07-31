 inherit NPC;
void create()
{
        set_name("虾", ({ "shrimp" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一头虾头虾脑的野虾。 \n");
        set("max_kee", 1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) ); 
        set_skill("dodge", 80); 
        setup();
}  
