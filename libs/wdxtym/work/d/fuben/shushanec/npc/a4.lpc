// tufei.c

inherit NPC;
//#include <fb_skill.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name(MAG"灵"NOR, ({ "lingv", "lingv" }) );
	set("gender", "男性");
	set("age", 30);
	set("twtnpc",1);
	set("long", "为道可以舍弃一切的护派者。\n");
	set("attitude",  "peaceful");
	set("int", 30);
		set("str", 25);
		set("con", 25);
		set("dex", 25);
	set_basic();
	setup();
}
void init(object me)
{
	object ob;
	mapping skills;
	string *sk;
	int j, jiali, i, lvl;
	
	me = this_player();
	ob = this_object();
	::init();
	
	if (userp(me)) {
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 1);
		if (!random(3))
			ob->do_clone(me, 1);
		
		lvl = 450;//设置所有技能120级
		
		set("int", 30);
		set("str", 25);
		set("con", 25);
		set("dex", 25);
		set("qi", 10000);
		set("eff_qi", 10000);
		set("max_qi", 10000);
		set("jing", 10000);
		set("eff_jing", 10000);
		set("max_jing", 10000);
		set("neili", 10000);
		set("eff_neili", 10000);
		set("max_neili", 10000);
		set("combat_exp", 500000);
		
		skills = ob->query_skills();
		if (mapp(skills))
		{
			sk = keys(skills);
			j = sizeof(sk);
			for (i = 0; i < j; i++)
				skills[sk[i]] = lvl;
		}
		jiali = ob->query_skill("force", 1) / 5;
		if (jiali > 100) jiali = 100;
		ob->set("jiali", jiali);
	}
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
		if(tar[0]->query("shushanec")>0)
		{
	   tar[0]->add("experience",30);	
	   tar[0]->add("potential",1000);
	tell_object(tar[0],HIC"你杀死"+name()+"，"HIY"获得了30点实战体会，1000点潜能"NOR"\n");
		}
		}else if(sizeof(tar)==2)
		{
		if(tar[0]->query("shushanec")>0)
		{
		tar[0]->add("experience",30);	
	   tar[0]->add("potential",1000);
	tell_object(tar[0],HIC"你杀死"+name()+"，"HIY"获得了30点实战体会，1000点潜能"NOR"\n");
		}
		if(tar[1]->query("shushanec")>0)
		{
		tar[1]->add("experience",30);	
	   tar[1]->add("potential",1000);
	tell_object(tar[1],HIC"你杀死"+name()+"，"HIY"获得了30点实战体会，1000点潜能"NOR"\n");
		}
		}else if(sizeof(tar)==3)
		{
		if(tar[0]->query("shushanec")>0)
		{
		tar[0]->add("experience",30);	
	   tar[0]->add("potential",1000);
	tell_object(tar[0],HIC"你杀死"+name()+"，"HIY"获得了30点实战体会，1000点潜能"NOR"\n");
		}
		if(tar[1]->query("shushanec")>0)
		{	
	tar[1]->add("experience",30);
	   tar[1]->add("potential",1000);
	tell_object(tar[1],HIC"你杀死"+name()+"，"HIY"获得了30点实战体会，1000点潜能"NOR"\n");
		}
		if(tar[2]->query("shushanec")>0)
		{	
	tar[2]->add("experience",30);
	   tar[2]->add("potential",1000);
	tell_object(tar[2],HIC"你杀死"+name()+"，"HIY"获得了30点实战体会，1000点潜能"NOR"\n");
		}
		}
	::die();
}