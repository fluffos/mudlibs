
inherit NPC;

void create()
{

  	set_name("蒙古兵", ({ "menggu bing", "bing" }));
  	
	set("age", 22);
  set("no_clean_up", 1);
  set("max_qi", 3500);
  set("eff_qi",3500);
  set("qi",3500+random(1500));
  set("max_jing", 800);
  set("long", "一个身穿铁甲的蒙古兵。\n");

  setup();
  carry_object("/clone/weapon/gangdao")->wield();
  carry_object("/clone/armor/tiejia")->wear();

	set("chat_chance",50);
	set("chat_msg",({
		"haha",
	}));
}