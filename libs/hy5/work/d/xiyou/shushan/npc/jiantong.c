//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("½£Í¯", ({ "jian tong", "tong" }));
        set("title", "ÊñÉ½½£ÅÉ");
        set("gender", "ÄÐÐÔ");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 500);
        set("max_sen", 500);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 500);

     
        setup();
        
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}