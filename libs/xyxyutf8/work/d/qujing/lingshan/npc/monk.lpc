// snowcat 12 14 1997

inherit NPC;

void create()
{
	int i = 140+random(20);
  	if (random(2))
    		set_name("阿罗", ({ "a luo", "a", "luo" }));
  	else	set_name("揭谛", ({ "jie di", "jie", "di" }));
  	set_level(i);
	set("title", "灵山");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "peaceful");
	set("force_factor",i*10);
	set("mana_factor",i*10);

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