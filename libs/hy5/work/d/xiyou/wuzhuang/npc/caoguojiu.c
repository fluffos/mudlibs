//Cracked by Roath
// caoguojiu.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("曹国舅", ({"cao guojiu", "cao", "guojiu"}));
	//set("title", "");
	set("gender", "男性" );
	set("age", 40);
	set("per", 20);
	set("long", "一位神情严肃的中年人。曹国舅名景休，天资纯善，\n不喜富贵，酷慕清虚。其弟骄纵不法，后罔逃国宪。\n曹国舅深以为耻，遂隐迹山林，精思元理。后投入镇元门下。\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 200000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 60);
	

	setup();
	initlvl((300+random(280)),16);
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/hammer/baiyuban")->wield();
}

