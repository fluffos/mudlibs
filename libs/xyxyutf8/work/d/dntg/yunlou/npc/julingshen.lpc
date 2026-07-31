 
inherit NPC;
 
void create()
{
 
        set_name("巨灵神", ({ "juling shen", "shen", "juling" }) );
        set("gender", "男性" );
        set("long","托塔李天王帐下先锋大将，膀阔腰圆，力大无穷。\n");
        set("age",40);
        set_level(150);
	set("title", "先锋大将");
        set("per", 15);
	set("class", "xian");
	set("attitude", "heroism");
	set("daoxing", 200000);
	set("force_factor", 60);
	set("mana_factor", 40);

        set("eff_dx", 400000);
        set("nkgain", 400);

	set_skill("unarmed",1250);
        set_skill("dodge",1250);
        set_skill("parry",1250);
	set_skill("axe", 1250);
	set_skill("force", 1250);
	set_skill("spells", 1250);
 	set_skill("changquan", 1250);
	set_skill("sanban-axe", 1250);
	set_skill("baguazhou", 1250);
	set_skill("moshenbu", 1250);
	set_skill("lengquan-force", 1250);
	map_skill("unarmed", "changquan");
	map_skill("force", "lengquan-force");
	map_skill("spells", "baguazhou");
	map_skill("axe", "sanban-axe");
	map_skill("parry", "sanban-axe");
	map_skill("dodge", "moshenbu");
	set_temp("armor_level",30+random(30));
	set_temp("weapon_level",50+random(30));
        setup();
        carry_object(0,"armor",random(5))->wear();
        carry_object(0,"kui",random(5))->wear();
        carry_object(0,"pifeng",random(5))->wear();
        carry_object(0,"shoes",random(5))->wear();
	carry_object(0,"axe",random(5))->wield();
}