//Cracked by Roath
inherit NPC;
string *namea= ({
  "É½Ã¨¹Ö",
  "²ÔÀÇ¹Ö",
  "Ò°Öí¹Ö",
  "×ØĞÜ¹Ö",
  "»¨»¢¹Ö",
  "ºÚòş¹Ö",
  "¾ŞÔ³¹Ö",
});


void create()
{
	string name, str;
	int i;
	name=namea[random(sizeof(namea))];

	set_name(name, ({"yao guai", "guai"}));

	i = random(5) + 6;
	set("class", "yaomo");
	set("gender", "ÄĞĞÔ");
	set("attitude", "heroism");
	set("per", 10);

	set("age", 20+random(40));
	set("max_qi", 100*i);
	set("max_jing", 100*i);
	set("neili", 100*i);
	set("max_neili", 100*i);
	set("force_factor", 5*i);
	set("neili", 100*i);
	set("max_neili", 100*i);
	set("mana_factor", 5*i);

	set("combat_exp", 20000*i+random(50000));
	
	set("eff_dx", -8000*i);
	set("nkgain", 300);

	set_skill("parry", 10*i);
	set_skill("unarmed", 10*i);
  	set_skill("dodge", 10*i);
  	set_skill("blade", 10*i);
  	set_skill("staff", 10*i);
  	set_skill("sword", 10*i);
  	set_skill("whip", 10*i);
  	set_skill("axe", 10*i);

	map_skill("dodge", "moshenbu");
	setup();
	carry_object("/d/qujing/kusong/obj/tongjia")->wear();
	str="/d/qujing/kusong/obj/weapon0";
	str[strlen(str)-1] = '0'+random(5);
  	carry_object(str)->wield();
	add_money("silver", random(5));
	add_money("coin", random(90));
}

void init()
{
	object ob;
	::init();

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));

	if(interactive(ob = this_player()) && 
                (string)ob->query("family/family_name")!="»ğÔÆ¶´" ){
		call_out("greeting", 10, ob);
		return;
	}
	return;
}

int greeting(object ob)
{
	if( !ob || !visible(ob) || environment(ob) != environment() ){
		return 1;
	}

	command("kill " + ob->query("id"));
	return 1;
}
ÿ