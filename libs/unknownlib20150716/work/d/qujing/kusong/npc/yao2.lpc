//Cracked by Roath
inherit NPC;
string *namea= ({
  "鹿头怪",
  "狐头怪",
  "马头怪",
  "羊头怪",
  "兔头怪",
});


void create()
{
	string name;
	int i;
	name=namea[random(sizeof(namea))];

	set_name(name, ({"yao guai", "guai"}));

	i = 30+random(10);
	set_level(i);
	set("class", "yaomo");
	set("gender", "女性");
	set("per", 20+random(10));
	set("age", 20);
	set("force_factor", 3*i);
	set("mana_factor", 3*i);

	set("eff_dx", -1500*i);
	set("nkgain", 200);

	set_skill("parry",i*10);
	set_skill("unarmed",i*10);
  	set_skill("dodge",i*10);
	set_skill("moondance",i*10);
	set_skill("baihua-zhang",100);
	map_skill("unarmed", "baihua-zhang");
	map_skill("dodge", "moondance");
	setup();
	carry_object(0,"shoes",random(2))->wear();
	carry_object(0,"cloth",random(2))->wear();

}