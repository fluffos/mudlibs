// sz,obj:yinzhen.c                
// 97.10.1  by Aug

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
	set_name(HIW"银针"NOR, ({ "yinzhen" , "yin zhen", "zhen"  }) );
	set_weight(200);

	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "枚");
		set("long",
HIW"这是一枚三寸长的银针，细而柔韧，多为医家刺穴疗伤之用。
能运用这种银针的医者多为旷世神医，并有深厚的内功。
你可以试着用它来针灸疗伤(zhenjiu)(heal)。\n"NOR);
		set("value", 100);		
		set("yingdu", 50);
		set("base_unit", "枚");
		set("base_weight", 10);
		set("base_value", 1000);
		set("no_drop",1);
		set("no_give",1);
		set("no_sell",1);
		set("no_get",1);
		set("material","crimsonsteel");
		set("wield_msg", HIW"$N从皮囊中拿出一根$n"+HIW"捏在手里。\n"NOR);
		set("unwield_msg", HIW"$N将手中的$n"+HIW"放回皮囊。\n"NOR);
	}
	set_amount(1);
	init_throwing(30);
	setup();
}

void init()
{
	add_action("do_heal","zhenjiu");
 	add_action("do_heal","heal"); 
}

int do_heal(string arg)
{
	object me,ob;
	int damage,heals,i;
	string msg,s;

	me=this_player();
	if( living(me) ==0 ) return 0;

	if( ! this_object()->query("equipped"))
		return notify_fail("你银针都没拿出来，怎么施行针灸术啊?\n");

      if( me->query_skill("miaoshouhuichun", 1)<1 )
		return notify_fail("你连妙手回春中最基本的功夫都没学会，就想使用针灸术啊?\n");

	if( !arg || !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("你想对谁施行针灸术？\n");
	
//这一段是为了防止 妙手回春 成为超级 perform
	if(!userp(ob))
	{
		if( me->query_skill("miaoshouhuichun", 1)<60 )
		{
			message_vision(
"$N想给$n疗伤，但$n看了看$N颤抖的手，脸上露出害怕的神色。
$n不想让$N给他刺穴疗伤。\n",me,ob);
			return 1;
		}
	}
	else
	{
		if( ob!=me && ob->query("env/agree_heal")!=1 )		
		{
			message_vision(YEL"$N想给$n施行针灸疗伤。\n"NOR,me,ob);
			tell_object(me,YEL"因为"+ob->name()+"是玩家控制的人物，请等待对方的答复。\n"NOR);
			tell_object(ob,
YEL"如果你同意的话，请设置环境参数agree_heal为1(set agree_heal 1)；
如不同意就不要设置这个参数，或把这个参数设置成任意不为一的数。\n"NOR);
			
			return 1;
		}
	}			

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() || ob->is_fighting() )
		return notify_fail("战斗中还想疗伤，你找死啊？\n");

// 5% 以下不疗，防止pl 无修止的用robot 练功
	if( (ob->query("max_kee")*10/ob->query("eff_kee")) > 200 )
		return notify_fail(ob->name()+"受的伤太重了，现在就施行针灸太危险了！\n");	

	if(ob->query("max_kee") == ob->query("eff_kee"))
	{
		if(me!=ob)
			return notify_fail("你要治的这个人，并没有伤啊！\n");
		else
			message_vision("$N决定用自己来做试验，来提高自己妙手回春的水平。\n",me);
	}

	if( me->query("force") < 50 )
		return notify_fail("你的内力不足，无法使用妙手回春术！\n");
	if( me->query("gin") < 30 )
		return notify_fail("你的精不足，无法集中精力！\n");

	me->add("force",-50);
	me->add("gin",-30);               
	me->improve_skill("miaoshouhuichun", random(me->query_int())/2);
	tell_object(me,"在实践中你的妙手回春水平上升了。\n");

	if(me==ob) s="$N"; else s="$n";

	msg= CYN"$N手捏银针，小心翼翼地向"+s+"的穴道刺去，\n"NOR;

	if( random(60)>(int)me->query_skill("miaoshouhuichun",1))
	{
		damage=random(ob->query("max_kee")/2);
		
		i=ob->query("max_kee")*10/damage;

		if(i>100)
			msg+= CYN"可是$N用力稍偏，没有正好刺中穴道，"+s+"脸上露出一丝难过的神情。"NOR;
		else
		{
			if(i>40)
				msg+= HIR"但是$N用力过猛，竟然刺出了血，这可是针灸中的大忌！"NOR;
			else
				msg+= RED"$N刺了下去才发现刺错了穴道，"+s+"「哇」的喷出了一口鲜血，看来有生命危险！！！"NOR;
		}

		ob->receive_wound("kee",damage);				
		
		damage=i;
	}
	else
	{
		msg+= CYN"$N的银针准确无误的刺入穴道，随着银针的缓缓转动，"+s+"长长的出了一口气，脸色好看多了。"NOR;

		damage=-1;

		heals= me->query_skill("miaoshouhuichun", 1)+ random(me->query_skill("miaoshouhuichun", 1)) ;
		if((ob->query("eff_kee")+heals) > ob->query("max_kee"))
			ob->set("eff_kee",ob->query("max_kee"));
		else
			ob->add("eff_kee",heals);
	}

	msg+= "\n";
	
	if(me==ob)
		message_vision(msg,me);
	else
		message_vision(msg,me,ob);

	if(damage>0)
	{
		if(ob->query("kee")<0)
		{
			ob->set("eff_kee",1);
			ob->set("kee",1);

			if( userp(ob) )
			{
				if(me==ob)					
					message_vision("好险啊！$N差一点把自己扎死。\n",me);
				else
					message_vision("好险啊！$N差一点把$n扎死。\n", me,ob);
			}
		}
		else
		{
			if (me!=ob)
			{
				if(random(damage)<40)
				{
					message_vision("$N「啊」大叫一声，怒道：你想杀我啊！\n",ob);

					ob->kill_ob(me);
					me->fight_ob(ob);
				}
				else
				{
					message_vision("$N「啊」大叫一声：好痛啊！下次你可千万当心点！\n",ob);
				}
			}
		}
		
	}

	return 1;
}


