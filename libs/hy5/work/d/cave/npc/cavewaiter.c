 // waiter.c
inherit NPC;
inherit F_VENDOR;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("大食堂跑堂", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long",
                "这位大食堂跑堂正皮笑肉不笑地看着你，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("attitude", "friendly");
        
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        set("class","bat");
        set("force",800);
        set("max_neili",800);
        set("force_factor",10);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("blade",150);
        set_skill("bat-blade",140);
        set_skill("meng-steps",150);
        set_skill("move",200);
        set_skill("blade",150);
        set_skill("luoriquan",150);
        
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
        map_skill("blade","bat-blade");
        map_skill("parry","bat-blade");
        map_skill("unarmed","luoriquan");
        

        set("rank_info/respect", "大师傅");

        	set("vendor_goods", ({
		__DIR__"obj/wineskin",
		__DIR__"obj/dumpling",
		__DIR__"obj/chicken_leg",
	}));
        
        
        setup();
        
        carry_object("/clone/misc/cloth")->wear();

} 
void init()
{       
        object ob;
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}   
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
        this_object()->perform_action("dodge.huanyinqianchong");
}
smart_attack() {
        this_object()->perform_action("blade.shiwanshenmo");    
        }     
