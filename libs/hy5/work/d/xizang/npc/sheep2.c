 inherit NPC;
void create()
{
        set_name("大绵羊", ({ "sheep" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只全身雪白的的绵羊。\n"); 
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("str",15);
        set("combat_exp", 25000); 
        setup();
}       
