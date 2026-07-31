inherit NPC;
void create()
{
        string *names = ({"小虎"}); 
        set_name( names[random(sizeof(names))], ({ "baby tiger","tiger"}));
        set("vendetta_mark","tiger");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一只可爱的小虎。\n");
      
        set("str", 40);
        set("cor", 100);
        set("cps", 22); 
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("max_neili", 5000);
        set("attitude", "peaceful");
        set("chat_chance", 2);
        set("chat_msg", ({
                "小虎朝你张牙舞爪的示威。\n"
        }) ); 
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 1000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 60);
        set_temp("apply/parry", 60);
        set_temp("apply/unarmed_damage", 30);
        setup();
        carry_object(__DIR__"obj/tiger_skin");
} 
