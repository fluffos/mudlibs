//liuer-mihou.c weiqi...98/05/13

#include <ansi.h>
#define MAX_TRY 20
inherit NPC;
#include "/d/migong/romnpc2.c"
string ask_me();

void create()
{
	set_name("六耳猕猴", ({"liuer mihou", "liuer", "mihou"}));
	set("title", "灵通子");
	set("gender", "男性" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
	set("long", "六耳猕猴早年拜在镇元大仙门下，学得一身好本领。\n后来他自觉跟镇元大仙差不多了，便开始不安分起来，\n居然去果园偷吃人参果，结果是果子没吃着反而被镇元大仙逮住，\n痛加斥责后逐出了门墙。\n");
	set("class", "xian");
	set("combat_exp", 38500000);
	set("attitude", "peaceful");
	//create_family("五庄观", 2, "弟子");
	set("rank_info/respect", "猴爷");


	set("max_qi", 200000);
	set("max_jing", 200000);
	set("neili", 200000);
	set("max_neili", 200000);
	set("neili", 200000);
	set("max_mana", 200000);	
	set("force_factor", 50);




	set("inquiry", ([
		"name": "齐天大圣孙悟空是也。\n",
		"here": "。。。\n",
		"人参果": "猴爷我最喜欢的就是人参果。\n",
		"杀人": "杀人？只要你有人参果，什么都好商量。\n",
		"秘诀": "秘诀？只要你有人参果，什么都好商量。\n",
		"猕猴手记": "手记？只要你有人参果，什么都好商量。\n",
                "包裹"     : (: ask_me :),
                 "真假"     : (: ask_me :),
	]) );

	setup();
initlvl((600+random(600)),24);	
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}


string ask_me()
{
	this_player()->set_temp("liuer-mihou_ask","done");
	call_out("autokill",1,this_player(),this_object());
	return "嘿嘿";
}

void autokill (object me, object who)
{
  message_vision ("$n大喝一声要杀死$N！\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N大怒：哪个泼贼子冒充你家猴爷！\n",this_player());

  set_temp("my_killer",ob);
  this_player()->kill_ob(me);
}

void unconcious()
{
  die ();
}





void die()
{
  object me = this_object();
  object ob = query_temp("my_killer");
    object guan = new (__DIR__"pusa");
  object xiangjiao;
  message_vision(HIY "\n观音突然从彩云间现身。\n" NOR,me);
  message_vision(HIY "\n观音对$N一点手，你这猴头！\n" NOR,me);
  message_vision(HIY "$N哎呀一声，现了真身。\n\n" NOR,me);
  if ((ob) && (ob->query_temp("liuer-mihou_ask") == "done"))
  {
  	ob->set_temp("obstacle/liuer-mihou/liuer-mihou_killed",1);
	message_vision(HIC "观音说道：这厮我带走，你安心取经去吧! \n\n" NOR,me);
	
  guan->announce_success (ob);
  destruct (guan); 
  }
  ob->set_temp("liuer-mihou_ask","no");
        ::die();
}
