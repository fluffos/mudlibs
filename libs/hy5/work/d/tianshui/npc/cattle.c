// cattle.c
inherit NPC;
void create()
{
        set_name("大青牛", ({ "cattle" }) );
        set("race", "野兽");
        set("age", 40);
        set("long", "这是一头大青牛。");
        set("attitude", "heroism");
        set("kee", 1000);
        set("max_kee", 1000);
                
        set("gin", 1000);
        set("max_gin", 1000);
        set("sen", 1000);
        set("max_sen", 1000);
        
        set("combat_exp", 300000);
        set("limbs", ({ "头部", "身体", "尾巴","前蹄", "后蹄"}) );
        set("verbs", ({ "bite","claw" }) );
        set("str",30);
        set("cor",30);
        set("chat_chance", 80);
   
        set_temp("apply/attack", 80);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);
        setup();
}