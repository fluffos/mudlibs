//created by greenwc
//created by greenwc
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("大势至菩萨", ({"dashizhi pusa", "dashizhi", "dashi", "pusa"}));
  set ("long", @LONG
南无阿弥陀佛次徒，观世音菩萨的师弟，三
人并称西方三神。
LONG);
  set("title", "西方三神之");
  set("gender", "男性");
  set("age", 400);
  set("str", 40);
  set("per", 40);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
    
           set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jing", 5000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("force_factor", 150);
	set("max_neili", 3000);
	set("neili", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("combat_exp", 10000000);

	create_family("南海普陀山", 1, "菩萨");
  setup();
      initlvl((1000+random(1000)),random(63));
	carry_object("/d/obj/weapon/hammer/falun2")->wield();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}



void die()
{
        if( environment() ) {
        message("sound", "\n\n大势至菩萨摇头叹道：冤孽！真是冤孽！n\n", environment());
        command("sigh");
        message("sound", "\n大势至菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
}

	destruct(this_object());
}
