 
inherit NPC;
 
void create()
{
 
        set_name("李靖", ({ "li jing", "jing" }) );
        set("gender", "男性" );
	set("long", "托塔李天王乃是天界元帅，麾下十万天兵天将，法力无边。\n");
        set("age",40);
	set("title", "托塔天王");
        set("str", 40);
        set("int", 20);
	set("con", 30);
	set("spi", 30);
        set("per", 30);
	set("class", "xian");
	set("attitude", "heroism");
        set("combat_exp", 1500000);
  set("daoxing", 2000000);

	set("max_kee", 1800);
	set("max_sen", 1800);
        set("force",3000);
        set("max_force",2000);
	set("force_factor", 110);
	set("mana", 3000);
	set("max_mana", 2000);
	set("mana_factor", 110);

        set("eff_dx", 600000);
        set("nkgain", 600);

        set_skill("unarmed",170);
        set_skill("dodge",170);
        set_skill("parry",170);
	set_skill("sword", 180);
	set_skill("force", 170);
	set_skill("spells", 170);
 	set_skill("changquan", 170);
	set_skill("liangyi-sword", 180);
	set_skill("baguazhou", 170);
	set_skill("moshenbu", 170);
	set_skill("lengquan-force", 170);
	map_skill("unarmed", "changquan");
	map_skill("force", "lengquan-force");
	map_skill("spells", "baguazhou");
	map_skill("sword", "liangyi-sword");
	map_skill("parry", "liangyi-sword");
	map_skill("dodge", "moshenbu");
        setup();
	carry_object("/d/obj/fabao/huangjin-baota");
        carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/sky/obj/zhanyaojian")->wield();
}
 

