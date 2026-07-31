// sz,obj:yinzhen.c                
// 97.10.1  by Aug

#include <weapon.h>
inherit THROWING;

void create()
#include <ansi.h>

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
//set("value", 100);		
		set("yingdu", 50);
		set("base_unit", "枚");
		set("base_weight", 10);
		set("base_value", 1000);
                set_temp("yinzhen", 20);
		set("no_put",1);
		set("no_drop",1);
		set("no_give",1);
		set("no_sell",1);
		set("no_steal",1);
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
	int damage,heals,i,exp,pot,score;
	string msg,s;

	me=this_player();
	if( living(me) ==0 ) return 0;

	if( ! this_object()->query("equipped"))
		return notify_fail("你银针都没拿出来，怎么施行针灸术啊?\n");

      if( me->query_skill("miaoshouhuichun", 1)<1 )
		return notify_fail("你连妙手回春中最基本的功夫都没学会，就想使用针灸术啊?\n");

	if( !arg || !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("你想对谁施行针灸术？\n");
	
       if ( me->query_temp("yinzhen") > 30)
           {
               message_vision("这根银针由于过度的使用，已经坏了\n", this_object(), me);
	destruct(this_object());
//	           destruct(yinzhen);
                   return 1;
           }


//这一段是为了防止 妙手回春 成为超级 perform
	if(!userp(ob))
	{
                if( me->query_skill("miaoshouhuichun", 1)<30 )
		{
			message_vision(
"$N想给$n疗伤，但$n看了看$N颤抖的手，脸上露出害怕的神色。
$n不想让$N给他刺穴疗伤。\n",me,ob);
			return 1;
		}
	}
	else
	{
		if( userp(me) && ob!=me && ob->query("env/agree_heal")!=1 )		
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
if (!ob)
		return notify_fail("战斗中还想疗伤，你找死啊？\n");
if (!me)
		return notify_fail("战斗中还想疗伤，你找死啊？\n");

// 5% 以下不疗，防止pl 无修止的用robot 练功
        if( userp(me) && ob->query("max_qi")< 10 || ob->query("eff_qi") < 10 )
                return notify_fail(ob->name()+"受的伤太重了，现在就施行针灸太危险了！\n"); 

        if( userp(me) && ob->query("max_qi")< 30 || ob->query("eff_qi") < 30 )
                return notify_fail(ob->name()+"受的伤太重了，现在就施行针灸太危险了！\n"); 


        if( userp(me) && (ob->query("max_qi")*10/ob->query("eff_qi")) > 200 )
                return notify_fail(ob->name()+"受的伤太重了，现在就施行针灸太危险了！\n"); 

        if(ob->query("max_qi") == ob->query("eff_qi"))
	{
		if(me!=ob)
			return notify_fail("你要治的这个人，并没有伤啊！\n");
		else
			return notify_fail("你自己并没有伤啊！\n");
	}

        if( me->query("neili") < 50 )
		return notify_fail("你的内力不足，无法使用妙手回春术！\n");
        if( me->query("jing") < 30 )
		return notify_fail("你的精不足，无法集中精力！\n");

//        if(me==ob) return notify_fail("你不能向自己用银针，手够不着啊！\n");

        me->add("neili",-50);
        me->add("jing",-30);               
	me->improve_skill("miaoshouhuichun", random(me->query_int())/2);
	tell_object(me,"在实践中你的妙手回春水平上升了。\n");
             exp =1+random(20);
             pot = exp/7;
             score = random(2)+1;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
             me->add_temp("yinzhen", 1);
     	      tell_object(me,"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点综合评价\n");

//      if(me==ob) return notify_fail("你不能向自己用银针，手够不着啊！\n");

	if(me==ob) s="$N"; else s="$n";

	msg= CYN"$N手捏银针，小心翼翼地向"+s+"的穴道刺去，\n"NOR;

	if( random(60)>(int)me->query_skill("miaoshouhuichun",1))
	{
                damage=random(ob->query("max_qi")/2);
		
                i=ob->query("max_qi")*10/damage;

		if(i>100)
			msg+= CYN"可是$N用力稍偏，没有正好刺中穴道，"+s+"脸上露出一丝难过的神情。"NOR;
		else
		{
			if(i>40)
				msg+= HIR"但是$N用力过猛，竟然刺出了血，这可是针灸中的大忌！"NOR;
			else
				msg+= RED"$N刺了下去才发现刺错了穴道，"+s+"「哇」的喷出了一口鲜血，看来有生命危险！！！"NOR;
		}

                ob->receive_wound("qi",damage);                         
		
		damage=i;
	}
	else
	{
		msg+= CYN"$N的银针准确无误的刺入穴道，随着银针的缓缓转动，"+s+"长长的出了一口气，脸色好看多了。"NOR;

		damage=-1;

        if (ob->apply_condition("snake_poison")>1)
        {          ob->clear_condition("snake_poison");}
        if (ob->apply_condition("wugong_poison")>1)
        {          ob->clear_condition("wugong_poison");}
        if (ob->apply_condition("zhizhu_poison")>1)
        {          ob->clear_condition("zhizhu_poison");}
        if (ob->apply_condition("xiezi_poison")>1)
        {          ob->clear_condition("xiezi_poison");}
        if (ob->apply_condition("chanchu_poison")>1)
        {          ob->clear_condition("chanchu_poison");}
		heals= me->query_skill("miaoshouhuichun", 1)+ random(me->query_skill("miaoshouhuichun", 1)) ;
                if((ob->query("eff_qi")+heals) > ob->query("max_qi"))
                        ob->set("eff_qi",ob->query("max_qi"));
		else
                        ob->add("eff_qi",heals);

		if((ob->query("eff_jing")+heals) > ob->query("max_jing"))
			ob->set("eff_jing",ob->query("max_jing"));
		else
			ob->add("eff_jing",heals);

        }

	msg+= "\n";
	
	if(me==ob)
		message_vision(msg,me);
	else
		message_vision(msg,me,ob);

	if(damage>0)
	{
                if(ob->query("qi")<0)
		{
                        ob->set("eff_qi",1);
                        ob->set("qi",1);

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


