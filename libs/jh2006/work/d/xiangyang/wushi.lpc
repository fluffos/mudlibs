inherit NPC;

void create()
{
        set_name("蒙古武士", ({ "wushi","fighter" }) );
        set("gender", "男性" );
        set("age", 35+random(10));
        set("attitude", "aggressive");
        set("str", 40+random(5));
        set("con", 40+random(5));
        set("int", 20+random(10));
        set("dex", 30+random(10));
 

        set("max_qi", 6500+random(500));
        set("max_jing", 6500+random(500));
        set("neili", 5000+random(1000));
        set("eff_jingli", 6500+random(500));
        set("max_neili", 5000+random(500));
        set("jiali", 150);
         
        set("combat_exp", 1500000);

        set_skill("force", 200); 
        set_skill("cuff", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("spear", 200);
        set_skill("bawang-qiang", 200);
        set_skill("taizu-quan", 200);
        set_skill("jinyan-gong", 200);
        set_skill("xiantian-gong",200);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("cuff", "taizu-quan");
        map_skill("parry", "taizu-quan");
        map_skill("spear", "bawang-qiang");
        prepare_skill("cuff", "taizu-quan");

        setup();
        carry_object(ARMOR_D("armor"))->wear();
        carry_object("/clone/weapon/changqiang")->wield();
}

void die()
{
    object me = this_object();
    object ob;

    if( objectp(me->query_temp("last_damage_from"))) {
        ob = me->query_temp("last_damage_from");
        ob->add_temp("xy/job",2);
    }
    ::die();
}
