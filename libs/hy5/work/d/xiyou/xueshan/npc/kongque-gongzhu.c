// kongque-gongzhu.c...weiqi, 97.09.15.

inherit NPC;

string get_ice(object me);
void do_drop(object ob);

void create()
{
	set_name("孔雀公主", ({"kongque gongzhu", "kongque", "gongzhu"}));
	set("title", "明王护法");
	set("gender", "女性" );
	set("age", 23);
	set("per", 21);
set("long", @LONG
这位孔雀公主是孔雀明王的女儿。孔雀明王被佛祖如来
押至灵山后，她由大鹏明王一手带大。说是侄女，与大
鹏明王实则有父女之情。
LONG );
	set("class", "yaomo");
	set("combat_exp", 800000);
 	set("daoxing", 500000);

	set("attitude", "peaceful");
	create_family("大雪山", 2, "弟子");
	set_skill("unarmed", 140);


	set("max_kee", 1000);
	set("max_sen", 600);
	set("force", 3000);
	set("max_force", 1500);
	set("mana", 3000);
	set("max_mana", 1500);	
	set("force_factor", 75);
	set("mana_factor", 76);
       set("eff_dx", -200000);
       set("nkgain", 400);


            setup();
	carry_object("/d/xiyou/xueshan/obj/nihong-yuyi")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
       carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/sword/fenghuangqin")->wield();
}

