// dapeng.c...weiqi, 97.09.27.

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("大鹏明王", ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
	set("title", "雪山之祖");
	set("gender", "男性" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "这位大鹏明王的确大有来历，说起来跟佛祖如来也有点亲戚关系，\n算是如来的“舅舅”。他不似其兄孔雀明王作恶多端，却也并非善类，\n且因其兄之故跟佛门结下深仇。生平最讨厌的就是和尚。\n");
	set("class", "yaomo");
	set("combat_exp", 1800000);
	set("daoxing", 3000000);

	set("attitude", "peaceful");
	create_family("大雪山", 1, "祖师");
	set("rank_info/respect", "明王");
 
	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);

            setup();
	carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}


