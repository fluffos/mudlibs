//laowangfei.c -- 汝阳王府老王妃
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

int hold_player();

void create()
{
  set_name("汝阳王妃", ({ "wang fei", "wangfei", "fei", "lao" }));
  set("long", 
  					"她是汝阳王的原配妻子，原先也是蒙古草原上知名的美人。\n"
  					"但现在人老珠黄，不常得王爷宠信。\n");
	
	set("gender", "女性");
	set("age", 46);
	set("attitude", "peaceful");
		
	set("shen_type", 1);
	set("shen", 10000);
  set("attitude", "peaceful");
  
	set("str", 20);
	set("int", 15);
	set("con", 20);
	set("dex", 15);
	set("per", 22);
	
  set("combat_exp", 5000000);
  		set_skill("unarmed",200);
      set_skill("force", 200);
      set_skill("parry", 200);
      set_skill("dodge", 200);
      set_temp("apply/attack", 200);
      set_temp("apply/defense", 200);
			set_temp("apply/damage",  200);      

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
				(: hold_player() :),
        }) );


	setup();
	
	carry_object(__DIR__"obj/ring-red")->wear();
	carry_object(__DIR__"obj/zhijin-tuanshan")->wear();
	carry_object(__DIR__"obj/gugu-guan")->wear();
}

int accept_fight(object me)
{
	remove_call_out("hold_player");
	call_out("hold_player", 0);

	return 1;
}

int accept_kill(object ob)
{
	remove_call_out("hold_player");
	call_out("hold_player", 0);

	return 1;
}

int hold_player()
{
	object me = this_object();
	object target = me->select_opponent();

	if ( !me->is_fighting() ) 
	{
  	if ( me->query("eff_qi") < me->query("max_qi") )
    	exert_function("heal");

    return 1;
  }
	else
	{
		command("say "HIY"来人啊，给我拿下了！"NOR"");
		message_vision("\n$N身后突然出现四名番僧，不由分说，一顿乱棍向$N打来……\n", target);
		target->unconcious();
		command("halt");
	
		target->move("/d/ruyang-wangfu/shuilao");
	}
	return 1;
}
