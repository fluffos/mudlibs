//Cracked by Roath
// xiaomaolu.c

inherit NPC;

void create()
{
	set_name("小毛驴", ({"xiao maolu", "maolu", "lu"}));
	set("race", "野兽");
	set("age", 10);
	set("combat_exp", 10000);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite"}));

	set("ride/msg", "倒骑");
	set("ride/dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 20);

	setup();
}

void die()
{
	if( environment() )
	{
		if( environment()->is_sea() )
			message("vision","\n一道巨浪打来，小毛驴躲闪不及，被浪花卷的无影无踪！\n\n",environment());
		else	message("vision","\n小毛驴一声惊啼，撒开了丫子，一骑绝尘跑的无影无踪！\n\n",environment());	
	}
	destruct(this_object());
}	

void unconcious()
{
	die();
}