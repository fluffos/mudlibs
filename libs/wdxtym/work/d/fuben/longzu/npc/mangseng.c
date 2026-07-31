// killer.c
// by doing
inherit NPC;
#include <ansi.h>
#include "/d/fuben/longzu/npc/fb_skill.h"





void create()
{
	set_name(HIW"盲僧"NOR"", ({ "mangseng", "mangseng" }) );
	set("gender", "男性" );
	set("age", 20 + random(20));

	set("long",
		"不要惹他。\n"
	);

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	 set("lvl",100);//设置任务人物成长值
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

	

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	set_temp("apply/damage", 215);
	 set("sequence",5);
	set_temp("apply/attack", 150);
	
	
	set_temp("apply/defense", 150);

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	call_out("do_flee", 1800);
	set_basic();
	setup();
}
int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence)
{
object me = this_object()->query_last_damage_from();
 

    newob->set("qi", ob->query("lvl")*50);
	newob->set("max_qi",ob->query("max_qi")*2);
	newob->set("eff_qi",ob->query("max_qi")*2 );
	newob->set("jing", ob->query("max_jing")*2);
	newob->set("max_jing", ob->query("max_jing")*2);
	newob->set("neili", ob->query("max_neili")*2);
	newob->set("max_neili", ob->query("max_neili")*2);
	newob->set("sequence",newsequence);
	
	 newob->set("name",manmsg[3]);
	 newob->set("title",manmsg[2]);
	newob->set("lvl",ob->query("lvl")+120);
	newob->set_temp("apply/jiali", ob->query("lvl"));
	newob->set_temp("apply/attack", ob->query("lvl"));
	newob->set_temp("apply/defense", ob->query("lvl"));
	newob->set_temp("apply/damage", ob->query("lvl")*3/2);
	newob->set_temp("apply/unarmed_damage", ob->query("lvl")*3/2);
	return 1;
}
int distribute_skill(object ob,int skill_level)
{
int ran,size,i;
string *skills;
	ran = random(sizeof(skill_map));
	size = sizeof(skill_map[ran]);
	skills = keys(skill_map[ran]);

	for(i = 0; i < size; i++)
	{
		if (!skill_map[ran][skills[i]])
		{
			ob->set_skill(skills[i], skill_level);
		}
		else
		{
			ob->set_skill(skills[i], skill_level);
			ob->set_skill(skill_map[ran][skills[i]], skill_level);
			ob->map_skill(skill_map[ran][skills[i]], skills[i]);
		}
	}
	return 1;
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

void die()
{
	mapping yours,my,a,b;
	object ob,*tar;
	  object gift;
	ob=this_object();
	tar = ob->query_enemy();
 if (sizeof(tar)==1)
		{
       tar[0]->add("jifeng",50);
	   tar[0]->add("combat_exp",5000);
	   tar[0]->add("potential",40000);
	tell_object(tar[0],HIC"你杀死"+name()+"，"HIY"获得了50消费点券！5000点修为，40000点潜能"NOR"\n");
		}
	CHANNEL_D->do_channel(this_object(), "chat", HIR"江湖竟然有如此高手！"NOR"");
	::die();
}
