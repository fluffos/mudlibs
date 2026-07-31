// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("老渔翁", ({ "yu weng", "fisherman", "laoyuweng" }) );
	set("gender", "男性" );
	set("age", 60+random(10));
	set("long", "这是一位满脸红光的老人,身披绿蓑衣,悠然自得。
由于他经常出海,你可以向他打听出海的事情.\n");

	set("combat_exp",4000);


	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	setup();
	carry_object("/d/hainan/obj/shuoyi")->wear();
}
