// xiansheng.c 教书先生
inherit NPC;

void create()
{
	set_name("教书先生", ({ "xian sheng", "teacher" , "xiansheng" }));
	set("long", "他就是慕容家请来的教书先生。\n");
	set("gender", "男性");
	set("age", 65);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 120000);
	set("shen_type", 1);
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}
