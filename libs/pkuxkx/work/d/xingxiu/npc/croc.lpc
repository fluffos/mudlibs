// zine aug 26 2010
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"鳄鱼"NOR,({"e yu","e","croc"}));
	set("race","野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs",({"bite"}));
	set("age",random(500));
	set("combat_exp",30000);
	set("long","这是一只土黄色的鳄鱼。\n");
	set("max_qi",4000);
	set("max_jing",4000);
	set("max_neili",1);
	set("neili",1);
	set("jiali",1);
	set("eff_jingli",40000);
	set("jingli",40000);
	set("str",10);
	set("con",10);
	set("dex",20);
	set("chat_chance", 10);
    set("chat_msg", ({
		"鳄鱼流下了几滴眼泪。\n",
		"鳄鱼懒洋洋的看着你，就像看着一块晚餐一样。\n",
	}));
	set_temp("apply/attack",10);
	set_temp("apply/damage",20);
	set_temp("apply/armor",40);
	setup();

    carry_object("/d/xingxiu/obj/eyd");
	
}

void init()
{
	object ob = this_player();
	
	if(userp(ob))
		{
			
			remove_call_out("killob");
       		call_out("killob", 3, ob);
       	}
}

int killob(object ob)
{
    if (present(ob,environment(this_object())))
    {
        kill_ob(ob);
    }
}

void die()
{
	object ob=this_object(),me;
	if(!objectp(me = get_damage_origin_object()))
	{
		message_vision("$N沉入了湖底，再也找不到了。\n",ob);
		destruct(ob);
		return;
	}
	if (!me->query_temp("xx_croc"))
		me->set_temp("xx_croc",1);
	else
	{
		message_vision("$N沉入了湖底，再也找不到了。\n",ob);
		destruct(ob);
		return;
	}
	::die();
}