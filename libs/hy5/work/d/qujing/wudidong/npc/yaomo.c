// jiading.c

inherit NPC;

void create()
{
       set_name("巡山妖", ({"yaomo"}));

set("long","一个相貌凶险的盗贼, 你仔细一看, 只见他股后似
有一条尾巴。啊！难怪盗贼如此凶狠，原是早已豺
狼成精，并非凡胎啊。\n");
       set("gender", "男性");
       set("age", 20+random(15));
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 300000);
  set("combat_exp", 33150000);

        set_skill("unarmed", 70);
	set("per", 5);
	set("bellicosity", 50000);
	set_skill("parry", 65);
	set("max_qi", 8000);
        set("max_jing", 8000);
	set_skill("dodge", 365);
	set_skill("blade", 360);
	

	setup();
        add_money("silver", 20);
	carry_object("/clone/weapon/blade")->wield();
}
