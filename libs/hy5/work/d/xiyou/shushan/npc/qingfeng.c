//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("清风", ({ "qing feng", "feng" }));
        set("long", 
"清风是蜀山剑派年轻一代的大弟子。\n");
        set("gender", "男性");
        set("age", 29);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("cor", 28);
        set("class","swordsman");
        
        set("max_kee", 1500);
        set("max_sen", 1500);
        set("force", 3000);
        set("max_force", 1500);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 1500);
        set("mana_factor", 60);
        set("combat_exp", 500000);
        set("daoxing", 700000);

       
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);

        setup();
carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

