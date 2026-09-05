// 药铺老板
// created by Zine 5 Sep 2010
inherit NPC;
#include <ansi.h>
#include <condition.h>

string *cant_list=({"drunk","unchblk","wannianzui"});
int do_cure(string arg);

void create()
{
	set_name("孙思邈", ({ "sun simiao","sun"}) );
	set("title", HIM"药王"NOR);
	set("gender", "男性" );
	set("long", "孙思邈行医治病60年，被人尊称为“药王”。\n");
  set("age", 80);
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
	set("max_jing", 200);
	set("eff_jingli", 200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", 100);
  set("combat_exp", 1000000);
  set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
  set("inquiry", ([
    "问诊" : "对新手实行长期义诊！老玩家请不要浪费宝贵资源。\n",
    "疗伤" : (: do_cure,"injure" :),
    "治病" : (: do_cure,"disease" :),
    "疗毒" : (: do_cure,"poison" :)
       	]) );
	setup();
	carry_object("/d/jinyang/obj/heibuxie")->wear();
  carry_object("/d/jinyang/obj/jycloth")->wear();
}

int do_cure(string arg)
{
	object me=this_player(), ob=this_object();
	string cond;
	
	if ( ( me->query("age")>=24 ||
		     me->query_combatgrade()>=60 ) &&
		   !wizardp(me) )
	{
		message_vision("$N说道：本人只对年龄在24周岁以下的并且功力在一甲子以下的新手提供服务。\n", ob);
		return 1;
	}
	
	if ( time()-me->query_temp("sun_cure")<60 )
	{
		message_vision("$N说道：你刚治疗完，先等等吧。\n", ob);
		return 1;
	}
	
	if ( ob->is_busy() )
	{
		tell_object(me , "你发现药铺里面挤满了人，还是在后面排会队吧。\n");
		return 1;
	}
	
	foreach( cond in keys(cond_def) )
	{
		if ( cond_def[cond]["type"]!=arg )
			continue;
		
		if ( member_array(cond, cant_list)>=0 )
			continue;
		
		if ( me->query_condition(cond)>0 )
		{
			ob->start_busy(10);
			me->start_busy(10);
			me->apply_condition(cond,0);
		}
	}
	
	if ( me->query("eff_qi") < me->query("max_qi") )
	{
	  ob->start_busy(10);
		me->start_busy(10);
		me->set("eff_qi",me->query("max_qi"));
	}

  if ( me->query("eff_jing") < me->query("max_jing") )
  {
  	ob->start_busy(10);
		me->start_busy(10);
		me->set("eff_jing",me->query("max_jing"));
	}
	
	if ( ob->is_busy() )
	{
		message_vision(CYN"$N拿出银针在$n的穴道上进行针灸。\n"NOR, ob, me);
		me->set_temp("sun_cure", time());
	  call_out("end_cure",10, me);
	}
	else
	{
		message_vision(CYN"$N瞅了瞅$n，说道：没病没疼的来消遣老夫啊？\n"NOR, ob, me);
		me->set_temp("sun_cure", time());
	}
	return 1;
}

void end_cure(object me)
{
	tell_object(me, CYN"孙思邈轻轻地在你的穴道上针灸了几下，你发现自己舒服了不少。\n"NOR);
	me->start_busy(0);
	this_object()->start_busy(0);
}