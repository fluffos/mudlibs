// snowcat 12 14 1997

inherit NPC;

void create()
{
	int i = 160+random(10);
  	set_name("菩萨", ({ "pu sa", "pu", "sa" }));
  	set("title", "灵山");
  	set("gender", "男性");
  	set("age", 1000);
  	set("attitude", "peaceful");
	set("force_factor", 120);
	set("mana_factor", 120);

	set_skill("spells",i*10);
	set_skill("buddhism",i*10);
	set_skill("unarmed",i*10);
	set_skill("jienan-zhi",i*10);
	set_skill("dodge",i*10);
	set_skill("lotusmove",i*10);
	set_skill("parry",i*10);
	set_skill("force",i*10);
	set_skill("lotusforce",i*10);
	set_skill("staff",i*10);
	set_skill("lunhui-zhang",i*10);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	setup();
	carry_object("/d/obj/cloth/jia_sha")->wear();
}