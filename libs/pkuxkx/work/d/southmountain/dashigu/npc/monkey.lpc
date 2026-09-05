// 拦路猴子
// zine 2014/7
inherit NPC;
void create()
{
        set_name("猴子", ({ "hou zi", "hou","monkey" }) );
         set("race", "野兽");
        set("age", 4);
        set("long", "一只拦路的野猴子。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体","上肢","下肢","尾巴" }) );
        set("verbs", ({ "bite","claw" }) );

        set("combat_exp", 10000);
        set("max_qi",300);
        set("qi",300);
		set("dashigu_houzi",1);
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void die()
{
    object killer,ob;
	if(killer=get_damage_origin_object())//无伤害来源
	{
		killer->set("tianmuQuests/dashigu/monkey","kill");
	}
	::die();
}

int accept_object(object me, object ob)
{
	if (ob->query("dashigu_tao"))
	{
		message_vision("$N接过$n递来的桃，兴奋的抓耳挠腮。\n",this_object(),me);
		me->set("tianmuQuests/dashigu/monkey","tao");
		ob->move(VOID_OB);
		destruct(ob);
		return 1;
	}
	return notify_fail(this_object()->query("name")+"不想要你的"+ob->query("name")+"。\n");
}


