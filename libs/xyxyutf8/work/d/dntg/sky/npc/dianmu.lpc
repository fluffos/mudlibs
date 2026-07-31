//sgzl

inherit NPC;

void create()
{
	set_name("电母",({"dian mu","dian shen","mu"}));
	set("gender", "女性");
	set("age", 45);
	set("long", "    \n一端庄秀雅的天神，在天宫中负责闪电。\n");
	set_level(151);
	set("daoxing", 2200000);	
	set("attitude", "heroism");
	set("class", "xian");

	set("force_factor", 30);
	set("mana_factor", 30);
	set_skill("dodge", 1480);
	set_skill("jindouyun", 1480);
	set_skill("unarmed", 1480);
	set_skill("puti-zhi", 1480);
	set_skill("spells", 1480);
	set_skill("parry", 1480);


	map_skill("dodge", "jindouyun");
	map_skill("unarmed", "puti-zhi");
	set("inquiry", ([
  		"闪电"   : "没到时候。",
	]));
   	set_temp("armor_level",50);
   	set_temp("weapon_level",50);
	setup();
	carry_object(0,"cloth",random(5))->wear();
	carry_object(0,"shoes",random(5))->wear();
	add_money("silver", 10);
}

