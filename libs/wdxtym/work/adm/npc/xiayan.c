// killer.c
// by doing

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW"瞎子"NOR"", ({ "xiazi", "xiazi" }) );
	set("gender", "男性" );
	set("age", 20 + random(20));

	set("long",
		"不要惹他。\n"
	);

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
    set("max_qi", 200000);
	set("eff_qi", 200000);
	set("qi", 200000);
	set("max_neili", 200000);
	set("neili", 200000);
	set("max_jing", 200000);
	set("eff_jing", 200000);
	set("jing", 200000);
	set("combat_exp", 200000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"瞎子骂道：你奶奶的，敢和我斗？不知道死字怎么写是么？\n",
		"瞎子喝道：快把宝物交出来，我饶了你这条小命！\n",
		"瞎子呵呵大笑：你遇到了老子我，那算是倒霉了！\n"
	}) );

	set_skill("blade", 480);
	set_skill("dodge", 480);
	set_skill("unarmed", 480);
	set_skill("parry", 480);
	set_skill("wuhu-duanmendao", 480);
	set_skill("feiyan-zoubi", 480);

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");

	set_temp("apply/damage", 2115);
	set_temp("apply/attack", 1150);
	set_temp("apply/unarmed_damage", 3000);//空手伤害
	set_temp("apply/defense", 1050);

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	call_out("do_flee", 1800);
}

void do_flee()
{
		object ob;
		object a=this_object();
		ob=new("/d/city/wlcw/npc/fulao");
        if(a->is_fighting())
			return 0;
	if (objectp(present(ob, environment(a))))
			return 0;
		message_vision("$N东张西望的看了一会儿，拔腿溜走了。\n",this_object());
	destruct(this_object());
}
/*
void init()
{
	object ob;

	::init();

	ob = this_player();
	remove_call_out("kill_ob");
      call_out("kill_ob", 1, ob); 
}*/
void die()
{
	mapping yours,my,a,b;
	object ob,*tar;
	  object gift;
	ob=this_object();
	tar = ob->query_enemy();
 if (sizeof(tar)==1)
		{
       tar[0]->add("jifeng",100);
	   tar[0]->add("combat_exp",5000);
	   tar[0]->add("potential",20000);
	tell_object(tar[0],HIC"你杀死"+name()+"，"HIY"获得了100消费点券！5000点修为，20000点潜能"NOR"\n");
		}
	CHANNEL_D->do_channel(this_object(), "chat", HIR"江湖竟然有如此高手！"NOR"");
	::die();
}
