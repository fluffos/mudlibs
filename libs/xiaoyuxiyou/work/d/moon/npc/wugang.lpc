// wugang.c

inherit NPC;

void create()
{
	object axe;
        set_name("吴刚", ({"wu gang","wugang","wu","gang"}));
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个气宇不凡的大汉．");
        set("attitude", "peaceful");
	set_level(70);
        set("eff_dx", 40000);
        set("nkgain", 200);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 80);
        set_skill("literate", 50);
        set_skill("force", 50);   
        set_skill("axe", 100);
        set("per", 27);
        set("max_kee", 500);
        set("max_gin", 200);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 15);
        set("env/test","HIB");
        setup();
        carry_object(0,"cloth",1)->wear();
        carry_object(0,"kui",1)->wear();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"pifeng",1)->wear();
        carry_object(0,"armor",1)->wear();
        axe = carry_object(0,"axe",0);
        if( axe )
        {
        	axe->set_name("大板斧",({"bigaxe","axe","fu"}));
        	axe->set("weapon_color","HIR");
        	axe->set("weapon_title","吴刚");
        	axe->setup();
        	axe->wield();
        }
        powerup(0,1);
}

int accept_fight(object me)
{
        command("jump");     
        command("say 正好！我砍了半天树，也该换换了。");
        return 1;
}