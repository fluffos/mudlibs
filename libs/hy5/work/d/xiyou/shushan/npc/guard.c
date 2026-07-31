//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("ÊØÉ½½£Í¯", ({ "jian tong", "tong" }));
        set("title", "ÊñÉ½½£ÅÉ");
        set("gender", "ÄÐÐÔ");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 1500);
        set("max_force", 1000);
        set("force_factor", 30);
        set("mana", 1500);
        set("max_mana", 1000);
        set("mana_factor", 30);
        set("combat_exp", 300000);
        set("daoxing", 500000);

      
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);
        setup();
        
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

