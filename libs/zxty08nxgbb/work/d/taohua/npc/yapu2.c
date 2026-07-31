inherit NPC;
void create()
{
        set_name("哑仆", ({"yapu"}));
        set("gender", "男性");
        set("age", 56);
        set("long", 
        "这是位既聋且哑，满脸风霜之色的老仆人。\n");
        set("attitude", "peaceful");
        set("str", 28);
        set("int", 17);
        set("con", 25);
        set("dex", 21);
        set("max_qi", 300);
        set("max_qi", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 30);
        set("combat_exp", 10000);
        set_skill("force", 50); 
        set_skill("huntian-qigong", 55); 
        set_skill("unarmed", 55); 
        set_skill("xianglong-zhang", 55); 
        set_skill("dodge", 35); 
        set_skill("xiaoyaoyou", 50); 
        set_skill("parry", 50);
        set_skill("begging", 40); 
        set_skill("stealing", 50); 
        
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
