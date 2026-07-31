// killer.c
// by doing

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"不屈魂"NOR"", ({ "buqu", "buqu" }) );
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
    set("max_qi", 3000);
	set("eff_qi", 3000);
	set("qi", 3000);
	set("max_neili", 3000);
	set("neili", 3000);
	set("max_jing", 3000);
	set("eff_jing", 3000);
	set("jing", 3000);
	set("combat_exp", 15000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"不屈魂幽幽道：守护万剑阁楼，是我们一生的使命！\n",
		"不屈魂低叹道：逃的逃，死的死，万剑阁楼已经不复当年风光\n",
	}) );

	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("wuhu-duanmendao", 80);
	set_skill("feiyan-zoubi", 80);

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");

	set_temp("apply/damage", 25);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);

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
	int b,i;
	mapping yours,my,a;
	object ob,*tar;
	  object gift;
	ob=this_object();
	tar = ob->query_enemy();
	b=200+random(500);
	for(i=0;i<sizeof(tar);i++)
	{
		if(tar[i]){
		tar[i]->add("potential",b);
	tell_object(tar[i],HIC"你杀死"+name()+"，"HIY"获得了"+b+"点潜能！"NOR"\n");
		}
	}
    ::die();
}
