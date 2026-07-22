//Cracked by Roath
inherit NPC;
string *namea= ({
  "山猫怪",
  "苍狼怪",
  "野猪怪",
  "棕熊怪",
  "花虎怪",
  "黑蟒怪",
  "巨猿怪",
});


void create()
{
	string name, str;
	int i;
	name=namea[random(sizeof(namea))];

	set_name(name, ({"yao guai", "guai"}));

	i = 30+random(15);
	set_level(i);
	set("class", "yaomo");
	set("gender", "男性");
	set("attitude", "heroism");
	set("per", 10);

	set("age", 20+random(40));
	set("force_factor", 5*i);
	set("mana_factor", 5*i);

	
	set("eff_dx", -8000*i);
	set("nkgain", 300);

	set_skill("parry",i*10);
	set_skill("unarmed",i*10);
  	set_skill("dodge",i*10);
  	set_skill("blade",i*10);
  	set_skill("fork",i*10);
  	set_skill("sword",i*10);
  	set_skill("whip",i*10);
  	set_skill("axe",i*10);
	set_skill("moshenbu",i*10);
	map_skill("dodge", "moshenbu");
	setup();
	carry_object(0,"armor",random(2))->wear();
	str="/d/qujing/kusong/obj/weapon0";
	str[strlen(str)-1] = '0'+random(5);
  	carry_object(str)->wield();
	add_money("silver", random(5));
	add_money("coin", random(90));
}
