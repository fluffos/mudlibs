//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("Öª¿Í½£Í¯", ({ "zhike jiantong", "jiantong","tong" }));
        set("title", "ÊñÉ½½£ÅÉ");
        set("gender", "ÄÐÐÔ");
        set("age", 12 + random(5));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 30);
        set("combat_exp", 50000);
        set("daoxing", 70000);



        setup();
carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}
