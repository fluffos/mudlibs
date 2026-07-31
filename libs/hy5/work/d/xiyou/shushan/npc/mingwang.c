//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("镇狱明王", ({ "zhenyu mingwang", "wang" }));
        set("title", "");
        set("age", 1000);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 35);
        set("con", 30);
        set("cor", 40);
        
        set("max_kee", 4000);
        set("max_sen", 4000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 60);
        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 60);
        set("combat_exp", 1500000);
        set("daoxing", 3000000);

    
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
carry_object("/clone/misc/cloth")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", "\n镇狱明王道：“我没办法了...”\n", environment());
        }
        destruct(this_object());
}
