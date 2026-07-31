 inherit NPC;
void create()
{
        set_name("黑鼠", ({ "rat" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只鼠头鼠脑的黑老鼠，养的精圆滚壮。\n");
        set("max_qi", 100);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 80); 
        setup();
}    
