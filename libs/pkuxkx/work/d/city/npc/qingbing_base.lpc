// 清军模板

#include <ansi.h>
inherit NPC;
int copy(object ob);

string *title = ({
	"正黄旗", "正白旗", "正蓝旗", "正红旗", "镶黄旗", "镶白旗", "镶蓝旗", "镶红旗",
});

string * surname=({"瓜尔佳","钮钴禄","舒穆禄","纳兰","董鄂","马佳","富察","萨克达",});
string * givenname=({"明珠","索尔图","玄烨","弘历","福临","济尔哈朗","胤祯","旻宁","永琰",});
	

void die()
{
	object pl=find_player(this_object()->query("target"));
	pl->add_temp("skf/credit",1);
	tell_room(environment(),query("title")+query("name")+"嘿嘿奸笑两声，翻身上马，远远离去。\n");
	if(this_object())
	destruct(this_object());
}

void dest()
{
	object ob = this_object();
	if (environment(ob)) 
	tell_room(environment(ob),query("title")+query("name")+"匆匆忙忙地离开了。\n");
	destruct(ob);
	return;
}

int kill2()
{
	object refugee;
	if (environment())
	{
		refugee=query("target_refugee");
		if (present(refugee,environment()))
		{
			message_vision(HIR+query("title")+"$N纵马跑了出来，开始对$n下手了！\n"NOR,this_object(),refugee);
			copy(refugee);
			kill_ob(refugee);
			refugee->kill_ob(this_object());
		}
	}
	return 1;
}
int copy(object me)
{
	object ob=this_object();
	int exp,lv,qi;
	if (me->query("max_qi")>=20000)
	qi=20000;
	else
	qi=me->query("max_qi");
	exp = me->query("combat_exp");
	if ( exp < 500000 )
	exp=500000;
	lv = to_int(pow(exp/100,0.333)*10);
	ob->set("max_qi", qi);
    ob->set("eff_qi", qi);
	ob->set("qi", qi);
	ob->set("max_jing", me->query("max_jing"));
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili"));
	ob->set("neili", ob->query("max_neili"));
	ob->set("combat_exp", exp);
	ob->set("max_jingli", me->query("max_jingli"));
	ob->set("jingli", ob->query("max_jingli"));
	if (ob->query("qingbing")==3)
	{
		ob->set("max_qi", qi*3/2);
		ob->set("eff_qi", qi*3/2);
		ob->set("qi", qi*3/2);
		ob->set("max_jing", me->query("max_jing")*3/2);
		ob->set("eff_jing", ob->query("max_jing"));
		ob->set("jing", ob->query("max_jing"));
		ob->set("max_neili", me->query("max_neili")*3/2);
		ob->set("neili", ob->query("max_neili"));
		ob->set("combat_exp", exp/10*11);
		ob->set_skill("dodge",lv*11/10);
		ob->set_skill("parry",lv*11/10);
		ob->set_skill("force",lv*11/10);
		ob->set_skill("claw",lv*11/10);
		ob->set_skill("longfeng-xiang",lv*11/10);
		ob->set_skill("bixue-xinfa",lv*11/10);
		ob->set_skill("kuihua-zhua",lv*11/10);
		ob->set_skill("kuangfeng-jian",lv*11/10);
		ob->set_skill("sword",lv*11/10);
		ob->map_skill("force", "bixue-xinfa");
		ob->map_skill("dodge", "longfeng-xiang");
		ob->map_skill("claw", "kuihua-zhua");
		ob->map_skill("parry", "kuihua-zhua");
		ob->map_skill("sword", "kuangfeng-jian");
		ob->prepare_skill("claw", "kuihua-zhua");
	}
	if (ob->query("qingbing")==1)
	{
		if (random(300)>149)
		{
			ob->set_skill("dodge",lv*3/4);
			ob->set_skill("parry",lv*3/4);
			ob->set_skill("force",lv*3/4);
			ob->set_skill("strike",lv*3/4);
			ob->set_skill("longfeng-xiang",lv*3/4);
			ob->set_skill("bixue-xinfa",lv*3/4);
			ob->set_skill("juehu-zhang",lv*3/4);
			ob->map_skill("force", "bixue-xinfa");
			ob->map_skill("dodge", "longfeng-xiang");
			ob->map_skill("strike", "juehu-zhang");
			ob->map_skill("parry", "juehu-zhang");
			ob->prepare_skill("strike", "juehu-zhang");
		}
		else 
		{
			ob->set_skill("dodge",lv*3/4);
			ob->set_skill("parry",lv*3/4);
			ob->set_skill("force",lv*3/4);
			ob->set_skill("claw",lv*3/4);
			ob->set_skill("longfeng-xiang",lv*3/4);
			ob->set_skill("bixue-xinfa",lv*3/4);
			ob->set_skill("kuihua-zhua",lv*3/4);
			ob->map_skill("force", "bixue-xinfa");
			ob->map_skill("dodge", "longfeng-xiang");
			ob->map_skill("claw", "kuihua-zhua");
			ob->map_skill("parry", "kuihua-zhua");
			ob->prepare_skill("claw", "kuihua-zhua");
		}
	}
	if (ob->query("qingbing")==2)
	{
		if (random(300)>149)
		{
			ob->set_skill("dodge",lv*8/10);
			ob->set_skill("parry",lv*8/10);
			ob->set_skill("force",lv*8/10);
			ob->set_skill("strike",lv*8/10);
			ob->set_skill("longfeng-xiang",lv*8/10);
			ob->set_skill("bixue-xinfa",lv*8/10);
			ob->set_skill("juehu-zhang",lv*8/10);
			ob->set_skill("fenglei-dao",lv*8/10);
			ob->set_skill("blade",lv*8/10);
			ob->map_skill("force", "bixue-xinfa");
			ob->map_skill("dodge", "longfeng-xiang");
			ob->map_skill("strike", "juehu-zhang");
			ob->map_skill("parry", "juehu-zhang");
			ob->map_skill("blade", "fenglei-dao");
			ob->prepare_skill("strike", "juehu-zhang");
		}
		else 
		{
			ob->set_skill("dodge",lv*8/10);
			ob->set_skill("parry",lv*8/10);
			ob->set_skill("force",lv*8/10);
			ob->set_skill("claw",lv*8/10);
			ob->set_skill("longfeng-xiang",lv*8/10);
			ob->set_skill("bixue-xinfa",lv*8/10);
			ob->set_skill("kuihua-zhua",lv*8/10);
			ob->set_skill("kuangfeng-dao",lv*8/10);
			ob->set_skill("blade",lv*8/10);
			ob->map_skill("force", "bixue-xinfa");
			ob->map_skill("dodge", "longfeng-xiang");
			ob->map_skill("claw", "kuihua-zhua");
			ob->map_skill("parry", "kuihua-zhua");
			ob->map_skill("blade", "kuangfeng-dao");
			ob->prepare_skill("claw", "kuihua-zhua");
		}
	}
}
