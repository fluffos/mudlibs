inherit NPC;
void create()
{
        set_name("帮众", ({ "di zi", "zi" }));
        set("gender", "男性");
        set("age", 19);
        set("long", "他是天涯第一城的帮众，负责看守城门。\n");
        
        set("combat_exp", 10000000);
        set("zjb_dj/dj",10);
        set("shen_type", -1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        setup();
        carry_object("/clone/misc/hic_cloth")->wear();
        add_money("silver",2);
}
