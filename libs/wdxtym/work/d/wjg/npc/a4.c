// killer.c
// by doing

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"万"HIG"剑"HIC"阁"WHT"主"NOR"", ({ "gezhu", "gezhu" }) );
	set("gender", "男性" );
	set("age", 20 + random(20));

	set("long",
		"这是一个身材高大的江湖人，两臂粗壮，膀阔"
		"腰圆，看起来似乎不怀好意。\n"
	);

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("tsboss",1);
	set("twtnpc",1);
    set("max_qi", 3000000);
	set("eff_qi", 3000000);
	set("qi", 3000000);
	set("max_neili", 3000000);
	set("neili", 3000000);
	set("max_jing", 3000000);
	set("eff_jing", 3000000);
	set("jing", 3000000);
	set("combat_exp", 30000000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"不屈魂幽幽道：守护万剑阁楼，是我们一生的使命！\n",
		"不屈魂低叹道：逃的逃，死的死，万剑阁楼已经不复当年风光\n",
	}) );

	set_skill("blade", 180);
	set_skill("dodge", 180);
	set_skill("unarmed", 180);
	set_skill("parry", 180);
	set_skill("wuhu-duanmendao", 180);
	set_skill("feiyan-zoubi", 180);

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");

	set_temp("apply/damage",525);
	set_temp("apply/attack", 525);
	set_temp("apply/defense", 525);

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	call_out("do_flee", 1220);
}

void do_flee()
{
		message_vision("$N不屈魂化作一丝青烟而去。\n",this_object());
	destruct(this_object());
}
void die()
{
	int a,b,c,i;
	mapping yours,my;
	object ob,*tar;
	  object gift;
	ob=this_object();
	tar = ob->query_enemy();
	b=50000+random(30000);
	a=500;
	c=20000+random(5000);
	for(i=0;i<sizeof(tar);i++)
	{
		if(tar[i])
		{
		tar[i]->add("yuanbao",a);
		tar[i]->add("potential",b);
		tar[i]->add("combat_exp",c);
	tell_object(tar[i],HIC"你杀死"+name()+"，"HIY"获得了"HIG+b+HIY"点潜能，"HIC+a+HIY"点灵石，"HIR+c+HIY"点修为！"NOR"\n");	
		}
	}
	::die();
}
